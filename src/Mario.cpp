#include "Mario.hpp"

const std::string Mario::MARIO_TEXTURE_PATH = "Media/Textures/Mario_small_transparent.png";

Mario::Mario() : Entity(MARIO_TEXTURE_PATH) {
    drawable_ = true;
}

Mario::Mario(float x_position, float y_position) : Entity(MARIO_TEXTURE_PATH, x_position, y_position) {
    drawable_ = true;
}

Mario::~Mario() { }