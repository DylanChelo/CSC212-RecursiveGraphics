#include "Headers/SierpinskiTriangle.hpp"
//#include "Header/SierpinskiCarpet.hpp"
//#include "Header/CirclePattern.hpp"
//#include "Header/KochSnowflake.hpp"
//#include "Header/TreeFractal.hpp"
//#include "Header/Mandelbrot.hpp"

std::vector<sf::Color> storeColors(std::vector<std::string> & colorVector);

int main(int argc, char**argv) {
    
    if (argc != 5) {
        std::cout << "Usage: ./RecursiveGenerator\n";
        std::cout << "\t<fractal type>\t\t\t1. Sierpinski's Triangle: 'ST'\n\t\t\t\t\t2. Koch's Snowflake: 'KS'\n\t\t\t\t\t3. Hilbert's Curve: 'HC'\n";
        std::cout << "\t<iterations>\t\t\tDesired number of iterations\n";
        std::cout << "\t<width,height>\t\t\tThe desired width and height of the window/image, seperated by a comma with no spaces\n";
        std::cout << "\t<color1,color2,color3,color4>\tList of colors for fractal, seperated by commas with no spaces, can list up to four\n\t\t\t\t\tColor Options: Black, White, Red, Blue, Green, Yellow, Magenta, Cyan\n";
        std::cout << "\t<fname>\t\t\t\tFile name to save image of graphic\n";
        return 0;
    } else {
        //Standard SFML float vector to store width and height
        sf::Vector2f WH;
        std::string temp;
        std::stringstream ss(argv[3]);
        int counter = 0;
        while(std::getline(ss, temp, ',')) {
            if (!counter) {
                WH.x = std::stoi(temp);
            } else {
                WH.y = std::stoi(temp);
            }
            counter++;
        }
        //String vector to store color selections
        std::vector<std::string> colorVector;
        std::stringstream ss2(argv[4]);
        while(std::getline(ss2, temp, ',')) {
        colorVector.push_back(temp);
        }
        std::vector<sf::Color> colors = storeColors(colorVector);
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;
        sf::RenderWindow window(sf::VideoMode(WH.x, WH.y), "Serpinski's Triangle", sf::Style::Default, settings);
        window.setFramerateLimit(60);
        int iteration = std::stoi(argv[2]);

        //main loop

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                /*if (event.type == sf::Event::KeyPressed) {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        window.close();
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        iteration++;
                        std::cout << "Current Level of Recursion: "<< iteration << std::endl;
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        iteration--;
                        std::cout << "Current Level of Recursion: "<< iteration << std::endl;
                    }
                }*/
            }
        window.clear();
        SierpinskiTriangle ST;
        ST.generateSierpinskiTriangle(WH.x, WH.y, iteration, colors, window);
        window.display();
        }
        return 0;
    }
}

//Conversion function to convert colors from string to native color type in SFML, Colors Options: Black, White, Red, Blue, Green, Yellow, Magenta, Cyan
std::vector<sf::Color> storeColors(std::vector<std::string>& colorVector) {
    std::vector<sf::Color> colorVec;
    for (int i = 0; i < colorVector.size(); i++) {
        if (!(colorVector[i].compare("Black"))) {
            colorVec.push_back(sf::Color::Black);
        } else if (!(colorVector[i].compare("White"))) {
            colorVec.push_back(sf::Color::White);
        } else if (!(colorVector[i].compare("Red"))) {
            colorVec.push_back(sf::Color::Red);
        } else if (!(colorVector[i].compare("Blue"))) {
            colorVec.push_back(sf::Color::Blue);
        } else if (!(colorVector[i].compare("Green"))) {
            colorVec.push_back(sf::Color::Green);
        } else if (!(colorVector[i].compare("Yellow"))) {
            colorVec.push_back(sf::Color::Yellow);
        } else if (!(colorVector[i].compare("Magenta"))) {
            colorVec.push_back(sf::Color::Magenta);
        } else if (!(colorVector[i].compare("Cyan"))) {
            colorVec.push_back(sf::Color::Cyan);
        } else {
            std::cout<<colorVector[i]<<" is not a Valid Color."<<std::endl;
        }
    }
    return colorVec;
}