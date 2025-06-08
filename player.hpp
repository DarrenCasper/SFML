#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "platform.hpp"

class Player {
public:
    Player();

    void handleInput();
    void applyPhysics(float gravity);
    void checkCollision(const std::vector<Platform*>& platforms);
    void update(float deltaTime); 
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    bool isJumping;
    float jumpSpeed;

    
    int currentFrame;
    float frameTime;
    float timeSinceLastFrame;
    int frameWidth;
    int frameHeight;
};
