#include "platform.hpp"

Platform::Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);
    LightTexture.loadFromFile("img/LightGround.jpg");
    DarkTexture.loadFromFile("img/DarkGround.jpg");

    shape.setTexture(&LightTexture); // Default texture
}

void Platform::setRealm(Realm realm) {
    currentRealm = realm;
    if (currentRealm == Realm::Light) {
        shape.setTexture(&LightTexture);
    } else {
        shape.setTexture(&DarkTexture);
    }
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
