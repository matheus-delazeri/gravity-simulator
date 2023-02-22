#include "SFML/Graphics.hpp"

const float RADIUS = 15;

class Circle : public sf::CircleShape {
public:
    sf::Color color = sf::Color(255, 255, 255);
    sf::Vector2f position;
    Settings settings;
    float velocity = 0;
    float createdAt;
    Circle(sf::Vector2i position, float createdAt) : sf::CircleShape(RADIUS) {
        this->position = (sf::Vector2f)position;
        this->createdAt = createdAt;
        this->setFillColor(color);
        this->setPosition(this->position);
    }
    void updatePosition(float nowTime) {
        this->velocity = this->getElapsedTime(nowTime) * this->settings.GRAVITY;
        this->position.y += this->velocity;
        this->setPosition(this->position);
    }
private:
    float getElapsedTime(float nowTime) const {
        return (nowTime - this->createdAt) / this->settings.TIME_DELAY;
    }
};