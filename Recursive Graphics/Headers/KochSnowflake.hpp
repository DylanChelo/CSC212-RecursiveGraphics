#ifndef KochSnowflake_hpp
#define KochSnowflake_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>

class KochSnowflake{
private:
    std::vector<sf::Vertex> vertices;
    std::vector<std::vector<sf::Vertex> > temp;
    std::vector<sf::Vertex> finalVector;
    int degree, width, height,type;
    sf::Color color;
    double sideLength;
    sf::RenderWindow* window;
    void recurseSnowflake(int degree);
    void getCorrectPoints(int index);
    void firstSnowflake();
    void drawSnowflake();
    void addColor();

public:
    KochSnowflake(int degree,int width,int height,int type,sf::Color color, sf::RenderWindow* window);
    void createSnowflake();

};

#endif
