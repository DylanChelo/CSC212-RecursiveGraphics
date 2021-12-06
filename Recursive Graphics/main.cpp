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
    //SFML Basic Window Initialization Code
    std::string windowTitle = "Recursive Graphics Generator";
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(width, height), windowTitle, sf::Style::Default, settings);
    window.setFramerateLimit(60);
    //Variable to set level of recursion
    int iterations = 0;
    //Variable to track selected fractal type; 1: Sierpinski's Triangle, 2: Koch's Snowflake, 3: Hilbert's Curve
    int windowSelection = 0;
    //Variable to hold starting color
    sf::Color startColor = sf::Color::White;

    //main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                    windowSelection = 0;
                    std::cout<<"Main Menu"<<std::endl;
                    windowTitle = "Recursive Graphics Generator";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    windowSelection = 1;
                    std::cout<<"Fractal Selection: Sierpinski's Triangle"<<std::endl;
                    windowTitle = "Sierpinski's Triangle";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                    windowSelection = 2;
                    std::cout<<"Fractal Selection: Koch's Snowflake"<<std::endl;
                    windowTitle = "Koch's Snowflake";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                    windowSelection = 3;
                    std::cout<<"Fractal Selection: Hilbert's Curve"<<std::endl;
                    windowTitle = "Hilbert's Curve";
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    iterations++;
                    std::cout << "Current Level of Recursion: "<< iterations << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    iterations--;
                    std::cout << "Current Level of Recursion: "<< iterations << std::endl;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                    startColor = sf::Color::Blue;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    startColor = sf::Color::Red;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                    startColor = sf::Color::Green;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    sf::Texture texture;
                    texture.create(width, height);
                    texture.update(window);
                    if (texture.copyToImage().saveToFile(filename)) {
                        std::cout << "screenshot saved to " << filename << std::endl;
                    }       
                }
            }
        }
    window.clear();
    if (windowSelection == 0) {
        mainMenu mm;
        mm.generateMenu(window);
    } else if (windowSelection == 1) {
        SierpinskiTriangle ST;
        ST.generateSierpinskiTriangle(width, height, iterations, startColor, window);
    } else if (windowSelection == 2) {

    } else if (windowSelection == 3) {

    } 
    
    window.display();
    }
    window.~RenderWindow();
    return 0;
}
