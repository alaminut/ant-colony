//
// Created by Hakan on 8/20/2020.
//

#include <stdexcept>
#include <exception>
#include "game_manager.h"
#include "world.h"

const uint8_t GameManager::WorldLimit = 2;

GameManager::GameManager(sf::RenderTarget &renderTarget, sf::RenderStates &renderStates) :
        m_renderTarget(renderTarget),
        m_renderState(renderStates) {}

void GameManager::createWorld(float width, float height, float x, float y) noexcept(false) {
    if (m_worlds.size() == WorldLimit)
        throw std::exception("You've reached the world size limit.");

    m_worlds.emplace_back(m_renderTarget, x, y, width, height);
}

void GameManager::spawnColony(size_t worldId, float x, float y, const uint32_t colonySize, const sf::Color colonyColor, const std::string &colonyName) {
    if (worldId > WorldLimit) {
        throw std::out_of_range("World id is out of range.");
    }

    World &world = m_worlds[worldId];
    world.spawnColony(x, y, colonySize, colonyColor, colonyName);
}

void GameManager::update(const float dt) {
    for (auto &world : m_worlds) {
        world.update(dt);
    }
}

void GameManager::render() {
    for (auto &world : m_worlds) {
        world.render();
    }
}
