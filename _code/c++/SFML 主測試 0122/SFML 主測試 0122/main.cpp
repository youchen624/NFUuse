#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class GameUnitData {
public:
	sf::Vector2f pos;
	float rotation;
	bool invisible = false;
	bool disable = false;
};
class GameUnit {
public:
	GameUnit() {}
	virtual ~GameUnit() {}
	virtual void tick(const sf::Event& event) {};
	virtual void renderTick(sf::RenderWindow& window) {};
	virtual void addShape(sf::Shape* ptr) { body = ptr; }
	virtual void move(sf::Vector2f delta)				{ if (body) body->move(delta); }
	virtual void move(float offsetX, float offsetY)	{ if (body) body->move(offsetX, offsetY); }
	virtual void print(sf::RenderWindow& window) { if (!attributes.invisible && body) window.draw(*body); }
	virtual void preset() {};
	virtual void reset() {};
	//virtual sf::Vector2f getPos() {};
	class Attributes {
	public:
		bool invisible = false;
		bool disable = false; //design logic: totally disable, not only render disable
	} attributes;
protected:
	sf::Shape* body;
};
class GameUnits : public GameUnit {
public:
	//setTop setButton
	virtual void addShape(sf::Shape* ptr) override { bodys.push_back(ptr); }
	virtual void addShapes(std::vector<sf::Shape*> ptrV) { bodys.insert(bodys.end(), ptrV.begin(), ptrV.end()); }; //<<<
	//virtual void addShapes(std::vector<sf::Shape*> ptrV) {}; //<<<
	virtual void popShape() { bodys.pop_back(); }
	virtual void delShape(sf::Shape* ptr) {
		auto it = std::find(bodys.begin(), bodys.end(), ptr);
		if (it != bodys.end()) bodys.erase(it);
	}
	virtual void move(sf::Vector2f delta) override { for (auto& body : bodys) body->move(delta); }
	virtual void move(float offsetX, float offsetY) override { for (auto& body : bodys) body->move(offsetX, offsetY); }
protected:
	std::vector<sf::Shape*> bodys;
};
// class GameUnitSpecial{};
// 
// class GameGUI
// class GameWindow
class GameTextInput {};
class GameLogger {};
class GameCPU {};
// class Clickable : public GameUnit{}; //預想 負緣觸發
class Clickable : public GameUnit {
public:
	void tick(const sf::Event& event) override {
		if (event.type == sf::Event::MouseButtonPressed) {
			switch (event.mouseButton.button) {
			case sf::Mouse::Left:		if(onLeftClick)		onLeftClick();		break;
			case sf::Mouse::Right:		if(onRightClick)	onRightClick();		break;
			case sf::Mouse::Middle:	if(onMiddleClick) onMiddleClick();	break;
			}
		}
	}
	void (*onLeftClick)();
	void (*onRightClick)();
	void (*onMiddleClick)();
private:
};
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
	~Draggable() {
		auto it = std::find(these.begin(), these.end(), this);
		if (it != these.end()) these.erase(it);
	}
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
				for(auto& moveTarget : it->moveTargets) {
					moveTarget->move(delta);
					//printf("移動目標\n");
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

	std::vector<GameUnit*>& getAllMoving() {
		static std::vector<GameUnit*> result; // 將 this 添加到新容器
		result = { this }; // 將 this 添加到新容器
		result.insert(result.end(), moveTargets.begin(), moveTargets.end());
		return result; // 返回容器副本
	}
///^^^^^^^<<<<<< problem here, 重複儲存指標=>重複move
	/// ^^^^<<<< more problem static


	// TODO 偵測重複target指標 避免重複移動(多重)
	void addMoveTarget(GameUnit* newTarget) { moveTargets.push_back(newTarget); }
	void addMoveTargets(std::vector<GameUnit*>& newTargets) { moveTargets.insert(moveTargets.end(), newTargets.begin(), newTargets.end()); }
	void removeMoveTarget(GameUnit* theTarget) {
		auto it = std::find(moveTargets.begin(), moveTargets.end(), theTarget);
		if (it != moveTargets.end()) moveTargets.erase(it);
	}
	void removeMoveTargets(std::vector<GameUnit*>& theTargets) {
		for(auto theTarget : theTargets) removeMoveTarget(theTarget);
	}
	bool isMouseTouch(sf::Vector2f mousePos) { return cBody.getGlobalBounds().contains(mousePos); }
private:
	sf::RectangleShape cBody;
	//sf::Shape* body = &cBody;
	static std::vector<Draggable*> these;
	bool isDragging = false;
	sf::Vector2f lastMousePos;
	//GameUnit* moveTarget = nullptr; // 移動目標
	std::vector<GameUnit*> moveTargets; // 移動目標
};
//class GameCircle : public sf::CircleShape, public GameUnit {};
// <<<<<<<<<<<===================
// 定義靜態成員變數
std::vector<Draggable*> Draggable::these;
int main() {
	// 創建視窗
	sf::RenderWindow window(sf::VideoMode(800, 600), L"測試");
	/*
	sf::Image icon;
	if (!icon.loadFromFile("icon.png")) return -1; // 如果載入失敗，退出程式
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	*/
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
	test2.addMoveTarget(&test3);
	//test3.addMoveTarget(&test2);
	test1.addMoveTargets(test2.getAllMoving());
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