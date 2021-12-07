#include "../Headers/KochSnowflake.hpp"

KochSnowflake::KochSnowflake(int degree,int width,int height,int type,sf::Color color, sf::RenderWindow* window){
    this->degree = degree;
    this->window = window;
    this->width = width;
    this->height = height;
    this->type = type;
    this-> color = color;
}

//gets the points for the new triangles being added on every line of the snowflake
//depending on the slope of the given line, the points must be calculated differently
void KochSnowflake::getCorrectPoints(int index){
    
    std::vector<sf::Vertex> smallTemp;
    //creates vertexes to later be added into a temporary vector
    sf::Vertex tempOne;
    sf::Vertex tempTwo;
    sf::Vertex tempThree;

    double dxOne;
    double dxTwo;
    double dxThree;
    
    double dyOne;
    double dyTwo;
    double dyThree;

    double x;
    //finds slope of given line
    double slope = (vertices[index].position.y - vertices[index + 1].position.y)/(vertices[index].position.x - vertices[index + 1].position.x);

    //if slope is negative AKA / shape since y's increase going down
    if(slope < 0){
        //finds the change in x of the line / side and assigns it to x
        x = vertices[index].position.x - vertices[index+ 1].position.x;
        //point 1 x value = x value of first point - one third of change in x
        dxOne = std::abs(vertices[index].position.x - (x / 3));
        //point 3 x value = x value of first point - two thirds of change in x
        dxThree = std::abs(vertices[index].position.x - (2 * x / 3));
        //point 1 y value = y value of second point - four thirds of change in x
        dyOne =std::abs(vertices[index + 1].position.y - (4 * x / 3));
        //point 3 y value = y value of second point - two thirds of change in x
        dyThree = std::abs(vertices[index + 1].position.y - (2 * x / 3));
        //point 2 x value = x value of second point
        dxTwo = vertices[index + 1].position.x;
        //point 2 y value = point 1 y value
        dyTwo = dyOne;
        //creates vertexes/points to later be put into vector
        tempOne = sf::Vector2f(dxOne, dyOne);
        tempTwo = sf::Vector2f(dxTwo, dyTwo);
        tempThree = sf::Vector2f(dxThree, dyThree);
    }
    //if slope is positive AKA \ shape since y's increase going down
    else if (slope > 0){
            
            x = vertices[index].position.x - vertices[index + 1].position.x;

            dxOne = std::abs(vertices[index + 1].position.x + (2 * x / 3));

            dxThree = std::abs(vertices[index + 1].position.x + (x / 3));

            dyOne = std::abs(vertices[index].position.y - (2 * x / 3));

            dyThree = std::abs(vertices[index].position.y - (4 * x / 3));

            dxTwo = vertices[index].position.x;

            dyTwo = dyThree;

            tempOne = sf::Vector2f(dxOne, dyOne);
            tempTwo = sf::Vector2f(dxTwo, dyTwo);
            tempThree = sf::Vector2f(dxThree, dyThree);
        
    }
    else{
        if(vertices[index].position.x < vertices[index + 1].position.x){
            dxOne = vertices[index + 1].position.x - vertices[index].position.x;
            dxOne = dxOne / 3;
            dxOne = vertices[index].position.x + dxOne;

            dxThree = vertices[index + 1].position.x - vertices[index].position.x;
            dxThree = 2 * dxThree / 3;
            dxThree = dxThree + vertices[index].position.x;

            dyOne = vertices[index].position.y;

            dyThree = vertices[index].position.y;

            dxTwo = vertices[index].position.x + vertices[index + 1].position.x;
            dxTwo = dxTwo / 2;
                

            dyTwo = vertices[index].position.y + sqrt(pow(sideLength,2) - pow(sideLength,2) / (4*(degree)));
            
            

            tempOne = sf::Vector2f(dxOne, dyOne);
            tempTwo = sf::Vector2f(dxTwo, dyTwo);
            tempThree = sf::Vector2f(dxThree, dyThree);
        }
        else{
            dxOne = vertices[index + 1].position.x - vertices[index].position.x;
            dxOne = dxOne / 3;
            dxOne = vertices[index].position.x + dxOne;

            dxThree = vertices[index + 1].position.x - vertices[index].position.x;
            dxThree = 2 * dxThree / 3;
            dxThree = dxThree + vertices[index].position.x;

            dyOne = vertices[index].position.y;

            dyThree = vertices[index].position.y;

            dxTwo = vertices[index].position.x + vertices[index + 1].position.x;
            dxTwo = dxTwo / 2;

            dyTwo = vertices[index].position.y - sqrt(pow(sideLength,2) - pow(sideLength,2) / 4);

            tempOne = sf::Vector2f(dxOne, dyOne);
            tempTwo = sf::Vector2f(dxTwo, dyTwo);
            tempThree = sf::Vector2f(dxThree, dyThree);
        }
    }

    smallTemp.push_back(tempOne);
    smallTemp.push_back(tempTwo);
    smallTemp.push_back(tempThree);

    temp.push_back(smallTemp);
}




