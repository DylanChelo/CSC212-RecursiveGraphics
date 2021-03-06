//Header for Sierpinski's Triangle Fractal
//Written by Mason Jacob

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

class SierpinskiTriangle {
    private:
        int type;
        sf::Color color;
        sf::RectangleShape container;

    public:
        SierpinskiTriangle();
        ~SierpinskiTriangle();
        void setType(int type);
        void setContainer(float x1, float y1, float x2, float y2);
        void setColor(sf::Color color);
        void generateSierpinskiTriangle(int w, int h, int iterations, int type, sf::Color color, sf::RenderWindow & window);
        void drawSierpinskiTriangle(sf::Vector2f &topTrianglePoint, sf::Vector2f &leftTrianglePoint, sf::Vector2f &rightTrianglePoint, int iteration, sf::RenderWindow &window);
        void drawTriangle(sf::Vector2f &topTrianglePoint, sf::Vector2f &leftTrianglePoint, sf::Vector2f &rightTrianglePoint, sf::Color & color, sf::RenderWindow &window);
};
