#ifndef KochSnowflake_hpp
#define KochSnowflake_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>

class KochSnowflake{
private:
    //Vector to keep vertices from previous interations
    std::vector<sf::Vertex> vertices;
    //Vector of vectors to store values from current iteration
    std::vector<std::vector<sf::Vertex> > temp;
    //Vector used to combine values from current and previous iteration
    std::vector<sf::Vertex> finalVector;
    
    //integer for the total amount of iterations, width/height of window, and the type of shape
    int degree, width, height, type;
    //Variable to choose a color for the shapes
    sf::Color color;
    //Variable that keeps track of what the length of each of the new lines created should be
    double sideLength;
    //Window that displays the Koch Snowflake
    sf::RenderWindow* window;

    //Functions:
    //Recursion function that gets points one iteration at a time
    void recurseSnowflake(int degree);
    //Function called to gather the three points in between the 
    //previous iteration's points to form new triangle
    void getCorrectPoints(int index);
    //Draws the degree 1 Koch Snowflake (A triangle)
    void firstSnowflake();
    //Uses the window to display the fractal
    void drawSnowflake();
    //Adds color to the fractal
    void addColor();

public:
    //Constructor for the class
    KochSnowflake(int degree,int width,int height,int type,sf::Color color, sf::RenderWindow* window);
    //Function user calls to call all the other functions
    void createSnowflake();

};

#endif
