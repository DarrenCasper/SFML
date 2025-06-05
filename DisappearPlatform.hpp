#pragma once
#include "platform.hpp"

class DisappearPlatform : public Platform {
    bool active;
    float disappearTime;
    float timer;
    float reappearTime;

    public:
    DisappearPlatform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, float disappearTime, float reappearTime);


    void update(float deltaTime) override;
    bool isActive() const override;
};