#ifndef hilbertCurve_hpp
#define hilbertCurve_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>


class hilbertCurve{
    private:
        int n;
        int width;
        int height;
        int type;
        sf::Color color;
        sf::RenderWindow* window;
        std::vector<sf::Vertex> topLeft;
        std::vector<sf::Vertex> topRight;
        std::vector<sf::Vertex> bottomLeft;
        std::vector<sf::Vertex> bottomRight;
        void updateDraw();
        void scaleToPoint(int centerX, int centerY, std::vector<sf::Vertex>* vector);
        void rotateCounterClockwise(std::vector<sf::Vertex>* vector);
        void rotateClockwise(std::vector<sf::Vertex>* vector);
        void moveTopleft();
        void moveTopRight();
        void moveBottomLeft();
        void moveBottomRight();
        void firstCurve();
        void recursiveCurve(int counter);
        void addColor();
        
        
    
    public:
        hilbertCurve(int n, int width, int height,int type,sf::Color color,sf::RenderWindow* window);
        void createCurve();
    
};

#endif /* curveObject_hpp */
