#include "DisappearPlatform.hpp"

DisappearPlatform::DisappearPlatform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, float disappearTime, float reappearTime)
    : Platform(size, position, color), active(true), disappearTime(disappearTime), reappearTime(reappearTime), timer(0.f)
{
    shape.setFillColor(color);
}

void DisappearPlatform::update(float deltaTime) {
    timer += deltaTime;
    if (active) {
        if (timer >= disappearTime) {
            active = false;
            timer = 0.f;
        }
    } else {
        if (timer >= reappearTime) {
            active = true;
            timer = 0.f;
        }
    }
}

bool DisappearPlatform::isActive() const {
    return active;
}