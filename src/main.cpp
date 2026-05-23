#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "TransitTycoon");
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e))
            if (e.type == sf::Event::Closed) window.close();
        window.clear(sf::Color::Blue);
        window.display();
    }
}