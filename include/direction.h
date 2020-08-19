//
// Created by Hakan Sulun on 18.08.2020.
//

#ifndef GAME_DEMO_DIRECTION_H
#define GAME_DEMO_DIRECTION_H

#include <cmath>

struct Direction {
public:
    Direction(float angle, float rotationSpeed = 10.f) :
            m_angle(angle),
            m_targetAngle(angle),
            m_rotationSpeed(rotationSpeed) {
        updateVec();
        m_target = m_vec;
    }

    void update(const float dt) {
        updateVec();

        const sf::Vector2f dir_norm(-m_vec.y, m_vec.x);
        const float dir_delta = dot(m_target, dir_norm);
        m_angle += m_rotationSpeed * dir_delta * dt;
    }

    void moveNow(float a) {
        this->operator+=(a);
        m_angle = m_targetAngle;
        updateVec();
    }

    sf::Vector2f getVector() const {
        return m_vec;
    }

    void operator +=(float a) {
        m_targetAngle += a;
        updateTarget();
    }

    void operator =(float a) {
        m_targetAngle = a;
        updateTarget();
    }

    operator sf::Vector2f() const {
        return m_vec;
    }

private:
    float m_angle;
    float m_targetAngle;
    float m_rotationSpeed;
    sf::Vector2f m_vec;
    sf::Vector2f m_target;

    void updateVec() {
        m_vec.x = cos(m_angle);
        m_vec.y = sin(m_angle);
    }

    void updateTarget() {
        m_target.x = cos(m_targetAngle);
        m_target.y = sin(m_targetAngle);
    }

    static float dot(const sf::Vector2f &v1, const sf::Vector2f &v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }
};

#endif //GAME_DEMO_DIRECTION_H
