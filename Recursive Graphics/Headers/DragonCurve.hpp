//Header for the Dragon's Curve Fractal
//Written by Nick Powers

#ifndef dragonCurve_hpp
#define dragonCurve_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>


class dragonCurve{
    private:
        int n;
        int width;
        int height;
        int type;
        sf::Color color;
        sf::RenderWindow* window;
        std::vector<sf::Vertex> first;
        std::vector<sf::Vertex> copy;
        void scaleToPoint(int centerX, int centerY);
        void rotateCounterClockwise();
        void rotateClockwise();
        void centerDragon();
        void firstCurve();
        void recursiveCurve(int counter);
        void updateDraw();
        void addCurve();
        void addColor();
        
        
    
    public:
        dragonCurve(int n, int width, int height, int type,sf::Color color, sf::RenderWindow* window);
        void createCurve();
    
        
    
    
};

#endif /* curveObject_hpp */
