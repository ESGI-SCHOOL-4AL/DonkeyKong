#include "LevelGenerator.hpp"

LevelGenerator::LevelGenerator() { }

std::vector<std::shared_ptr<Entity>> LevelGenerator::GenerateLevel() {
    std::vector<std::shared_ptr<Entity>> entities_ptr;
    std::vector<Entity> entities;

    for(int i = 1; i <= PLATFORM_NUMBER; i++) {
        std::vector<Block> current_platform;
        current_platform = GeneratePlatform(SPACING_FROM_WINDOW, SPACING_BETWEEN_PLATFORM * i);
        entities.insert(entities.end(), current_platform.begin(), current_platform.end());
    }

    std::vector<Ladder> ladders = GenerateLadders(SPACING_FROM_WINDOW, SPACING_BETWEEN_PLATFORM);
    entities.insert(entities.end(), ladders.begin(), ladders.end());

    Mario mario = Mario();
    float mario_y_size = mario.GetSize().y;
    mario.SetPosition(100.f + 70.f, SPACING_BETWEEN_PLATFORM * 5 - mario_y_size);
    entities.push_back(mario);

    for(Entity entity : entities) {
        std::shared_ptr<Entity> entity_ptr = std::make_shared<Entity>();
        *entity_ptr = entity;
        entities_ptr.push_back(entity_ptr);
    }

    return entities_ptr;
}

std::vector<Block> LevelGenerator::GeneratePlatform(float x_position, float y_position) {
    std::vector<Block> platform;

    for(int i = 1; i <= BLOCK_NUMBER; i++) {
        Block current_block = Block();
        float x_size = current_block.GetSize().x;

        current_block.SetPosition(x_position + x_size * i, y_position);
        
        platform.push_back(current_block);
    }

    return platform;
}

std::vector<Ladder> LevelGenerator::GenerateLadders(float x_position, float y_position) {
    std::vector<Ladder> ladders;
    Block block = Block();
    float x_size = block.GetSize().x;
    float y_size = block.GetSize().y;

    for(int i = 1; i <= LADDER_NUMBER; i++) {
        ladders.push_back(Ladder(x_position + x_size * i, y_size + y_position * i));
    }

    return ladders;
}

LevelGenerator::~LevelGenerator() { }
