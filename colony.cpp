//
// Created by Hakan Sulun on 19.08.2020.
//

#include "colony.h"
#include "rng_engine.h"

Colony::Colony(World &world, float x, float y, uint32_t size, sf::Color color, std::string name) :
        m_world(world),
        position(to_world_coordinates(world.position(), x + Colony::size, y + Colony::size)),
        m_ants_va(sf::Quads, 4 * size),
        color(color),
        name(std::move(name)) {

    // TODO: Ant kendi texture dosyasını yüklemeli.
    m_antTexture.loadFromFile("assets/ant_2.png");
    for (auto i = size; i--;) {
        m_ants.emplace_back(m_world, *this, position.x, position.y, RNGEngine::getRandRange(2.0f * PI), i);
    }

    world.add_colony(*this);
}

void Colony::spawn_ant() {
    m_ants.emplace_back(m_world, *this, position.x, position.y, RNGEngine::getRandRange(2.f * PI), m_ants.size() + 1);
    m_ants_va.resize(m_ants_va.getVertexCount() + 4);
}

void Colony::update(const float dt) {
    for (Ant &ant : m_ants) {
        ant.update(dt);
    }
}

void Colony::render(sf::RenderTarget &target) {
    uint32_t index = 0;
    for (const Ant &ant : m_ants) {
        ant.render_in(m_ants_va, 4 * (index++));
    }

    sf::RenderStates state;
    state.texture = &m_antTexture;
    target.draw(m_ants_va, state);

    sf::CircleShape colony(size);
    colony.setOrigin(size, size);
    colony.setPosition(position);
    colony.setFillColor(color);
    target.draw(colony, state);
}
