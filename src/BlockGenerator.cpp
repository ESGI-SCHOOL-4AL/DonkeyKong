#include "BlockGenerator.hpp"

std::vector<Block> BlockGenerator::GeneratePlatform(int platform_lenght, float x_position, float y_spacing) {
    std::vector<Block> platform = std::vector<Block>();
    
    for (int i = 1; i <= platform_lenght; i++) {
        Block current_block = Block();
        current_block.position_.x = x_position + current_block.size_.x * i;
        current_block.position_.x = y_spacing;
        current_block.sprite_.setPosition(current_block.position_);
        
        platform.push_back(Block());
    }

    return platform;
}