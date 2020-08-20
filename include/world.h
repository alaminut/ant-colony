//
// Created by Hakan Sulun on 19.08.2020.
//

#ifndef GAME_DEMO_WORLD_H
#define GAME_DEMO_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "colony.h"

struct World {
    friend class GameManager;

    World(sf::RenderTarget &window, float x, float y, float width, float height);

    const sf::Vector2f &position() const;

    const sf::Vector2f &size() const;

private:
    void update(float dt);

    void render();

    void spawnColony(float x, float y, uint32_t colonySize, sf::Color colonyColor, const std::string &colonyName);

    sf::RenderTarget &m_target;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    std::vector<Colony> m_colonies;
    sf::RectangleShape m_shape;
};

#endif //GAME_DEMO_WORLD_H
