#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>



//KoshSnowflake.h
class KochSnowflake{
private:
    std::vector<sf::Vertex> vertices;
    std::vector<std::vector<sf::Vertex> > temp;
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

    double slope = (vertices[index].position.y - vertices[index + 1].position.y)/(vertices[index].position.x - vertices[index + 1].position.x);

    if(slope < 0){
        dxOne = vertices[index].position.x - vertices[index + 1].position.x;
        dxOne = dxOne / 3;

        dxThree = vertices[index].position.x - vertices[index + 1].position.x;
        dxThree = dxThree / 3;
        dxThree = 2 * dxThree;

        dyOne = vertices[index + 1].position.y - vertices[index].position.y;
        dyOne = dyOne / 3;

        dyThree = vertices[index + 1].position.y - vertices[index].position.y;
        dyThree = dyThree / 3;
        dyThree = 2 * dyThree; 

        dxTwo = vertices[index].position.y;

        dyTwo = tempOne.position.y + dyThree;
        dyTwo = dyTwo / 2;

        std::cout << "IF:   " << "\n";
        std::cout << "DX1:  " << dxOne << "\n";
        std::cout << "DX2:  " << dxTwo << "\n";
        std::cout << "DX3:  " << dxThree << "\n";
        std::cout << "DY1:  " << dyOne << "\n";
        std::cout << "DY2:  " << dyTwo << "\n";
        std::cout << "DY3:  " << dyThree << "\n";
        tempOne = sf::Vector2f(dxOne, dyOne);
        tempTwo = sf::Vector2f(dxTwo, dyTwo);
        tempThree = sf::Vector2f(dxThree, dyThree);
        std::cout << "DXONE:  " << tempOne.position.x << "\n";
        std::cout << "DXTWO:  " << tempTwo.position.x << "\n";
        std::cout << "DXThree:  " << tempThree.position.x << "\n";
        std::cout << "DYONE:  " << tempOne.position.y << "\n";
        std::cout << "DYTWO:  " << tempTwo.position.y << "\n";
        std::cout << "DYThree:  " << tempThree.position.y << "\n" << "\n";
    }
    else if (slope > 0){
        double x = vertices[index].position.x - vertices[index + 1].position.x;

        dxOne = std::abs(vertices[index + 1].position.x + (2/3)*x);

        dxThree = std::abs(vertices[index + 1].position.x + (1/3)*x);

        dyOne = std::abs(vertices[index].position.y - (2/3)*x);

        dyThree = std::abs(vertices[index].position.y - (4/3)*x);

        dxTwo = vertices[index].position.y;

        dyTwo = std::abs(vertices[index].position.x);
        dyTwo = std::abs(tempOne.position.y);

        std::cout << "ELSE IF:   " << "\n";
        std::cout << "DX1:  " << dxOne << "\n";
        std::cout << "DX2:  " << dxTwo << "\n";
        std::cout << "DX3:  " << dxThree << "\n";
        std::cout << "DY1:  " << dyOne << "\n";
        std::cout << "DY2:  " << dyTwo << "\n";
        std::cout << "DY3:  " << dyThree << "\n";
        tempOne = sf::Vector2f(dxOne, dyOne);
        tempTwo = sf::Vector2f(dxTwo, dyTwo);
        tempThree = sf::Vector2f(dxThree, dyThree);
        std::cout << "DXONE:  " << tempOne.position.x << "\n";
        std::cout << "DXTWO:  " << tempTwo.position.x << "\n";
        std::cout << "DXThree:  " << tempThree.position.x << "\n";
        std::cout << "DYONE:  " << tempOne.position.y << "\n";
        std::cout << "DYTWO:  " << tempTwo.position.y << "\n";
        std::cout << "DYThree:  " << tempThree.position.y << "\n" << "\n";
    }
    else{
        dxOne = vertices[index + 1].position.x - vertices[index].position.x;
        dxOne = dxOne / 3;

        dxThree = vertices[index + 1].position.x - vertices[index].position.x;
        dxThree = dxThree / 3;
        dxThree = 2 * dxThree;

        dyOne = vertices[index + 1].position.y - vertices[index].position.y;
        dyOne = dyOne / 3;

        dyThree = vertices[index + 1].position.y - vertices[index].position.y;
        dyThree = dyThree / 3;
        dyThree = 2 * dyThree;

        dxTwo = std::abs(dxOne + dxThree);
        dxTwo = dxTwo / 2;

        dyTwo = vertices[index].position.y;
        std::cout << "ELSE:   " << "\n";
        std::cout << "DX1:  " << dxOne << "\n";
        std::cout << "DX2:  " << dxTwo << "\n";
        std::cout << "DX3:  " << dxThree << "\n";
        std::cout << "DY1:  " << dyOne << "\n";
        std::cout << "DY2:  " << dyTwo << "\n";
        std::cout << "DY3:  " << dyThree << "\n";
        tempOne = sf::Vector2f(dxOne, dyOne);
        tempTwo = sf::Vector2f(dxTwo, dyTwo);
        tempThree = sf::Vector2f(dxThree, dyThree);
        std::cout << "DXONE:  " << tempOne.position.x << "\n";
        std::cout << "DXTWO:  " << tempTwo.position.x << "\n";
        std::cout << "DXThree:  " << tempThree.position.x << "\n";
        std::cout << "DYONE:  " << tempOne.position.y << "\n";
        std::cout << "DYTWO:  " << tempTwo.position.y << "\n";
        std::cout << "DYThree:  " << tempThree.position.y << "\n" << "\n";
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

    
    std::cout << "START" << "\n";
    for(int i = 0; i < vertices.size(); i++){
        std::cout << vertices[i].position.x << "   " << vertices[i].position.y << "\n";
    }
    
    
    std::cout << "START TEMP" << "\n" << "\n";
    for(int i = 0; i < 3*temp.size(); i = i + 3){
        std::cout << temp[i/3][i].position.x << "   " << temp[i/3][i].position.y << "\n";
        std::cout << temp[i/3][i + 1].position.x << "   " << temp[i/3][i + 1].position.y << "\n";
        std::cout << temp[i/3][i + 2].position.x << "   " << temp[i/3][i + 2].position.y << "\n" << "\n";
    }


    //Put all values from temp into vector
    int tempSize = temp.size();
    int currentIndex = 1;
    
    for(int i = 0; i < tempSize; i++){
        currentIndex = currentIndex + i;
        vertices.insert(vertices.begin() + currentIndex, temp[currentIndex][currentIndex]);
        currentIndex = currentIndex + 1;
        vertices.insert(vertices.begin() + currentIndex, temp[currentIndex][currentIndex]);
        currentIndex = currentIndex + 1;
        vertices.insert(vertices.begin() + currentIndex, temp[currentIndex][currentIndex]);
    }

    /*
    std::cout << "AFTER" << "\n";
    for(int i = 0; i < vertices.size(); i++){
        std::cout << vertices[i].position.x << "   " << vertices[i].position.y << "\n";
    }
    std::cout << "END" << "\n";
    */

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


    sideLength = vertices[2].position.x - vertices[1].position.x;


    //Check if degree is greater than one
    if (degree > 1){
        //Call recursive function
        recurseSnowflake(1);
    }
}


void KochSnowflake::drawSnowflake(){
    window->draw(&vertices[0], vertices.size(), sf::LineStrip);
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

