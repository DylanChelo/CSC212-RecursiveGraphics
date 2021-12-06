#include <iostream>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>

sf::CircleShape genTriangle(float size, float positionX, float positionY, sf::Color color);
void recursion(float size, int numRecursions, std::vector<sf::CircleShape> * triangles);

int main(int argc, char**argv) {
    float size = std::stoi(argv[1]);
    int numRecursions = std::stoi(argv[2]);
    std::vector<sf::CircleShape> triangles;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(size, ((sqrt(3))/2)*size), "Serpinski's Triangle", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    recursion(size, numRecursions, &triangles);

    //main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = triangles.size() - 1; i >= 0; i--) {
            window.draw(triangles[i]);
        }
        window.display();
    }

    return 0;
}

sf::CircleShape genTriangle(float size, float positionX, float positionY, sf::Color color) {
    float radius = size/(sqrt(3));
    sf::CircleShape Triangle;
    Triangle.setPointCount(3);
    Triangle.setRadius(radius);
    Triangle.setOrigin(radius,size/2);
    Triangle.setFillColor(color);
    Triangle.setPosition(positionX, positionY);
    return Triangle;
}

void recursion(float size, int numRecursions, std::vector<sf::CircleShape> * triangles) {
    if (triangles.size() == 0) {
        triangles->push_back(genTriangle(size, size/2, size/2, sf::Color::Red));
    }
if (numRecursions != 0) {
    //Top Triangle
    recursion(size/2, numRecursions - 1, triangles);
    triangles->push_back(genTriangle(size, size/2, size/2, sf::Color::White));
    
} else {
    
}
}





//Way to save image
sf::Texture texture;
texture.create(render_window.getSize().x, render_window.getSize().y);
texture.update(render_window);
if (texture.copyToImage().saveToFile(filename))
{
    std::cout << "screenshot saved to " << filename << std::endl;
}