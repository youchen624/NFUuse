#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pixel Point Example");

    // 創建一個像素點
    sf::Vertex pixel(sf::Vector2f(20, 10), sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(&pixel, 1, sf::Points); // 使用 sf::Points 繪製
        window.display();
    }

    return 0;
}
