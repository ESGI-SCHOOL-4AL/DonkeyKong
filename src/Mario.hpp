#ifndef MARIO_HPP
#define MARIO_HPP

#include <string>

#include "Entity.hpp"

class Mario : public Entity {
    public:
        Mario();
        Mario(float x_position, float y_position); 
        ~Mario();
    
    private:
        static const std::string MARIO_TEXTURE_PATH; 
};

#endif