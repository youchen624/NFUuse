#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    sf::Font notoSan;
    notoSan.loadFromFile("NotoSansTC-VariableFont_wght.ttf");
    sf::Text t;
    t.setFillColor(sf::Color::White);
    t.setFont(notoSan);
    std::string s = "This is text that you type: ";
    t.setString(s);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                printf("%c\n", char(event.text.unicode));
                s = std::to_string(event.key.code);
                //s.append(std::to_string(event.key.code));
            }
        }
        t.setString(s);
        window.clear(sf::Color::Black);
        window.draw(t);
        window.display();
    }
}