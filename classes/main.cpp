#include <SFML/Graphics.hpp>
#include <iostream>
#include "../includes/TopBar.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Editor de Texto");

    // Criação da fonte
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Erro ao carregar a fonte." << std::endl;
        return 1;
    }

    TopBar topBar(window, font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Verifica se o usuário clicou em algum dos botões de menu ou submenu
            topBar.handleEvent(event);
            
        }

        window.clear();
        topBar.draw(window);
        window.display();
    }

    return 0;
}
