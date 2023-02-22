#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Circle.h"

const sf::Vector2i WINDOW_SIZE = {1000, 1000};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Gravity");
    sf::Clock clock;
    std::vector<Circle> circles;
    Settings settings;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Circle newCircle(sf::Mouse::getPosition(window), clock.getElapsedTime().asSeconds());
                circles.push_back(newCircle);
            }
        }

        window.clear();
        sf::Vector2f timeElapsedPos(20, 20);
        window.draw(settings.prepareText("Time elapsed: " + std::to_string(clock.getElapsedTime().asSeconds()) + "s", timeElapsedPos));
        int i = 0;
        for (Circle &circle : circles) {
            circle.updatePosition(clock.getElapsedTime().asSeconds());

            window.draw(circle);
            std::string velocityText = std::to_string(circle.velocity) + " m/s";
            sf::Vector2f velocityPos(circle.position.x + 50, circle.position.y);
            window.draw(settings.prepareText(velocityText, velocityPos));
            if (circle.position.y >= WINDOW_SIZE.y) {
                circles.erase(circles.begin() + i);
            }

            i++;
        }

        window.display();
    }

    return 0;
}
