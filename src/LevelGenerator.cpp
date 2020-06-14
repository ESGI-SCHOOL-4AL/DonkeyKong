#include "LevelGenerator.hpp"

LevelGenerator::LevelGenerator() {}

std::vector<std::shared_ptr<Entity>> LevelGenerator::GenerateLevel(std::shared_ptr<EventManager> event_manager)
{
    std::vector<std::shared_ptr<Entity>> entities_ptr;

    std::vector<Ladder> ladders = GenerateLadders(SPACING_FROM_WINDOW, SPACING_BETWEEN_PLATFORM);
    for (auto l : ladders)
    {
        entities_ptr.push_back(std::make_shared<Ladder>(l));
    }

    for (int i = 1; i <= PLATFORM_NUMBER; i++)
    {
        std::vector<Block> current_platform;
        current_platform = GeneratePlatform(SPACING_FROM_WINDOW, SPACING_BETWEEN_PLATFORM * i);
        for (auto p : current_platform)
        {
            entities_ptr.push_back(std::make_shared<Block>(p));
        }
    }

    Mario mario = Mario();
    float mario_y_size = mario.GetSize().y;
    mario.SetPosition(100.f + 70.f, SPACING_BETWEEN_PLATFORM * 5 - mario_y_size);
    auto shared = std::make_shared<Mario>(mario);
    event_manager->RegisterControllableEntity(shared);
    entities_ptr.push_back(shared);

    return entities_ptr;
}

std::vector<Block> LevelGenerator::GeneratePlatform(float x_position, float y_position)
{
    std::vector<Block> platform;

    for (int i = 1; i <= BLOCK_NUMBER; i++)
    {
        Block current_block = Block();
        float x_size = current_block.GetSize().x;

        current_block.SetPosition(x_position + x_size * i, y_position);

        platform.push_back(current_block);
    }

    return platform;
}

std::vector<Ladder> LevelGenerator::GenerateLadders(float x_position, float y_position)
{
    std::vector<Ladder> ladders;
    Block block = Block();
    float x_size = block.GetSize().x;

    for (int i = 1; i <= LADDER_NUMBER; i++)
    {
        ladders.push_back(Ladder(x_position + x_size * i, 1 + y_position * i));
    }

    return ladders;
}

LevelGenerator::~LevelGenerator() {}
