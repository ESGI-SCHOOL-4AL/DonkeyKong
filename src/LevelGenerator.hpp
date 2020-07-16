#ifndef LEVEL_GENERATOR_HPP
#define LEVEL_GENERATOR_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Block.hpp"
#include "Ladder.hpp"
#include "Mario.hpp"
#include "EventManager.hpp"
#include "InstanceOfHelper.hpp"

#define SPACING_FROM_WINDOW 100.f
#define SPACING_BETWEEN_PLATFORM 110.f

#define BLOCK_NUMBER 8
#define PLATFORM_NUMBER 5
#define LADDER_NUMBER 4

class LevelGenerator
{
public:
    LevelGenerator();
    ~LevelGenerator();
    std::vector<std::shared_ptr<Entity>> GenerateLevel(std::shared_ptr<EventManager> event_manager);
    std::vector<Block> GeneratePlatform(float x_position, float y_position);
    std::vector<Ladder> GenerateLadders(float x_position, float y_position);
    Mario GenerateMario(float x_position, float y_position);
};

#endif