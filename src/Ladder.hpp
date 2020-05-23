#ifndef LADDER_HPP
#define LADDER_HPP

#include <string>

#include "Entity.hpp"

class Ladder : public Entity {
    public:
        Ladder();
        Ladder(float x_position, float y_position); 
        ~Ladder();
    
    private:
        static const std::string LADDER_TEXTURE_PATH; 
};

#endif