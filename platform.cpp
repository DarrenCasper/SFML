#include "platform.hpp"

Platform::Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Platform::getBounds() const {
    return shape.getGlobalBounds();
}

const sf::Vector2f& Platform::getPosition() const {
    return shape.getPosition();
}   

const sf::Vector2f& Platform::getSize() const {
    return shape.getSize();
}
