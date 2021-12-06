#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>



//KoshSnowflake.h
class KochSnowflake{
private:
    std::vector<sf::Vertex> vertices;
    std::vector<std::vector<sf::Vertex> > temp;
    std::vector<sf::Vertex> finalVector;
    int degree, width, height;
    double sideLength;
    sf::RenderWindow* window;
    void recurseSnowflake(int degree);
    void getCorrectPoints(int index);
    void firstSnowflake();
    void drawSnowflake();

public:
    KochSnowflake(int degree, sf::RenderWindow* window);
    void createSnowflake();

};










//KoshSnowflake.cpp
KochSnowflake::KochSnowflake(int degree, sf::RenderWindow* window){
    this->degree = degree;
    this->window = window;
}


void KochSnowflake::getCorrectPoints(int index){
    
    std::vector<sf::Vertex> smallTemp;

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

    double slope = (vertices[index].position.y - vertices[index + 1].position.y)/(vertices[index].position.x - vertices[index + 1].position.x);

    if(slope < 0){
        x = vertices[index].position.x - vertices[index+ 1].position.x;
        
        dxOne = std::abs(vertices[index].position.x - (x / 3));

        dxThree = std::abs(vertices[index].position.x - (2 * x / 3));
        
        dyOne =std::abs(vertices[index + 1].position.y - (4 * x / 3));

        dyThree = std::abs(vertices[index + 1].position.y - (2 * x / 3));

        dxTwo = vertices[index + 1].position.x;
        
        dyTwo = dyOne;

        tempOne = sf::Vector2f(dxOne, dyOne);
        tempTwo = sf::Vector2f(dxTwo, dyTwo);
        tempThree = sf::Vector2f(dxThree, dyThree);
    }
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

    int vectSize = vertices.size();

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
    width = 1000;
    height = 1000;
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
    if (degree > 1){
        //Call recursive function
        recurseSnowflake(1);
    }
}


void KochSnowflake::drawSnowflake(){
    window->draw(&finalVector[0], finalVector.size(), sf::LineStrip);
}


void KochSnowflake::createSnowflake(){
    firstSnowflake();
    drawSnowflake();
}







int main()
{
    // create the window
    int height = 1000;
    int width = 1000;
    int n = 2;
    
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(event.type ==sf::Event::KeyPressed){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                n++;
                std::cout << n << "\n";
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && n != 0){
                n--;
                std::cout << n << "\n";
            }
        }
        // clear the window with black color
        window.clear();
        KochSnowflake snowflake = KochSnowflake(n, &window);
        snowflake.createSnowflake();
        // end the current frame
        window.display();
    }

    return 0;
}

