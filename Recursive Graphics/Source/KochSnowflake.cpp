#include "../Headers/KochSnowflake.hpp"

//Constructor
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

    //X and Y variables of the new vertices
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
            //finds the change in x of the line / side and assigns it to x
            x = vertices[index].position.x - vertices[index + 1].position.x;
            
            //point 1 x value = absolute value of the second points x position 
            //plus two thirds the variable x
            dxOne = std::abs(vertices[index + 1].position.x + (2 * x / 3));
            //point 3 x position = absolute value of the second points x position 
            //plus one third the variable x
            dxThree = std::abs(vertices[index + 1].position.x + (x / 3));

            //point 1 y value = absolute value of the first points y postion
            //minus two thirds the variable x
            dyOne = std::abs(vertices[index].position.y - (2 * x / 3));
            //point 3 y value = absolute value of the first points y postion
            //minus two thirds the variable x 
            dyThree = std::abs(vertices[index].position.y - (4 * x / 3));

            //point 2 x position = first points x postion
            dxTwo = vertices[index].position.x;
            //point 2 y position = point 3 y value
            dyTwo = dyThree;

            //creates vertexes/points to later be put into vector
            tempOne = sf::Vector2f(dxOne, dyOne);
            tempTwo = sf::Vector2f(dxTwo, dyTwo);
            tempThree = sf::Vector2f(dxThree, dyThree);
        
    }
    //If the slope is equal to zero
    else{
        //Checks if next point is to the right of the point at the current index
        if(vertices[index].position.x < vertices[index + 1].position.x){
            //point 1 x value = one third the difference of the second and first points x
            //postion, plus the first points x position 
            dxOne = vertices[index + 1].position.x - vertices[index].position.x;
            dxOne = dxOne / 3;
            dxOne = vertices[index].position.x + dxOne;
            //point 3 x value = second thirds the difference of the second and first points x
            //postion, plus the first points x position 
            dxThree = vertices[index + 1].position.x - vertices[index].position.x;
            dxThree = 2 * dxThree / 3;
            dxThree = dxThree + vertices[index].position.x;

            //point 1 y value = the y value of the first point
            dyOne = vertices[index].position.y;
            //point 3 y value = the y value of the first point
            dyThree = vertices[index].position.y;

            //point 2 x value = the average of the first and second points x values
            dxTwo = vertices[index].position.x + vertices[index + 1].position.x;
            dxTwo = dxTwo / 2;
                
            //point 2 y value = the square root of the length of the line to be added squared 
            //subtracted by one fourth the side length squared
            dyTwo = vertices[index].position.y + sqrt(pow(sideLength,2) - pow(sideLength,2) / (4*(degree)));
            
            
            //creates vertexes/points to later be put into vector
            tempOne = sf::Vector2f(dxOne, dyOne);
            tempTwo = sf::Vector2f(dxTwo, dyTwo);
            tempThree = sf::Vector2f(dxThree, dyThree);
        }
        //Runs if the current point is to the right of the next point
        else{
            //point 1 x value = difference of one third second and first points x position
            //dived by three, added to the first points x position
            dxOne = vertices[index + 1].position.x - vertices[index].position.x;
            dxOne = dxOne / 3;
            dxOne = vertices[index].position.x + dxOne;
            //point 3 x value = difference of two thirds second and first points x position
            //dived by three, added to the first points x position
            dxThree = vertices[index + 1].position.x - vertices[index].position.x;
            dxThree = 2 * dxThree / 3;
            dxThree = dxThree + vertices[index].position.x;

            //point 1 y value = the y value of the first point
            dyOne = vertices[index].position.y;
            //point 3 y value = the y value of the first point
            dyThree = vertices[index].position.y;

            //point 2 x value = the average of the first and second points x values
            dxTwo = vertices[index].position.x + vertices[index + 1].position.x;
            dxTwo = dxTwo / 2;
            //point 2 y value = the first points x value minus the square root of the length of the
            //new side squared minus one fourth the new side length squared
            dyTwo = vertices[index].position.y - sqrt(pow(sideLength,2) - pow(sideLength,2) / 4);

            //creates vertexes/points to later be put into vector
            tempOne = sf::Vector2f(dxOne, dyOne);
            tempTwo = sf::Vector2f(dxTwo, dyTwo);
            tempThree = sf::Vector2f(dxThree, dyThree);
        }
    }

    //Pushes the temporary vertices in a vector
    smallTemp.push_back(tempOne);
    smallTemp.push_back(tempTwo);
    smallTemp.push_back(tempThree);

    //The vector used is pushed into a vector of vectors
    temp.push_back(smallTemp);
}




