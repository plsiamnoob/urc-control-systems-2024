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
    application(){
        auto clock = resources::clock();
        auto terminal = resources::console();
        auto carousel_servo_ptr = resources::carousel_servo();
        auto carousel_servo = carousel(carousel_servo_ptr);
        hal::print(*terminal, "Hello, Program Started");
        while(true){

        }
    }
}
