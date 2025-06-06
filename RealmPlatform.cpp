#include "RealmPlatform.hpp"

RealmPlatform::RealmPlatform(const sf::Vector2f& size, const sf::Vector2f& position, Realm realm) 
    : Platform(size, position, (realm == Realm::Light ? sf::Color::Cyan : sf::Color::Magenta)), activeRealm(realm) , currentRealm(Realm::Light){}

void RealmPlatform::setRealm(Realm realm) {
    currentRealm = realm;
}

bool RealmPlatform::isActive() const {
    return currentRealm == activeRealm;
}