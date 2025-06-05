#pragma once
#include <SFML/Graphics.hpp>

class Platform{
    protected:
    sf::RectangleShape shape;
    public:
    Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);
    virtual ~Platform() = default;

    virtual void update(float deltaTime) {}
    virtual void draw(sf::RenderWindow& window);
    virtual bool isActive() const { return true;}

    sf::FloatRect getBounds() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getSize() const;
};