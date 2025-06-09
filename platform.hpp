#pragma once
#include "Realm.hpp"
#include <SFML/Graphics.hpp>

class Platform
{
protected:
    sf::RectangleShape shape;
    sf::Texture LightTexture;
    sf::Texture DarkTexture;
    Realm currentRealm;

public:
    Platform(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
    virtual ~Platform() = default;

    virtual void update(float deltaTime) {}
    virtual void draw(sf::RenderWindow &window);
    virtual bool isActive() const { return true; }
    virtual void setRealm(Realm realm);
    virtual void drawGhost(sf::RenderWindow &window)
    {
        sf::RectangleShape ghost = shape;
        ghost.setFillColor(sf::Color(100, 100, 100, 100)); // gray with alpha
        window.draw(ghost);
    }

    sf::FloatRect getBounds() const;
    const sf::Vector2f &getPosition() const;
    const sf::Vector2f &getSize() const;
};