#include "../Headers/DragonCurve.hpp"

//dragonCurve functions

//constructor for curve
dragonCurve::dragonCurve(int n, int width, int height,int type,sf::Color color, sf::RenderWindow* window){
    this->n = n;
    this->width = width;
    this->height = height;
    this->window = window;
    this->type = type;
    this->color = color;
}

//updates the drawing of the curve. Based on the user input, the primitive type for the vertex vector changes
void dragonCurve::updateDraw(){
    if(type % 3 == 0){
        window->draw(&first[0], first.size(), sf::LineStrip);
    }
    if(type % 3 == 1){
        window->draw(&first[0], first.size(), sf::Quads);
    }
    if(type % 3 == 2){
        window->draw(&first[0], first.size(), sf::TrianglesFan);
    }
}

//scales all points in first vector about the middle of the window(the first point in the first vector = the middle of the window)
void dragonCurve::scaleToPoint(int centerX, int centerY){
    for(int i = 0;i < first.size();i++){
        first[i].position.x = sqrt(2)/2 * (first[i].position.x - centerX) + centerX;
        first[i].position.y = sqrt(2)/2 * (first[i].position.y - centerY) + centerY;
    }
}


//rotates the first vector about the middle of the window 45 degrees counter clockwise.
void dragonCurve::rotateCounterClockwise(){
        //rotate by 45 degrees counter clockwise
    double angle = 45.0;
    double rad = angle*M_PI/180;
    for(int i = 0;i < first.size();i++){
        first[i].position.x += -width/2;
        first[i].position.y += -height/2;
        double tempX = first[i].position.x;
        first[i].position.x = (first[i].position.x * cos(rad)) - (first[i].position.y * sin(rad));
        first[i].position.y = (first[i].position.y * cos(rad)) + (tempX * sin(rad));
        first[i].position.x += width/2;
        first[i].position.y += height/2;
    }
}

//rotates the copy of the first vector 90 degrees clockwise about the last point in the first vector
void dragonCurve::rotateClockwise(){
    int centerX = first[first.size()-1].position.x;
    int centerY = first[first.size()-1].position.y;
    //rotate by 90 degrees clockwise
    for(int i = 0;i < first.size();i++){
        copy[i].position.x += -centerX;
        copy[i].position.y += -centerY;
        std::swap(copy[i].position.x,copy[i].position.y);
        copy[i].position.y *= -1;
        copy[i].position.x += centerX;
        copy[i].position.y += centerY;
    }

}

//translates all points in the vector over such that the first point = the center of the window
void dragonCurve::centerDragon(){
    int offsetX = first[0].position.x - (width/2-width/10);
    int offsetY = first[0].position.y - (height/2);
    for(int i = 0;i < first.size();i++){
        first[i].position.x += -offsetX;
        first[i].position.y += -offsetY;
    }
}

//adds color to the curve
void dragonCurve::addColor(){
    for(int i = 0;i < first.size();i++){
        first[i].color = color;
    }
}

//creates the first line segment of the curve.
//the first point is the center of the window and the second point is 2/10 the width of the window to the right
void dragonCurve::firstCurve(){
    first.push_back(sf::Vector2f(width/2,height/2));
    first.push_back(sf::Vector2f(width/2+width*2/10,height/2));
}

//helper function that is called in main
//declares counter to be used in recursive call, creates the initial line including color, then it calls the recursive function and finally updates the drawing.
void dragonCurve::createCurve(){
    int counter = 0;
    firstCurve();
    addColor();
    recursiveCurve(counter);
    updateDraw();
}

//recursive function that creates curve based on given number of iterations
void dragonCurve::recursiveCurve(int counter){
    //base case
    if(n == counter){
        return;
    }
    //rotates the first vector about the center of the window 45 degrees counter-clockwise
    rotateCounterClockwise();
    
    //creates a copy of the rotated vector
    copy = first;
    
    //rotates the copy 90 degrees clockwise about the last point in the first vector
    rotateClockwise();
    
    //reverses the copy's vector so that it can be inserted into the first vector correctly
    std::reverse(copy.begin(), copy.end());
    
    //inserts the rotated copy into the first vector to make it all one line
    first.insert(first.end(), copy.begin(), copy.end());
    copy.clear();
    //scales first vector so that entire fractal stays the same size in the window
    scaleToPoint(first[0].position.x, first[0].position.y);
    
    //translates vector so that the first point is at the center of the window
    centerDragon();
    
    //function is recursively called to begin another iteration until base case is met
    return recursiveCurve(counter + 1);
}


