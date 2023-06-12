#pragma once

#include <SFML/Graphics.hpp>

class TopBar {
private:
    sf::RectangleShape menuBar;
    sf::Text fileButton;
    sf::Text editButton;
    sf::Text newFileSubmenu;
    sf::Text openFileSubmenu;
public:
    TopBar(sf::RenderWindow& window, sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
};