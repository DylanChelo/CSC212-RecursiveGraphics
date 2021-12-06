#include "../Headers/Menu.hpp"

//Default Constructor
mainMenu::mainMenu() {

}
//Default Destructor
mainMenu::~mainMenu() {

}
//Main menu generation function
void mainMenu::generateMenu(sf::RenderWindow & window) {
    //load font
    font.loadFromFile("../Resources/Fonts/Gihun.ttf");
    //set title
    title.setFont(font);
    title.setString("Welcome to the Recursive Graphics Generator!\n");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setPosition(10, 40);
    window.draw(title);
    //set subtitle
    subtitle.setFont(font);
    subtitle.setString("Created by Dylan Chelo, Mason Jacob, and Nick Powers");
    subtitle.setCharacterSize(25);
    subtitle.setFillColor(sf::Color::Magenta);
    subtitle.setPosition(10, 100);
    window.draw(subtitle);
    //set first line
    line1.setFont(font);
    line1.setString("-------------------------------------------------------------------");
    line1.setCharacterSize(30);
    line1.setFillColor(sf::Color::White);
    line1.setPosition(10, 150);
    window.draw(line1);
    //set heading 1
    heading1.setFont(font);
    heading1.setString("How to use this generator:");
    heading1.setCharacterSize(30);
    heading1.setFillColor(sf::Color::White);
    heading1.setStyle(sf::Text::Underlined);
    heading1.setPosition(10, 200);
    window.draw(heading1);
    //set text 1
    text1.setFont(font);
    text1.setString("Pressing the following keys on your keyboard will perform various actions:");
    text1.setCharacterSize(25);
    text1.setFillColor(sf::Color::Magenta);
    text1.setPosition(30, 250);
    window.draw(text1);
    //set text 2
    text2.setFont(font);
    text2.setString("0 - Return to this menu\n1 - Sierpinski's Triangle\n2 - Koch's Snowflake\n3 - Hilbert's Curve\n4 - Dragon's Curve\n\nS - Save an image of the window");
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(30, 300);
    window.draw(text2);
    //set heading 2
    heading2.setFont(font);
    heading2.setString("These keys will change the starting color of the fractal:");
    heading2.setCharacterSize(25);
    heading2.setFillColor(sf::Color::Magenta);
    heading2.setPosition(30, 600);
    window.draw(heading2);
    //set text 3
    text3.setFont(font);
    text3.setString("R - Red\nB - Blue\nG - Green\nY - Yellow\nW - White\nM - Magenta\nC - Cyan");
    text3.setCharacterSize(30);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(30, 650);
    window.draw(text3);
    //set line 2
    line2.setFont(font);
    line2.setString("-------------------------------------------------------------------");
    line2.setCharacterSize(30);
    line2.setFillColor(sf::Color::White);
    line2.setPosition(10, 900);
    window.draw(line2);
}