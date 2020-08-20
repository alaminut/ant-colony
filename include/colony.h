//
// Created by Hakan Sulun on 18.08.2020.
//

#ifndef GAME_DEMO_COLONY_H
#define GAME_DEMO_COLONY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "ant.h"

struct World;

struct Colony {
    friend struct World;

    Colony(World &world, float x, float y, uint32_t size, sf::Color color, const std::string &name);

    void spawn_ant();

    [[nodiscard]]
    const sf::Vector2f &position() const {
        return m_position;
    }

    [[nodiscard]]
    const std::string &name() const {
        return m_name;
    }

    const float Radius = 20;

private:
    void update(float dt);

    void render(sf::RenderTarget &target, sf::RenderStates &renderStates);

    World &m_world;
    sf::VertexArray m_ants_va;
    std::vector<Ant> m_ants;

    //TODO: Ant texture daha sonra texture manager ile yönetilecek
    sf::Texture m_antTexture;

    const sf::Color m_color;
    const std::string &m_name;
    const sf::Vector2f m_position;
};

#endif //GAME_DEMO_COLONY_H
