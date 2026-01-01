#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#define TEXTURES_FOLDER "assets/textures/"

class TheBasicUnit {
public:
    virtual void tick(const sf::Event& event) {}
    virtual void renderTick(sf::RenderWindow& window) {}
    virtual void saveData() {}
    virtual void loadData() {}
    void test() {}

    //void (*tickPtr)();
protected:
};
/*
class TheBasicRectangleUnit : virtual public TheBasicUnit {
public:
    sf::RectangleShape shape;
};
*/
class TheBasicTextureUnit : virtual public TheBasicUnit {
public:
    sf::Sprite body;
    TheBasicTextureUnit(std::string texturePath) {
        if (!texture.loadFromFile(TEXTURES_FOLDER + texturePath)) { // 確保圖片文件存在
            std::cerr << "Error loading texture at \"" << TEXTURES_FOLDER + texturePath << "\"" << std::endl;
        }
    }
    virtual void renderTick(sf::RenderWindow& window) { window.draw(body); }
    bool isTouch(sf::Vector2f pos) { return body.getGlobalBounds().contains(pos); }
    bool isTouch(sf::FloatRect rect) {
        //rect (x, y, w, h)
        // TODO 檢測body頂點是否contain
        return false;
    }
protected:
    sf::Texture texture;
};

class TheGui : virtual public TheBasicUnit {
public:
    TheGui() {}
    void tick(const sf::Event& event) override {};
    void move(sf::Vector2f delta) {};

    std::vector<TheBasicUnit*> elements;
private:
    sf::RectangleShape base;
};

int main() {
	// 創建視窗
	sf::RenderWindow window(sf::VideoMode(800, 600), L"遊戲視窗");

    //TheBasicUnit test("test.png");
    // 主循環
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        //draw
        //test.renderTick(window);
        window.display();
    }
	return 0;
}