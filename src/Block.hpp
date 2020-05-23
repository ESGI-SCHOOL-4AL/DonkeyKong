#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Block : public Entity {
    public:
        Block();
        Block(float x_position, float y_position); 
        ~Block();
    
    private:
        static const std::string BLOCK_TEXTURE_PATH; 

};

#endif