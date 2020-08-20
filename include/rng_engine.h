//
// Created by Hakan Sulun on 19.08.2020.
//

#ifndef GAME_DEMO_RNG_ENGINE_H
#define GAME_DEMO_RNG_ENGINE_H

#include <random>

struct RNGEngine {
    static float getRandRange(float base) {
        std::mt19937 gen(rd());
        std::uniform_real_distribution dist(-base, base);
        return dist(gen);
    }

    static float getRandUnder(float lim) {
        std::mt19937 gen(rd());
        std::uniform_real_distribution dist(0.f, lim);
        return dist(gen);
    }

private:
    inline static std::random_device rd;
};

#endif //GAME_DEMO_RNG_ENGINE_H
