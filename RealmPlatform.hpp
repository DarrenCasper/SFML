#pragma once
#include "platform.hpp"
#include "Realm.hpp"

class RealmPlatform : public Platform{
    Realm activeRealm;

    public:
    RealmPlatform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color &color, Realm realm);

    void setRealm(Realm realm);
    bool isActive() const override;

    private:
    Realm currentRealm;
};