void KochSnowflake::recurseSnowflake(int counter){

    //Base Case
    if(counter == degree){
        return;
    }


    //Change length of side to be 1/3 the original size
    sideLength = sideLength/3;
    //int to store size of the vector
    unsigned long int vectSize = vertices.size();

    //Loop to find all the points that need to be added
    for(int i = 0; i < vectSize - 1; i++){
        //Find the 3 points to make the new triangle in between each of the points
        getCorrectPoints(i);
    }

    //Put all values from temp into final vector
    //clears vector so it can rebuild it from scratch
    finalVector.clear();
    //Loop through and add a point from the original vector and the new three points in between
    //the point and its next point
    for(int i = 1; i < 4 * (vertices.size() - 1); i = i + 4){
        finalVector.insert(finalVector.begin() + i - 1, vertices[(i - 1) / 4]);
        finalVector.insert(finalVector.begin() + i, temp[(i - 1) / 4][0]);
        finalVector.insert(finalVector.begin() + i + 1, temp[(i - 1) / 4][1]);
        finalVector.insert(finalVector.begin() + i + 2, temp[(i - 1) / 4][2]);
    }
    //Inserts the original point again so that the window creates the last line to the original point
    finalVector.insert(finalVector.begin() + finalVector.size(), vertices[0]);
    
    //Clears the other two vectors
    temp.clear();
    vertices.clear();

    //Copys the new vector into the vector with the "old" points for the next iteration
    for(int i = 0; i < finalVector.size(); i++){
        vertices.push_back(finalVector[i]);
    }

    //Calls function again and increments the counter
    recurseSnowflake(counter + 1);
}


void KochSnowflake::firstSnowflake(){
    //Push back the first three points of the original triangle
    vertices.push_back(sf::Vector2f(width/2, height/4));
    vertices.push_back(sf::Vector2f(width/4, 3*height/4));
    vertices.push_back(sf::Vector2f(3*width/4, 3*height/4));
    vertices.push_back(sf::Vector2f(width/2, height/4));

    //If there is only one iteration it pushes all the values into the vector
    //used to display the values
    if(degree == 1){
        finalVector.push_back(sf::Vector2f(width/2, height/4));
        finalVector.push_back(sf::Vector2f(width/4, 3*height/4));
        finalVector.push_back(sf::Vector2f(3*width/4, 3*height/4));
        finalVector.push_back(sf::Vector2f(width/2, height/4));
    }

    //Calculates the length of each side of the triangle
    sideLength = vertices[2].position.x - vertices[1].position.x;


    //Check if degree is greater than one
        //Call recursive function
        if (degree > 1) {
        recurseSnowflake(1);
        }
}

void KochSnowflake::addColor(){
    //Loops through each value and adds color to them
    for(int i = 0;i < finalVector.size();i++){
        finalVector[i].color = color;
    }
}

void KochSnowflake::drawSnowflake(){
    //Checks to see if type mod 6 = 0, then prints out line strips
    if(type % 6 == 0){
        window->draw(&finalVector[0], finalVector.size(), sf::LineStrip);
    }
    //Checks to see if type mod 6 = 01, then prints out lines
    if(type % 6 == 1){
        window->draw(&finalVector[0], finalVector.size(), sf::Lines);
    }
    //Checks to see if type mod 6 = 2, then prints out line triangles
    if(type % 6 == 2){
        window->draw(&finalVector[0], finalVector.size(), sf::Triangles);
    }
    //Checks to see if type mod 6 = 3, then prints out triangle strips
    if(type % 6 == 3){
        window->draw(&finalVector[0], finalVector.size(), sf::TrianglesStrip);
    }
    //Checks to see if type mod 6 = 4, then prints out triangle fans
    if(type % 6 == 4){
        window->draw(&finalVector[0], finalVector.size(), sf::TrianglesFan);
    }
    //Checks to see if type mod 6 = 5, then prints out quads
    if(type % 6 == 5){
        window->draw(&finalVector[0], finalVector.size(), sf::Quads);
    }
}


void KochSnowflake::createSnowflake(){
    //Calls functions to create snowflake, add color, and display the snowflake
    firstSnowflake();
    addColor();
    drawSnowflake();
}

