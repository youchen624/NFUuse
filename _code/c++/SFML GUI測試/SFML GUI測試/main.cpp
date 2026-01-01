#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class RectanglePool {
public:
    RectanglePool(size_t initialSize) {
        for (size_t i = 0; i < initialSize; ++i) {
            auto rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(50, 50));
            rect->setFillColor(sf::Color::Green);
            pool.push_back(std::move(rect));
        }
    }

    // 獲取一個可用的對象
    sf::RectangleShape* acquire() {
        if (!pool.empty()) {
            auto rect = std::move(pool.back());
            pool.pop_back();
            active.push_back(std::move(rect));
            return active.back().get();
        }

        // 如果池中沒有可用對象，動態創建
        auto rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(50, 50));
        rect->setFillColor(sf::Color::Red); // 新創建的對象使用不同顏色
        active.push_back(std::move(rect));
        return active.back().get();
    }

    // 回收一個對象
    void release(sf::RectangleShape* rect) {
        auto it = std::find_if(active.begin(), active.end(),
            [rect](const std::unique_ptr<sf::RectangleShape>& r) {
                return r.get() == rect;
            });
        if (it != active.end()) {
            pool.push_back(std::move(*it));
            active.erase(it);
        }
    }

    // 渲染所有活躍的對象
    void render(sf::RenderWindow& window) {
        for (const auto& rect : active) {
            window.draw(*rect);
        }
    }
    const std::vector<std::unique_ptr<sf::RectangleShape>>& getActive() const {
        return active;
    }
private:
    std::vector<std::unique_ptr<sf::RectangleShape>> pool;  // 可用對象池
    std::vector<std::unique_ptr<sf::RectangleShape>> active; // 活躍對象
};
class Game {
public:
    class General {
    public:
        class Draggable : sf::
    };
};
class GameObjectsUnit : public sf::Drawable {
    /***
    * 遊戲物件單元 sf::Drawable
    */
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        for (const auto& obj : objects) {
            target.draw(*obj, states);
        }
    }

private:
    std::vector<std::unique_ptr<sf::Drawable>> objects;
    sf::Vector2f xy;
};
class GameObject_GUI : public sf::Drawable {
    /***
    * GUI嵌套GUI或sf::Drawable
    */
    class Button {

    };
public:
private:
};
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), L"GUI 製作/測試");

    RectanglePool pool(5); // 初始化包含5個方形的對象池

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            /*
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // 點擊左鍵，從池中取出對象並初始化位置
                    sf::RectangleShape* rect = pool.acquire();
                    rect->setPosition(event.mouseButton.x, event.mouseButton.y);
                }

                if (event.mouseButton.button == sf::Mouse::Right) {
                    // 點擊右鍵，將距滑鼠最近的方形回收
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                    for (auto& rect : pool.getActive()) {
                        if (rect->getGlobalBounds().contains(mousePos)) {
                            pool.release(rect.get());
                            break;
                        }
                    }
                }
            }
            */
        }

        window.clear();
        pool.render(window); // 渲染活躍對象
        window.display();
    }

    return 0;
}
