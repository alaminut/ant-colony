//
// Created by Hakan Sulun on 19.08.2020.
//

#include "world.h"

World::World(sf::RenderTarget &window, float width, float height) : World::World(window, 0, 0, width, height) {}

World::World(sf::RenderTarget &window, float x, float y, float width, float height) :
        m_target(window),
        m_position(x, y),
        m_size(width, height) {}

void World::add_colony(Colony &colony) {
    if (std::find(m_colonies.begin(), m_colonies.end(), &colony) == m_colonies.end()) {
        m_colonies.emplace_back(&colony);
    }
}

void World::update(const float dt) {
    for (Colony *const colony : m_colonies) {
        colony->update(dt);
    }
}

void World::render() {
    m_shape.setPosition(m_position);
    m_shape.setSize(m_size);
    m_shape.setFillColor(sf::Color(10, 92, 32));

    m_target.draw(m_shape);
    for (Colony *const colony : m_colonies) {
        colony->render(m_target);
    }
}

const sf::Vector2f &World::position() const {
    return m_position;
}

const sf::Vector2f &World::size() const {
    return m_size;
}