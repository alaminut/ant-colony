//
// Created by Hakan on 8/20/2020.
//

#ifndef GAME_DEMO_GAME_MANAGER_H
#define GAME_DEMO_GAME_MANAGER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "world.h"

//struct World;

class GameManager {
    sf::RenderTarget &m_renderTarget;
    sf::RenderStates &m_renderState;
    std::vector<World> m_worlds;

public:

    GameManager(sf::RenderTarget &renderTarget, sf::RenderStates &renderStates);

    void createWorld(float width, float height, float x = 0, float y = 0) noexcept(false);

    void spawnColony(size_t worldId, float x, float y, uint32_t colonySize, sf::Color colonyColor, const std::string &colonyName);

    void update(float dt);

    void render();

    GameManager(const GameManager &) = delete;

    GameManager &operator=(const GameManager &) = delete;

    GameManager(GameManager &&) = delete;

    GameManager &operator=(GameManager &&) = delete;

    static const uint8_t WorldLimit;
};


#endif //GAME_DEMO_GAME_MANAGER_H
