#include "Ladder.hpp"

const std::string Ladder::LADDER_TEXTURE_PATH = "Media/Textures/Echelle.png";

Ladder::Ladder() : Entity(LADDER_TEXTURE_PATH) { }

Ladder::Ladder(float x_position, float y_position) : Entity(LADDER_TEXTURE_PATH, x_position, y_position) {
    drawable_ = true;
}

Ladder::~Ladder() { }