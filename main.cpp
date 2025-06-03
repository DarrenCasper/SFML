#include <SFML/Graphics.hpp>
#include <vector>

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
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Platformer");
    window.setFramerateLimit(60);

    sf::View view(sf::FloatRect(0.f, 0.f, 1600.f, 900.f));
    updateView(window, view);

    // Initialize player
    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(50.f, 400.f);

    // Initialize platforms
    std::vector<sf::RectangleShape> platforms;

    sf::RectangleShape platform1(sf::Vector2f(200.f, 20.f));
    platform1.setFillColor(sf::Color::Blue);
    platform1.setPosition(300.f, 700.f);
    platforms.push_back(platform1);

    sf::RectangleShape platform2(sf::Vector2f(200.f, 20.f));
    platform2.setFillColor(sf::Color::Blue);
    platform2.setPosition(720.f, 620.f);
    platforms.push_back(platform2);

    sf::RectangleShape ground(sf::Vector2f(2000.f, 50.f));
    ground.setFillColor(sf::Color::Yellow);
    ground.setPosition(0.f, 850.f);
    platforms.push_back(ground);

    // Physics variables
    sf::Vector2f velocity(0.f, 0.f);
    float worldWidth = 1600.f;
    float gravity = 0.5f;
    float jumpSpeed = -12.f;
    bool isJumping = false;

    while (window.isOpen())
    {
        // --- Event Handling ---
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
                updateView(window, view);
        }

        // --- Input ---
        sf::Vector2f pos = player.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-5.f, 0.f);
        if (pos.x > worldWidth)
            player.setPosition(0.f - player.getSize().x, pos.y);
        else if (pos.x + player.getSize().x < 0.f)
            player.setPosition(worldWidth, pos.y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(5.f, 0.f);
        if (pos.x > worldWidth)
            player.setPosition(0.f - player.getSize().x, pos.y);
        else if (pos.x + player.getSize().x < 0.f)
            player.setPosition(worldWidth, pos.y);
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) && !isJumping)
        {
            velocity.y = jumpSpeed;
            isJumping = true;
        }

        // --- Physics ---
        velocity.y += gravity;
        player.move(0, velocity.y);

        // --- Collision with all platforms ---
        for (auto &plat : platforms)
        {
            if (player.getGlobalBounds().intersects(plat.getGlobalBounds()))
            {
                if (velocity.y > 0) // Only correct while falling
                {
                    player.setPosition(player.getPosition().x, plat.getPosition().y - player.getSize().y);
                    velocity.y = 0;
                    isJumping = false;
                }
            }
        }

        // --- Drawing ---
        window.clear(sf::Color::Black);
        window.setView(view);

        window.draw(player);
        for (auto &plat : platforms)
            window.draw(plat);

        window.display();
    }

    return 0;
}
