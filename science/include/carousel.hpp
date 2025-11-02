#pragma once
#include <libhal-actuator/rc_servo.hpp>
#include <libhal/pointers.hpp>
#include <libhal/units.hpp>

namespace sjsu::science{
    class carousel{
        public:
            carousel(hal::v5::strong_ptr<hal::actuator::rc_servo> p_servo);
            void home();
            void step_move();
            void step_move(int turns);
            void step_backward();
            void step_backward(int turns);
        private:
            hal::v5::strong_ptr<hal::actuator::rc_servo> m_servo;
            hal::degrees degrees;
    };
}