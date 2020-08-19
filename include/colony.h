//
// Created by Hakan Sulun on 18.08.2020.
//

#ifndef GAME_DEMO_COLONY_H
#define GAME_DEMO_COLONY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "ant.h"
#include "world.h"

struct Ant;
struct World;

struct Colony {
    Colony(World &world, float x, float y, uint32_t size, sf::Color color, std::string name);

    void spawn_ant();

    void update(float dt);

    void render(sf::RenderTarget &target);

private:
    World &m_world;
    sf::VertexArray m_ants_va;
    std::vector<Ant> m_ants;
    sf::Texture m_antTexture;

public:
    float size = 20;
    const sf::Color color;
    const std::string name;
    const sf::Vector2f position;
};

#endif //GAME_DEMO_COLONY_H
