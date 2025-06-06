#include "player.hpp"

Player::Player() {
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(50.f, 400.f);
    velocity = {0.f, 0.f};
    isJumping = false;
    jumpSpeed = -12.f;
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        shape.move(-5.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        shape.move(5.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        velocity.y = jumpSpeed;
        isJumping = true;
    }
}

void Player::applyPhysics(float gravity) {
    velocity.y += gravity;
    shape.move(0.f, velocity.y);
}

void Player::checkCollision(const std::vector<Platform*>& platforms) {
    for (const auto& plat : platforms) {
        if (shape.getGlobalBounds().intersects(plat->getBounds()) && plat->isActive()) {
            if (velocity.y > 0) { // falling
                shape.setPosition(shape.getPosition().x, plat->getPosition().y - shape.getSize().y);
                velocity.y = 0;
                isJumping = false;
            }
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}
