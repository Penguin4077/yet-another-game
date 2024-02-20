#include <SFML/Graphics.hpp>
#include <GAME/homeScreen.hpp>
#include <iostream>

sf::Vector2u GetWinSize() {
    sf::RenderWindow window(sf::VideoMode(100, 100), "GetWinSize");
    
    sf::Vector2u winSize = window.getSize();
    window.close();

    return winSize;
}

int main() {
    std::cout << "Game by PenguinTrooper\n";
    std::cout << "Please do not worry if you see a small window appearing and disappearing, it measures your screen size\n";

    sf::Vector2u winSize = GetWinSize();
    sf::RenderWindow window(sf::VideoMode(winSize.x ,winSize.y), "Game", sf::Style::Fullscreen);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        homeScreen(window);
        window.display();
    }

    return 0;
}