#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player {
public:
    Player();

    void handleInput();
    void applyPhysics(float gravity);
    void checkCollision(const std::vector<sf::RectangleShape>& platforms);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool isJumping;
    float jumpSpeed;
};
