#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Entity.hpp"

#define BLOCK_WIDHT 70.f
#define BLOCK_HEIGHT 33.f

class Block : public Entity {
    public:
        Block();
    
    private:
        const char* blockTexturePath = "Media/Textures/Block.png";

};

#endif