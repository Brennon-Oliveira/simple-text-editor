#include "../includes/TopBar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

TopBar::TopBar(sf::RenderWindow& window, sf::Font& font){
    // Criação do menu
    menuBar = sf::RectangleShape(sf::Vector2f(window.getSize().x, 30));
    menuBar.setFillColor(sf::Color(200, 200, 200));

    fileButton.setString("File");
    fileButton.setCharacterSize(12);
    fileButton.setFont(font);
    fileButton.setPosition(10, 5);
    fileButton.setFillColor(sf::Color::Black);

    editButton.setString("Edit");
    editButton.setCharacterSize(12);
    editButton.setFont(font);
    editButton.setPosition(60, 5);
    editButton.setFillColor(sf::Color::Black);

    newFileSubmenu.setString("New File");
    newFileSubmenu.setCharacterSize(12);
    newFileSubmenu.setFont(font);
    newFileSubmenu.setPosition(10, 35);
    newFileSubmenu.setFillColor(sf::Color::Black);

    openFileSubmenu.setString("Open File");
    openFileSubmenu.setCharacterSize(12);
    openFileSubmenu.setFont(font);
    openFileSubmenu.setPosition(10, 55);
    openFileSubmenu.setFillColor(sf::Color::Black);
}

void TopBar::draw(sf::RenderWindow& window){
    window.draw(menuBar);
    window.draw(fileButton);
    window.draw(editButton);
    window.draw(newFileSubmenu);
    window.draw(openFileSubmenu);
}

void TopBar::handleEvent(sf::Event& event){
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left){
            sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);

            // Verifica clique no botão "File"
            if (fileButton.getGlobalBounds().contains(mousePos))
            {
                std::cout << "Menu File clicado!" << std::endl;
            }

            // Verifica clique no submenu "New File"
            if (newFileSubmenu.getGlobalBounds().contains(mousePos))
            {
                std::cout << "Submenu New File clicado!" << std::endl;
            }
        }
    }
}