//
// Created by Hakan Sulun on 19.08.2020.
//

#ifndef GAME_DEMO_RNG_ENGINE_H
#define GAME_DEMO_RNG_ENGINE_H

#include <random>

struct RNGEngine {
    static float getRandRange(float base);

    static float getRandUnder(float lim);

private:
    static std::random_device rd;
};

#endif //GAME_DEMO_RNG_ENGINE_H
