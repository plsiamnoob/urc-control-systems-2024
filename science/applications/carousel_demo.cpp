#include <libhal-armcortex/dwt_counter.hpp>
#include <libhal-armcortex/startup.hpp>
#include <libhal-armcortex/system_control.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>
#include <libhal/units.hpp>
#include <libhal-actuator/rc_servo.hpp>

#include "../resource_list.hpp"
#include "../include/carousel.hpp"

using namespace hal::literals;
using namespace std::chrono_literals;

namespace sjsu::science {
    void application(){
        
        auto clock = resources::clock();
        auto terminal = resources::console();

        try{
            auto carousel_servo_ptr = resources::carousel_servo();
            int turn = 0;
            hal::print(*terminal, "Hello, Program Started\n");
            hal::delay(*clock, 100ms); 
            carousel carousel_servo(carousel_servo_ptr);
            carousel_servo.home();
            hal::print(*terminal, "Moved Servo to Start\n");
            while(true){
                hal::print<128>(*terminal, "Moved Servo to %d turns\n", turn);
                hal::delay(*clock, 1000ms);
                carousel_servo.step_move(turn);
                hal::print(*terminal, "Moved Servo one turn\n");
                hal::delay(*clock, 100ms);
                turn+=1;
                hal::print(*terminal, "Success!\n");
                hal::delay(*clock, 100ms);
            }
        }catch(hal::exception const& e ){
            hal::print<128>(*terminal, "error code: %d\n", e.error_code());
        }catch(std::exception const& e ){
            hal::print<128>(*terminal, "error code: %s\n", e.what());
        }
    }
        
}
