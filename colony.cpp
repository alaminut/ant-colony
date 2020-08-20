//
// Created by Hakan Sulun on 19.08.2020.
//

#include "colony.h"
#include "rng_engine.h"
#include "utils.h"
#include "world.h"

Colony::Colony(World &world, float x, float y, uint32_t size, const sf::Color color, const std::string &name) :
        m_world(world),
        m_position(to_world_coordinates(world.position(), x + Colony::Radius, y + Colony::Radius)),
        m_ants_va(sf::Quads, 4 * size),
        m_color(color),
        m_name(name) {

    m_antTexture.loadFromFile("assets/ant_2.png");

    for (auto i = size; i--;) {
        m_ants.emplace_back(m_world, *this, m_position.x, m_position.y, RNGEngine::getRandRange(2.0f * PI), i, m_antTexture);
    }
}

void Colony::spawn_ant() {
    m_ants.emplace_back(m_world, *this, m_position.x, m_position.y, RNGEngine::getRandRange(2.f * PI), m_ants.size() + 1, m_antTexture);
    m_ants_va.resize(m_ants_va.getVertexCount() + 4);
}

void Colony::update(const float dt) {
    for (Ant &ant : m_ants) {
        ant.update(dt);
    }
}

void Colony::render(sf::RenderTarget &target, sf::RenderStates &renderStates) {
    uint32_t index = 0;
    for (const Ant &ant : m_ants) {
        ant.render_in(m_ants_va, 4 * (index++), renderStates);
    }

    renderStates.texture = &m_antTexture;
    target.draw(m_ants_va, renderStates);

    sf::CircleShape colony(Radius);
    colony.setOrigin(Radius, Radius);
    colony.setPosition(m_position);
    colony.setFillColor(m_color);
    target.draw(colony, renderStates);
}
