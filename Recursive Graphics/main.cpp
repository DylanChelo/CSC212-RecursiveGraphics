#include "Headers/SierpinskiTriangle.hpp"
//#include "Header/SierpinskiCarpet.hpp"
//#include "Header/CirclePattern.hpp"
//#include "Header/KochSnowflake.hpp"
//#include "Header/TreeFractal.hpp"
//#include "Header/Mandelbrot.hpp"

int main(int argc, char**argv) {
    if (argc != 5) {
        std::cout << "Usage: ./RecursiveGenerator\n";
        std::cout << "\t<fractal type>\t1. Sierpinski's Triangle: 'ST'\n\t\t\t\t2. Koch's Snowflake: 'KS'\n\t\t\t\t3. Hilbert's Curve: 'HC'\n";
        std::cout << "\t<iterations>\tdesired number of iterations\n";
        std::cout << "\t<color>\tdesired color\n";
        std::cout << "\t<fname>\tfile name to save image of graphic\n";
        return 0;
    } else {
        int width = 1000;
        int height = 1000;
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;
        sf::RenderWindow window(sf::VideoMode(width, height), "Serpinski's Triangle", sf::Style::Default, settings);
        window.setFramerateLimit(60);
        int i = std::stoi(argv[2]);

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
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        i++;
                        std::cout << i << std::endl;
                    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        i--;
                        std::cout << i << std::endl;
                    }
                }
            }
        window.clear();
        SierpinskiTriangle ST;
        ST.generateSierpinskiTriangle(width, height, i, sf::Color::Red, window);
        window.display();
        }
        return 0;
    }
}