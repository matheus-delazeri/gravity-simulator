#include "filesystem"
#include <iostream>

class Settings {
public:
    float GRAVITY = 9.8;
    float TIME_DELAY = 500;
    sf::Font font;
    sf::Text text;

    Settings() {
        this->font.loadFromFile("./src/fonts/arial.ttf");
        this->text.setFont(this->font);
        this->text.setCharacterSize(15);
        this->text.setFillColor(sf::Color(255, 255, 255));
    }
    sf::Text prepareText(std::string string, sf::Vector2f position){
        this->text.setString(string);
        this->text.setPosition(position);

        return this->text;
    }
};