#ifndef LADDER_HPP
#define LADDER_HPP

#include "Entity.hpp"

#define LADDER_WIDTH 30.f
#define LADDER_HEIGHT 70.f

class Ladder : Entity {
    public:
        Ladder();
        GenerateLadder(foat x_position, float y_position);
    public:
        const char* ladderTexturePath = "Media/Textures/Echelle.png";
};

#endif