#include <iostream>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "colony.h"
#include "config.h"

using SFMLEventType = sf::Event::EventType;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Game Demo");
    window.setFramerateLimit(60);

    World gameWorld(window, 50, 50, 800, 600);
    Colony c1(gameWorld, 400, 300, 50, sf::Color::Blue, "Blue Colony");

    sf::Event event;
    const float dt = 0.016f;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == SFMLEventType::Closed) {
                window.close();
            }
            if (event.type == SFMLEventType::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Key::Escape:
                        window.close();
                    default:;
                        c1.spawn_ant();
                }
            }
        }

        gameWorld.update(dt);

        window.clear();
        gameWorld.render();
        window.display();
    }

    std::cout << "Application terminated." << std::endl;
    return 0;
}
