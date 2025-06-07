#include "Cloud.hpp"

Cloud::Cloud(const std::string &imagePath, const sf::Vector2f &startPos, float spd)
    : Object(imagePath, startPos), speed(spd) {}

void Cloud::update(float deltaTime) {
    sf::Vector2f pos = sprite.getPosition();
    pos.x += speed * deltaTime;

    if (pos.x > 1800.f)
        pos.x = -sprite.getGlobalBounds().width;

    sprite.setPosition(pos);
}
