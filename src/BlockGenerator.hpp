#ifndef BLOCK_GENERATOR_HPP
#define BLOCK_GENERATOR_HPP

#include "Block.hpp"
#include <vector>

class BlockGenerator {
    public:
        std::vector<Block> GeneratePlatform(int platform_lenght, float x_position, float y_spacing);

};

#endif