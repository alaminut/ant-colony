//
// Created by Hakan Sulun on 19.08.2020.
//

#include "ant.h"
#include "config.h"
#include "rng_engine.h"

Ant::Ant(World &world, Colony &colony, float x, float y, float angle, uint32_t id_) :
        m_world(world),
        m_colony(colony),
        m_position(x, y),
        m_direction(angle),
        m_id(id_),
        m_action(Action::SEARCHING_FOOD) {}

void Ant::update(const float dt) {
    updatePosition(dt);

    last_direction_update += dt;
    if (last_direction_update > direction_update_period) {
        m_direction += RNGEngine::getRandRange(direction_noise_range);
        last_direction_update = 0.f;
    }

    //TODO: Action durumuna göre world üzerinde marker ara.

    //TODO: Yemek aranmayan durumda colony ile collide işlemini hesapla.

    if (getLength(m_position - m_colony.position) < m_colony.size) {
        if (m_action == Action::TO_COLONY) {
            printf("Ant reached to home, moving back to food.");
            m_action = Action::SEARCHING_FOOD;
            m_direction.moveNow(PI);
        }
    }

    m_direction.update(dt);
}

void Ant::updatePosition(const float dt) {
    const auto speed = m_action == Action::HALT ? 0 : move_speed;
    m_position += (dt * speed) * m_direction.getVector();

    const sf::Vector2f world_position = m_world.position();
    const sf::Vector2f world_size = m_world.size();

    m_position.x = m_position.x < world_position.x ? world_size.x : m_position.x;
    m_position.y = m_position.y < world_position.y ? world_size.y : m_position.y;

    m_position.x = m_position.x > world_size.x ? world_position.x : m_position.x;
    m_position.y = m_position.y > world_size.y ? world_position.y : m_position.y;
}

void Ant::render_in(sf::VertexArray &va, const uint32_t index) const {
    const sf::Vector2f dir = m_direction;
    const sf::Vector2f norm(-dir.y, dir.x);

    va[index + 0].color = ANT_COLOR;
    va[index + 1].color = ANT_COLOR;
    va[index + 2].color = ANT_COLOR;
    va[index + 3].color = ANT_COLOR;

    va[index + 0].position = m_position - width * norm + length * dir;
    va[index + 1].position = m_position + width * norm + length * dir;
    va[index + 2].position = m_position + width * norm - length * dir;
    va[index + 3].position = m_position - width * norm - length * dir;

    va[index + 0].texCoords = TextureCoords[0];
    va[index + 1].texCoords = TextureCoords[1];
    va[index + 2].texCoords = TextureCoords[2];
    va[index + 3].texCoords = TextureCoords[3];
}

void Ant::setAction(const Action action) {
    m_action = action;
}

const sf::Vector2f &Ant::getPosition() const {
    return m_position;
}

std::vector<sf::Vector2f> Ant::TextureCoords{sf::Vector2f(0.0f, 0.0f),
                                             sf::Vector2f(73.0f, 0.0f),
                                             sf::Vector2f(73.0f, 107.0f),
                                             sf::Vector2f(0.0f, 107.0f)};