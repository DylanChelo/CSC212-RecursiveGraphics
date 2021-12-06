#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

class mainMenu {
    private:
    sf::Font font;
    sf::Text title;
    sf::Text subtitle;
    sf::Text heading1;
    sf::Text heading2;
    sf::Text text1;
    sf::Text text2;
    sf::Text line1;
    sf::Text line2;

    public:
    mainMenu();
    ~mainMenu();
    void generateMenu(sf::RenderWindow & window);
};