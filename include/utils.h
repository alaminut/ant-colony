//
// Created by Hakan Sulun on 18.08.2020.
//

#ifndef GAME_DEMO_UTILS_H
#define GAME_DEMO_UTILS_H

#include <SFML/Graphics.hpp>
#include <random>
#include <cmath>

const float PI = 3.14;

inline sf::Vector2f to_world_coordinates(const sf::Vector2f &world_coords, float x, float y) {
    return sf::Vector2f(world_coords.x + x, world_coords.y + y);
}

template<typename T>
inline float getLength(const sf::Vector2<T> &vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

#endif //GAME_DEMO_UTILS_H
