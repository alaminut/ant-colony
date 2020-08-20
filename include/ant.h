//
// Created by Hakan Sulun on 18.08.2020.
//

#ifndef GAME_DEMO_ANT_H
#define GAME_DEMO_ANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "direction.h"
#include "utils.h"

struct Direction;
struct Colony;
struct World;

struct Ant {
    friend struct Colony;

    enum class Action {
        SEARCHING_FOOD,
        TO_COLONY,
        HALT
    };

    Ant(World &world, Colony &colony, float x, float y, float angle, uint32_t id_, sf::Texture &texture);

    const sf::Vector2f &getPosition() const;

private:
    void update(float dt);

    void updatePosition(float dt);

    void render_in(sf::VertexArray &va, uint32_t index, sf::RenderStates &renderStates) const;

    void setAction(Action action);

    World &m_world;
    Colony &m_colony;
    sf::Vector2f m_position;
    Direction m_direction;
    uint32_t m_id;
    Action m_action;
    sf::Texture &m_texture;

    float last_direction_update = 0;

    const float width = 6.f; //2
    const float length = 18.f; //3.5
    const float move_speed = 50.f;
    const float marker_detection_max_dist = 40.0f;
    const float direction_update_period = 0.125f;
    const float marker_drop_period = 0.25f;
    const float max_reserve = 2000.0f;
    const float direction_noise_range = PI * 0.1f;

    static const std::vector<sf::Vector2f> TextureCoords;
};

#endif //GAME_DEMO_ANT_H
