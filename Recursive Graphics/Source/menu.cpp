#include "../Headers/menu.hpp"

mainMenu::mainMenu() {

}

mainMenu::~mainMenu() {

}

void mainMenu::generateMenu(sf::RenderWindow & window) {
    font.loadFromFile("../Resources/Gihun.ttf");
    title.setFont(font);
    title.setString("Welcome to the Recursive Graphics Generator!\n");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setPosition(10, 40);
    subtitle.setFont(font);
    subtitle.setString("Created by Dylan Chelo, Mason Jacob, and Nick Powers");
    subtitle.setCharacterSize(25);
    subtitle.setFillColor(sf::Color::Magenta);
    subtitle.setPosition(10, 100);
    line1.setFont(font);
    line1.setString("-------------------------------------------------------------------");
    line1.setCharacterSize(30);
    line1.setFillColor(sf::Color::White);
    line1.setPosition(10, 150);
    heading1.setFont(font);
    heading1.setString("How to use this generator:");
    heading1.setCharacterSize(30);
    heading1.setFillColor(sf::Color::White);
    heading1.setStyle(sf::Text::Underlined);
    heading1.setPosition(10, 200);
    text1.setFont(font);
    text1.setString("Pressing the following keys on your keyboard will perform various actions:");
    text1.setCharacterSize(25);
    text1.setFillColor(sf::Color::Magenta);
    text1.setPosition(30, 250);
    text2.setFont(font);
    text2.setString("0 - Return to this menu\n1 - Sierpinski's Triangle\n2 - Hilbert's Curve\n2 - Koch's Snowflake\n3 - Hilbert's Dragon\n\nS - Save an image of the window");
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(30, 300);
    heading2.setFont(font);
    heading2.setString("These keys will change the starting color of the fractal:");
    heading2.setCharacterSize(25);
    heading2.setFillColor(sf::Color::Magenta);
    heading2.setPosition(30, 400);
    window.draw(title);
    window.draw(subtitle);
    window.draw(line1);
    window.draw(heading1);
    window.draw(text1);
    window.draw(text2);
    window.draw(heading2);
}