//
// Created by Hakan Sulun on 19.08.2020.
//

#include <algorithm>
#include "world.h"


World::World(sf::RenderTarget &window, float x, float y, float width, float height) :
        m_target(window),
        m_position(x, y),
        m_size(width, height) {}

void World::spawnColony(float x, float y, uint32_t colonySize, sf::Color colonyColor, const std::string &colonyName) {
    if (std::find_if(m_colonies.begin(), m_colonies.end(), [&](const Colony &c) { return c.name() == colonyName; }) == m_colonies.end()) {
        Colony colony(*this, x, y, colonySize, colonyColor, colonyName);
        m_colonies.emplace_back(colony);
    }
}

void World::update(const float dt) {
    for (auto &colony : m_colonies) {
        colony.update(dt);
    }
}

void World::render() {

    sf::RenderStates states;

    m_shape.setPosition(m_position);
    m_shape.setSize(m_size);
    m_shape.setFillColor(sf::Color(10, 92, 32));

    m_target.draw(m_shape);
    for (auto &colony : m_colonies) {
        colony.render(m_target, states);
    }
}

const sf::Vector2f &World::position() const {
    return m_position;
}

const sf::Vector2f &World::size() const {
    return m_size;
}