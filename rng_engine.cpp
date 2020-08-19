//
// Created by Hakan Sulun on 19.08.2020.
//

#include "rng_engine.h"

float RNGEngine::getRandRange(float base) {
    std::mt19937 gen(RNGEngine::rd());
    std::uniform_real_distribution dist(-base, base);
    return dist(gen);
}

float RNGEngine::getRandUnder(float lim) {
    std::mt19937 gen(RNGEngine::rd());
    std::uniform_real_distribution dist(0.f, lim);
    return dist(gen);
}

std::random_device RNGEngine::rd;
