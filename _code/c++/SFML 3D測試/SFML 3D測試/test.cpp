#include <SFML/Graphics.hpp>
#include <array>
#include <cmath>

// 用於計算 3D 透視投影
sf::Vector2f projectPoint(const sf::Vector3f& point, float fov, float aspect, float nearPlane) {
    float scale = nearPlane / (point.z + nearPlane);
    return sf::Vector2f(point.x * scale * fov * aspect, point.y * scale * fov);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "3D Cube Simulation with SFML");

    // Cube's 3D points
    std::array<sf::Vector3f, 8> cube = { {
        {-50, -50, -50}, {50, -50, -50}, {50, 50, -50}, {-50, 50, -50},
        {-50, -50, 50}, {50, -50, 50}, {50, 50, 50}, {-50, 50, 50}
    } };

    // Cube's edges
    std::array<std::pair<int, int>, 12> edges = { {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, // Back face
        {4, 5}, {5, 6}, {6, 7}, {7, 4}, // Front face
        {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Connections
    } };

    // Camera parameters
    sf::Vector3f cameraPos(0, 0, -20);
    float fov = 1.5f;      // Field of view (radians)
    float aspect = 800.f / 600.f; // Aspect ratio
    float nearPlane = 1.f; // Near clipping plane
    sf::Vector3f rotation(0, 0, 0); // Cube's rotation

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle input for cube rotation
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) rotation.y -= 0.02f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) rotation.y += 0.02f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) rotation.x -= 0.02f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) rotation.x += 0.02f;

        // Rotate cube points
        std::array<sf::Vector3f, 8> transformedCube = cube;
        for (auto& point : transformedCube) {
            // Rotate around X axis
            float y = point.y * cos(rotation.x) - point.z * sin(rotation.x);
            float z = point.y * sin(rotation.x) + point.z * cos(rotation.x);
            point.y = y;
            point.z = z;

            // Rotate around Y axis
            float x = point.x * cos(rotation.y) + point.z * sin(rotation.y);
            z = -point.x * sin(rotation.y) + point.z * cos(rotation.y);
            point.x = x;
            point.z = z;
        }

        // Project 3D points onto 2D screen
        std::vector<sf::Vector2f> projectedPoints;
        for (const auto& point : transformedCube) {
            sf::Vector3f transformedPoint = point + cameraPos;
            projectedPoints.push_back(projectPoint(transformedPoint, fov, aspect, nearPlane));
        }

        // Convert projected points to SFML coordinates
        std::vector<sf::Vector2f> screenPoints;
        for (const auto& point : projectedPoints) {
            screenPoints.push_back({ point.x + window.getSize().x / 2, -point.y + window.getSize().y / 2 });
        }

        window.clear();

        // Draw edges
        sf::Vertex line[2];
        for (const auto& edge : edges) {
            line[0] = sf::Vertex(screenPoints[edge.first], sf::Color::White);
            line[1] = sf::Vertex(screenPoints[edge.second], sf::Color::White);
            window.draw(line, 2, sf::Lines);
        }

        window.display();
    }

    return 0;
}
