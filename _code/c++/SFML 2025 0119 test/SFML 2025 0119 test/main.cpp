#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#define IDI_APP_ICON 102
class GameUnit {
public:
	GameUnit(){}
	~GameUnit(){}
	void tick() {};
	void renderTick(sf::RenderWindow& window) {};
	void move(sf::Vector2f vector2f) { body->move(vector2f); }
	void move(float offsetX, float offsetY) { body->move(offsetX, offsetY); }
protected:
	sf::Shape* body;
};
// class GameUnitSpecial{};
// class Clickable : public GameUnit{};
class Draggable : public GameUnit {
	/***
	 * TODO 將body改成新類 改成多元素類
	 * TODO 修改偵測邏輯 新增偵測目標
	*/
public:
	Draggable(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) {
		body = &cBody;
		cBody.setSize(size);
		cBody.setPosition(position);
		cBody.setFillColor(color);
		these.push_back(this);
	}
	~Draggable() { these.erase(std::remove(these.begin(), these.end(), this), these.end()); }
	static void tickAll(const sf::Event& event) {
		for (auto& it : these) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				// 滑鼠點擊
				//printf("點擊\n");
				sf::Vector2f mousePos((float)event.mouseButton.x, (float)event.mouseButton.y);
				if (it->isMouseTouch(mousePos)) {
					//當物件被點擊
					it->lastMousePos = mousePos; // 更新起始位置
					it->isDragging = true;        // 開始拖動
					break;
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) { it->isDragging = false; } //結束拖動printf("結束\n");
			if (it->isDragging && event.type == sf::Event::MouseMoved) {
				//移動
				//printf("移動\n");
				sf::Vector2f mousePos((float)event.mouseMove.x, (float)event.mouseMove.y);
				sf::Vector2f delta = mousePos - it->lastMousePos;
				if (it->moveTarget) {
					//printf("移動目標\n");
					it->moveTarget->move(delta);
				}
				it->move(delta);
				it->lastMousePos = mousePos;
			}
		}
	};
	static void renderTickAll(sf::RenderWindow& window) {
		for (size_t i = these.size(); i > 0; --i) {
			auto& it = these[i - 1]; // 從最後一個元素開始
			window.draw(it->cBody);
			// 執行反向迭代操作
		}
		//for (auto& it : these) {}
	};
	//void move(const sf::Transformable& target = body);
	//void setMoveTarget(sf::Transformable* newTarget) { moveTarget = newTarget; }
	void setMoveTarget(GameUnit* newTarget) { moveTarget = newTarget; }
	//void moveBody(sf::Vector2f vector2f) { body->move(vector2f); }
	bool isMouseTouch(sf::Vector2f mousePos) {
		return cBody.getGlobalBounds().contains(mousePos);
	}
private:
	sf::RectangleShape cBody;
	//sf::Shape* body = &cBody;
	static std::vector<Draggable*> these;
	bool isDragging = false;
	sf::Vector2f lastMousePos;
	//sf::Vector2f xy;
	//sf::Transformable* moveTarget = nullptr; // 移動目標
	//Draggable* moveTarget = nullptr; // 移動目標
	GameUnit* moveTarget = nullptr; // 移動目標
};
//class GameCircle : public sf::CircleShape, public GameUnit {};
// <<<<<<<<<<<===================
// 定義靜態成員變數
std::vector<Draggable*> Draggable::these;
int main() {
	// 創建視窗
	sf::RenderWindow window(sf::VideoMode(800, 600), L"測試");
	sf::Image icon;
	if (!icon.loadFromFile("icon.png")) return -1; // 如果載入失敗，退出程式
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	Draggable test1(sf::Vector2f(100, 100), sf::Vector2f(500, 100), sf::Color::Blue);
	Draggable test2(sf::Vector2f(100, 100), sf::Vector2f(100, 100), sf::Color::Red);
	Draggable test3(sf::Vector2f(100, 100), sf::Vector2f(200, 300), sf::Color::Green);
	/*
	GameCircle circle;
	circle.setRadius(50);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(200, 200);
	test2.setMoveTarget(&circle);
	*/
	test1.setMoveTarget(&test2);
	test2.setMoveTarget(&test3);
	test3.setMoveTarget(&test1);
	// 主循環
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Draggable::tickAll(event);

		window.clear(sf::Color::Black);
		Draggable::renderTickAll(window);
		window.display();
	}
	return 0;
}