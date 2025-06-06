#include <SFML/Graphics.hpp>
#include <vector>
#include "player.hpp"
#include "platform.hpp"
#include "DisappearPlatform.hpp"
#include "Realm.hpp"
#include "RealmPlatform.hpp"

const float ASPECT_RATIO = 16.f / 9.f;

void updateView(sf::RenderWindow &window, sf::View &view)
{
    float width = static_cast<float>(window.getSize().x);
    float height = static_cast<float>(window.getSize().y);

    float windowRatio = width / height;
    float viewWidth = 1.f;
    float viewHeight = 1.f;
    float viewportX = 0.f;
    float viewportY = 0.f;

    if (windowRatio > ASPECT_RATIO)
    {
        viewWidth = ASPECT_RATIO / windowRatio;
        viewportX = (1.f - viewWidth) / 2.f;
    }
    else if (windowRatio < ASPECT_RATIO)
    {
        viewHeight = windowRatio / ASPECT_RATIO;
        viewportY = (1.f - viewHeight) / 2.f;
    }

    view.setViewport(sf::FloatRect(viewportX, viewportY, viewWidth, viewHeight));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Echo's Realm");
    sf::Clock clock;
    window.setFramerateLimit(60);

    Player player;
    bool rKeyPrev = false;
    const float gravity = 0.5f;

    // Create platforms
    std::vector<Platform *> platforms;

    // Realm platforms
    Realm currentRealm = Realm::Light;

    sf::RectangleShape platform1(sf::Vector2f(200.f, 20.f));
    platform1.setFillColor(sf::Color::Blue);
    platform1.setPosition(300.f, 700.f);
    platforms.push_back(new Platform(platform1.getSize(), platform1.getPosition(), platform1.getFillColor()));

    sf::RectangleShape platform2(sf::Vector2f(200.f, 20.f));
    platform2.setFillColor(sf::Color::Red);
    platform2.setPosition(720.f, 620.f);
    platforms.push_back(new DisappearPlatform(platform2.getSize(), platform2.getPosition(), platform2.getFillColor(), 2.f, 3.f));

    sf::RectangleShape ground(sf::Vector2f(3000.f, 50.f));
    ground.setFillColor(sf::Color::Yellow);
    ground.setPosition(0.f, 850.f);
    platforms.push_back(new Platform(ground.getSize(), ground.getPosition(), ground.getFillColor()));

    sf::RectangleShape realmPlat(sf::Vector2f(200.f, 20.f));
    realmPlat.setPosition(1000.f, 500.f);
    platforms.push_back(new RealmPlatform(realmPlat.getSize(), realmPlat.getPosition(), Realm::Light));

    sf::RectangleShape realmPlat1(sf::Vector2f(200.f, 20.f));
    realmPlat1.setPosition(1300.f, 500.f);
    platforms.push_back(new RealmPlatform(realmPlat1.getSize(), realmPlat1.getPosition(), Realm::Dark));

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput();
        bool rKeyNow = sf::Keyboard::isKeyPressed(sf::Keyboard::R);
        if (rKeyNow && !rKeyPrev)
        {
            currentRealm = (currentRealm == Realm::Light) ? Realm::Dark : Realm::Light;
        }
        rKeyPrev = rKeyNow;
        player.applyPhysics(gravity);
        player.checkCollision(platforms);

        sf::Vector2f pos = player.getPosition();
        float playerWidth = player.getBounds().width;

        if (pos.x + playerWidth < 0)
        {
            // Left edge → teleport to right
            player.setPosition(1600, pos.y);
        }
        else if (pos.x > 1600)
        {
            // Right edge → teleport to left
            player.setPosition(-playerWidth, pos.y);
        }
        // Update all platforms
        for (auto &plat : platforms)
            plat->update(deltaTime);
        for (auto &plat : platforms)
            plat->setRealm(currentRealm);

        sf::Color bgColor = (currentRealm == Realm::Light) ? sf::Color(200, 220, 255) : sf::Color(30, 30, 50);
        window.clear(bgColor);
        player.draw(window);

        for (auto &plat : platforms)

            if (plat->isActive())
                plat->draw(window);
            else
            {
                RealmPlatform *realmPlat = dynamic_cast<RealmPlatform *>(plat);
                if (realmPlat)
                {
                    plat->drawGhost(window);
                }
            }

        window.display();
    }

    return 0;
}
