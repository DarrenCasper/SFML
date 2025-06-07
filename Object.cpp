#include "Object.hpp"

Object::Object(const std::string &imagePath, const sf::Vector2f &startPos)
    : position(startPos)
{
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Object::update(float deltaTime) {
    
}

void Object::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