void KochSnowflake::recurseSnowflake(int counter){

    //Base Case
    if(counter == degree){
        return;
    }


    //Change length of side to be 1/3 the original size
    sideLength = sideLength/3;

    unsigned long int vectSize = vertices.size();

    //Loop to find all the points that need to be added
    for(int i = 0; i < vectSize - 1; i++){
        //Find the 3 points to make the new triangle in between each of the points
        getCorrectPoints(i);
    }

    //Put all values from temp into final vector

    finalVector.clear();

    for(int i = 1; i < 4 * (vertices.size() - 1); i = i + 4){
        finalVector.insert(finalVector.begin() + i - 1, vertices[(i - 1) / 4]);
        finalVector.insert(finalVector.begin() + i, temp[(i - 1) / 4][0]);
        finalVector.insert(finalVector.begin() + i + 1, temp[(i - 1) / 4][1]);
        finalVector.insert(finalVector.begin() + i + 2, temp[(i - 1) / 4][2]);
    }
    finalVector.insert(finalVector.begin() + finalVector.size(), vertices[0]);
    
    
    temp.clear();
    vertices.clear();

    for(int i = 0; i < finalVector.size(); i++){
        vertices.push_back(finalVector[i]);
    }

    
    recurseSnowflake(counter + 1);
}


void KochSnowflake::firstSnowflake(){
    //Push back the first three points of the original triangle
    vertices.push_back(sf::Vector2f(width/2, height/4));
    vertices.push_back(sf::Vector2f(width/4, 3*height/4));
    vertices.push_back(sf::Vector2f(3*width/4, 3*height/4));
    vertices.push_back(sf::Vector2f(width/2, height/4));

    if(degree == 1){
    finalVector.push_back(sf::Vector2f(width/2, height/4));
    finalVector.push_back(sf::Vector2f(width/4, 3*height/4));
    finalVector.push_back(sf::Vector2f(3*width/4, 3*height/4));
    finalVector.push_back(sf::Vector2f(width/2, height/4));
    }

    sideLength = vertices[2].position.x - vertices[1].position.x;


    //Check if degree is greater than one
        //Call recursive function
        if (degree > 1) {
        recurseSnowflake(1);
        }
}

void KochSnowflake::addColor(){
    for(int i = 0;i < finalVector.size();i++){
        finalVector[i].color = color;
    }
}

void KochSnowflake::drawSnowflake(){
    if(type % 6 == 0){
        window->draw(&finalVector[0], finalVector.size(), sf::LineStrip);
    }
    if(type % 6 == 1){
        window->draw(&finalVector[0], finalVector.size(), sf::Lines);
    }
    if(type % 6 == 2){
        window->draw(&finalVector[0], finalVector.size(), sf::Triangles);
    }
    if(type % 6 == 3){
        window->draw(&finalVector[0], finalVector.size(), sf::TrianglesStrip);
    }
    if(type % 6 == 4){
        window->draw(&finalVector[0], finalVector.size(), sf::TrianglesFan);
    }
    if(type % 6 == 5){
        window->draw(&finalVector[0], finalVector.size(), sf::Quads);
    }
}


void KochSnowflake::createSnowflake(){
    firstSnowflake();
    addColor();
    drawSnowflake();
}









