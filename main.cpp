#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_manager.h"
#include "config.h"

using SFMLEventType = sf::Event::EventType;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Game Demo");
    window.setFramerateLimit(60);

    sf::RenderStates renderState;
    GameManager game(window, renderState);
    game.createWorld(800, 600, 50, 50);
    game.spawnColony(0, 400, 300, 15000, sf::Color::Blue, "Blue Colony");

    sf::Event event;
    const float dt = 0.016f;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == SFMLEventType::Closed) {
                window.close();
            }

            if (event.type == SFMLEventType::KeyReleased) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        game.update(dt);

        window.clear();
        game.render();
        window.display();
    }

    std::cout << "Application terminated." << std::endl;
    return 0;
}
