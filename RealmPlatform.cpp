#include "RealmPlatform.hpp"

RealmPlatform::RealmPlatform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color &color , Realm realm) 
    : Platform(size, position, color), activeRealm(realm) , currentRealm(Realm::Light){}

void RealmPlatform::setRealm(Realm realm) {
    currentRealm = realm;
    if (currentRealm == Realm::Light) {
        shape.setTexture(&LightTexture);
    } else {
        shape.setTexture(&DarkTexture);
    }
}

bool RealmPlatform::isActive() const {
    return currentRealm == activeRealm;
}