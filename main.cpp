#include <SFML/Graphics.hpp>
#include <vector>
#include "player.hpp"
#include "platform.hpp"
#include "DisappearPlatform.hpp"

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
    const float gravity = 0.5f;

    // Create platforms
    std::vector<Platform *> platforms;

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
        player.applyPhysics(gravity);
        player.checkCollision(platforms);

        // Update all platforms
        for (auto &plat : platforms)
            plat->update(deltaTime);

        window.clear(sf::Color::Black);
        player.draw(window);

        for (auto &plat : platforms)
            if (plat->isActive())
                plat->draw(window);
        window.display();
    }

    return 0;
}
