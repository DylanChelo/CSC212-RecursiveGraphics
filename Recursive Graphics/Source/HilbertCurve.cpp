#include "../Headers/HilbertCurve.hpp"

//hilbertCurve functions

//constructor for curve
hilbertCurve::hilbertCurve(int n, int width, int height,int type,sf::Color color,sf::RenderWindow* window){
    this->n = n;
    this->width = width;
    this->height = height;
    this->window = window;
    this->color = color;
    this->type = type;
    
}

//updates the drawing of the curve. Based on the user input, the primitive type for the vertex vector changes
void hilbertCurve::updateDraw(){
    if(type % 3 == 0){
        window->draw(&topLeft[0], topLeft.size(), sf::LineStrip);
    }
    if(type % 3 == 1){
        window->draw(&topLeft[0], topLeft.size(), sf::TriangleStrip);
    }
    if(type % 3 == 2){
        window->draw(&topLeft[0], topLeft.size(), sf::Triangles);
    }
}


//scales all vertexes(points) in a vector about a given point
//in cases for this fractal, the points are scaled to the width/2 and the height/2 (AKA the center of the window)
void hilbertCurve::scaleToPoint(int centerX, int centerY, std::vector<sf::Vertex>* vector){
    for(int i = 0;i < vector->size();i++){
        (*vector)[i].position.x = 0.5 * ((*vector)[i].position.x - centerX) + centerX;
        (*vector)[i].position.y = 0.5 * ((*vector)[i].position.y - centerY) + centerY;
    }
}

//ROTATE FUNCTIONS
//rotates a given vector of vertexes(points) Counter-Clockwise 90 degrees about the middle of the window.It is important to note that the middle of the window is != to (0,0). (0,0) is the upper-most left point.
void hilbertCurve::rotateCounterClockwise(std::vector<sf::Vertex>* vector){
    for(int i = 0;i < vector->size();i++){
        (*vector)[i].position.x += -width/2;
        (*vector)[i].position.y += -height/2;
        std::swap((*vector)[i].position.x,(*vector)[i].position.y);
        (*vector)[i].position.y *= -1;
        (*vector)[i].position.x += width/2;
        (*vector)[i].position.y += height/2;
    }
}

//rotates a given vector of vertexes(points) Clockwise 90 degrees about the middle of the window.It is important to note that the middle of the window is != to (0,0). (0,0) is the upper-most left point.
void hilbertCurve::rotateClockwise(std::vector<sf::Vertex>* vector){
    for(int i = 0;i < vector->size();i++){
        (*vector)[i].position.x += -width/2;
        (*vector)[i].position.y += -height/2;
        std::swap((*vector)[i].position.x,(*vector)[i].position.y);
        (*vector)[i].position.x *= -1;
        (*vector)[i].position.x += width/2;
        (*vector)[i].position.y += height/2;
    }
}
//MOVE FUNCTIONS
//All 4 copies of the curve start at the midpoint (width/2,height/2) of the window. Because of this, to move the copies to their respective corners of the window, 1/4 the width/height of the window is added or subtracted to all the points of each copy.

//moves to top left
void hilbertCurve::moveTopleft(){
    for(int i = 0;i < topLeft.size();i++){
        topLeft[i].position.x += -width/4;
        topLeft[i].position.y += -height/4;
    }
}
//moves to top right
void hilbertCurve::moveTopRight(){
    for(int i = 0;i < topRight.size();i++){
        topRight[i].position.x += width/4;
        topRight[i].position.y += -height/4;
    }
}
//moves to bottom left
void hilbertCurve::moveBottomLeft(){
    for(int i = 0;i < bottomLeft.size();i++){
        bottomLeft[i].position.x += -width/4;
        bottomLeft[i].position.y += height/4;
    }
}
//moves to bottom right
void hilbertCurve::moveBottomRight(){
    for(int i = 0;i < bottomRight.size();i++){
        bottomRight[i].position.x += width/4;
        bottomRight[i].position.y += height/4;
    }
}

//Creates the first "bucket" shape
void hilbertCurve::firstCurve(){
    topLeft.push_back(sf::Vector2f(width/4,height/4));
    topLeft.push_back(sf::Vector2f(width/4,height*3/4));
    topLeft.push_back(sf::Vector2f(width*3/4,height*3/4));
    topLeft.push_back(sf::Vector2f(width*3/4,height/4));
}
//adds color to the first four points (first four points are copied so color carries to future iterations)
void hilbertCurve::addColor(){
    for(int i = 0;i < topLeft.size();i++){
        topLeft[i].color = color;
    }
}

//helper function that is called in main
//declares counter to be used in recursive call, creates the initial "bucket" including color, then it calls the recursive function and finally updates the drawing.
void hilbertCurve::createCurve(){
    int counter = 0;
    firstCurve();
    addColor();
    recursiveCurve(counter);
    updateDraw();
}

//recursive function that creates curve based on given number of iterations
void hilbertCurve::recursiveCurve(int counter){
    //base case
    if(n == counter){
        return;
    }
    //scales all points of top left vector in half
    scaleToPoint(width/2,height/2,&topLeft);
    
    //sets all other vectors to be = to top left vector, essentially copying the curve 3 times.
    topRight = topLeft;
    bottomLeft = topLeft;
    bottomRight = topLeft;
    
    //rotates top left curve counter clockwise
    rotateCounterClockwise(&topLeft);
    //rotates top right curve clockwise
    rotateClockwise(&topRight);
    
    //moves all four copies to respective corners of the window
    moveTopleft();
    moveTopRight();
    moveBottomLeft();
    moveBottomRight();
    
    //Reverses top left and top right vectors
    //this is done because after the rotation, if the vectors aren't reversed, when they are inserted into the top left vector, the points will be connected incorrectly
    std::reverse(topLeft.begin(), topLeft.end());
    std::reverse(topRight.begin(), topRight.end());
    
    //top right, bottom left, and bottom right vectors are inserted into the end of top left. This is done to connect the points and prepare for the next iteration where top left is copied onto the other vectors.
    topLeft.insert(topLeft.end(), bottomLeft.begin(), bottomLeft.end());
    topLeft.insert(topLeft.end(), bottomRight.begin(), bottomRight.end());
    topLeft.insert(topLeft.end(), topRight.begin(), topRight.end());
    
    //function is recursively called to begin another iteration until base case is met
    return recursiveCurve(counter + 1);
}

