#include "Headers/menu.hpp"
#include "Headers/SierpinskiTriangle.hpp"
//#include "Header/SierpinskiCarpet.hpp"
//#include "Header/CirclePattern.hpp"
//#include "Header/KochSnowflake.hpp"
//#include "Header/TreeFractal.hpp"
//#include "Header/Mandelbrot.hpp"

int main(int argc, char**argv) {
    std::string filename = argv[1];
    //Width and Height of Window/Image
    int width = 1000;
    int height = 1000;
    //Variable to set level of recursion
    int iterations = 0;
    //Variable to track selected fractal type; 1: Sierpinski's Triangle, 2: Koch's Snowflake, 3: Hilbert's Curve
    int windowSelection = 0;
    //Variable to hold starting color
    sf::Color startColor = sf::Color::White;

    //SFML Basic Window Initialization Code
    std::string windowTitle = "Recursive Graphics Generator";
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(width, height), windowTitle, sf::Style::Default, settings);
    window.setFramerateLimit(60);
    
    //main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            //Checker to close window when program ends
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //Checks if a key is pressed
            if (event.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    //If escape key is pressed, close window
                    window.close();
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                    // if 0 is pressed, set window to main menu
                    windowSelection = 0;
                    std::cout<<"Main Menu"<<std::endl;
                    windowTitle = "Recursive Graphics Generator";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    //if 1 if pressed, set window to Sierpinki's Triangle
                    windowSelection = 1;
                    std::cout<<"Fractal Selection: Sierpinski's Triangle"<<std::endl;
                    windowTitle = "Sierpinski's Triangle";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                    //if 2 is pressed, set window to Koch's Snowflake
                    windowSelection = 2;
                    std::cout<<"Fractal Selection: Koch's Snowflake"<<std::endl;
                    windowTitle = "Koch's Snowflake";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                    //if 3 is pressed, set window to Hilbert's Curve
                    windowSelection = 3;
                    std::cout<<"Fractal Selection: Hilbert's Curve"<<std::endl;
                    windowTitle = "Hilbert's Curve";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                    //if 4 is pressed, set window to Dragon's Curve
                    windowSelection = 4;
                    std::cout<<"Fractal Selection: Dragon's Curve"<<std::endl;
                    windowTitle = "Dragon's Curve";
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    //if up arrow is pressed, increase level of recursion
                    iterations++;
                    std::cout << "Current Level of Recursion: "<< iterations << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    //if down arrow is pressed, decrease level of recursion
                    if (iterations > 0) {
                    iterations--;   
                    std::cout << "Current Level of Recursion: "<< iterations << std::endl;
                    }
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                    //Set starting color to Blue
                    startColor = sf::Color::Blue;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    //Set starting color to Red
                    startColor = sf::Color::Red;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                    //Set starting color to Green
                    startColor = sf::Color::Green;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    //Set starting color to Yellow
                    startColor = sf::Color::Yellow;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    //Set starting color to Cyan
                    startColor = sf::Color::Cyan;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    //Set starting color to Magenta
                    startColor = sf::Color::Magenta;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    //Set starting color to White
                    startColor = sf::Color::White;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    //If S key is pressed, save the file to the inputed file name from the command line
                    sf::Texture texture;
                    texture.create(width, height);
                    texture.update(window);
                    if (texture.copyToImage().saveToFile(filename)) {
                        std::cout << "screenshot saved to " << filename << std::endl;
                    }       
                }
            }
        }
    //clear window
    window.clear();
    if (windowSelection == 0) {
        //set window to main menu
        mainMenu mm;
        mm.generateMenu(window);
    } else if (windowSelection == 1) {
        //set window to sierpinski's triangle
        SierpinskiTriangle ST;
        ST.generateSierpinskiTriangle(width, height, iterations, startColor, window);
    } else if (windowSelection == 2) {
        //set window to koch's snowflake
        
    } else if (windowSelection == 3) {
        //set window to hilbert's curve

    } else if (windowSelection == 4) {
        //set window to dragon's curve

    } 
    //Display window
    window.display();
    }
    //Deconstruct window
    window.~RenderWindow();
    return 0;
}
