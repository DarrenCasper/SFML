#pragma once
#include "Object.hpp"

class Cloud : public Object {
private:
    float speed;

public:
    Cloud(const std::string &imagePath, const sf::Vector2f &startPos, float speed);
    void update(float deltaTime) override;
};
