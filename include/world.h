//
// Created by Hakan Sulun on 19.08.2020.
//

#ifndef GAME_DEMO_WORLD_H
#define GAME_DEMO_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "colony.h"

struct Colony;

struct World {
    World(sf::RenderTarget &window, float width, float height);

    World(sf::RenderTarget &window, float x, float y, float width, float height);

    void add_colony(Colony &colony);

    void update(float dt);

    void render();

    const sf::Vector2f &position() const;

    const sf::Vector2f &size() const;

private:
    sf::RenderTarget &m_target;
    std::vector<Colony *> m_colonies;
    sf::Vector2f m_size;
    sf::Vector2f m_position;
    sf::RectangleShape m_shape;
};

#endif //GAME_DEMO_WORLD_H
