#include "../include/carousel.hpp"

namespace sjsu::science{
    carousel::carousel(hal::v5::strong_ptr<hal::actuator::rc_servo> p_servo) : m_servo(p_servo){
    }  
    void carousel::home(){
        degrees = 0;
        (*m_servo).position(degrees);
    }
    void carousel::step_move(){
        degrees+=20;
        (*m_servo).position(degrees);
    }
    void carousel::step_move(int turns){
        degrees=degrees+20*turns;
        (*m_servo).position(degrees);
    }
    void carousel::step_backward(){
        degrees-=20;
        (*m_servo).position(degrees);
    }
    void carousel::step_backward(int turns){
        degrees=degrees-20*turns;
        (*m_servo).position(degrees);
    }   
}