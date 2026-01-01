#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), L"隨機方向生成方形並處理失敗");

    // 存放所有方形的容器
    std::vector<sf::RectangleShape> rectangles;

    // 初始方形
    sf::RectangleShape initialRectangle(sf::Vector2f(50, 50));
    initialRectangle.setFillColor(sf::Color::Blue);
    initialRectangle.setPosition(400, 300); // 視窗中央
    rectangles.push_back(initialRectangle);

    // 視圖
    sf::View view = window.getDefaultView();

    // 隨機數生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> directionDist(0, 3); // 方向 0~3
    std::uniform_int_distribution<int> colorDist(0, 255);   // 顏色 0~255

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // 視窗大小改變時，調整視圖
            if (event.type == sf::Event::Resized) {
                view.setSize(event.size.width, event.size.height);
                view.setCenter(event.size.width / 2.0f, event.size.height / 2.0f);
                window.setView(view);
            }

            // 偵測滑鼠點擊事件
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(
                        sf::Vector2i(event.mouseButton.x, event.mouseButton.y), view);

                    for (auto it = rectangles.begin(); it != rectangles.end(); ++it) {
                        if (it->getGlobalBounds().contains(mousePos)) {
                            sf::RectangleShape newRectangle(*it);
                            sf::Vector2f newPosition = it->getPosition();
                            bool positionFound = false;

                            // 嘗試隨機方向
                            int maxAttempts = 4; // 最多4次，因為有4個方向
                            int attempts = 0;

                            while (!positionFound && attempts < maxAttempts) {
                                ++attempts;

                                // 隨機選擇方向
                                int direction = directionDist(gen);
                                switch (direction) {
                                case 0: // 上
                                    newPosition = it->getPosition() + sf::Vector2f(0, -60);
                                    break;
                                case 1: // 下
                                    newPosition = it->getPosition() + sf::Vector2f(0, 60);
                                    break;
                                case 2: // 左
                                    newPosition = it->getPosition() + sf::Vector2f(-60, 0);
                                    break;
                                case 3: // 右
                                    newPosition = it->getPosition() + sf::Vector2f(60, 0);
                                    break;
                                }

                                // 檢查新位置是否與其他方形重疊
                                positionFound = true;
                                for (const auto& existingRect : rectangles) {
                                    if (existingRect.getGlobalBounds().contains(newPosition)) {
                                        positionFound = false;
                                        break;
                                    }
                                }
                            }

                            // 如果找到有效位置
                            if (positionFound) {
                                newRectangle.setPosition(newPosition);

                                // 隨機顏色生成
                                newRectangle.setFillColor(sf::Color(
                                    colorDist(gen), colorDist(gen), colorDist(gen)));

                                rectangles.push_back(newRectangle);
                            }
                            else {
                                // 如果生成失敗，刪除被點擊的方形
                                rectangles.erase(it);
                            }
                            break; // 每次點擊只處理一個方形
                        }
                    }
                }
            }
        }

        // 繪製所有方形
        window.clear();
        for (const auto& rect : rectangles) {
            window.draw(rect);
        }
        window.display();
    }

    return 0;
}
