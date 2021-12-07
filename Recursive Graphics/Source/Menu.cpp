//Class Implementation of the Main Menu
//Written by Mason Jacob

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
    font.loadFromFile("../Resources/Fonts/Ubuntu-Medium.ttf");
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
    subtitle.setFillColor(sf::Color::Cyan);
    subtitle.setPosition(10, 100);
    window.draw(subtitle);
    //set first line
    line1.setFont(font);
    line1.setString("----------------------------------------------------------------------------------------------------------------------");
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
    text1.setFillColor(sf::Color::Cyan);
    text1.setPosition(30, 250);
    window.draw(text1);
    //set text 2
    text2.setFont(font);
    text2.setString("0 - Return to this menu\n1 - Sierpinski's Triangle\n2 - Koch's Snowflake\n3 - Hilbert's Curve\n4 - Dragon's Curve\n\nS - Save an image of the window\nUp Arrow - Increase level of recursion\nDown Arrrow - Decrease level of recursion\n Right Arrow - Change Fractal Options (Forward)\nLeft Arrow - Change Fractal Options (Back)");
    text2.setCharacterSize(25);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(30, 300);
    window.draw(text2);
    //set heading 2
    heading2.setFont(font);
    heading2.setString("These keys will change the starting color of the fractal:");
    heading2.setCharacterSize(25);
    heading2.setFillColor(sf::Color::Cyan);
    heading2.setPosition(30, 650);
    window.draw(heading2);
    //set text 3
    text3.setFont(font);
    text3.setString("R - Red");
    text3.setCharacterSize(25);
    text3.setFillColor(sf::Color::Red);
    text3.setPosition(30, 700);
    window.draw(text3);
    //set text 4
    text4.setFont(font);
    text4.setString("B - Blue");
    text4.setCharacterSize(25);
    text4.setFillColor(sf::Color::Blue);
    text4.setPosition(30, 730);
    window.draw(text4);
    //set text 5
    text5.setFont(font);
    text5.setString("G - Green");
    text5.setCharacterSize(25);
    text5.setFillColor(sf::Color::Green);
    text5.setPosition(30, 760);
    window.draw(text5);
    //set text 6
    text6.setFont(font);
    text6.setString("Y - Yellow");
    text6.setCharacterSize(25);
    text6.setFillColor(sf::Color::Yellow);
    text6.setPosition(30, 790);
    window.draw(text6);
    //set text 7
    text7.setFont(font);
    text7.setString("W - White");
    text7.setCharacterSize(25);
    text7.setFillColor(sf::Color::White);
    text7.setPosition(30, 820);
    window.draw(text7);
    //set text 8
    text8.setFont(font);
    text8.setString("M - Magenta");
    text8.setCharacterSize(25);
    text8.setFillColor(sf::Color::Magenta);
    text8.setPosition(30, 850);
    window.draw(text8);
    //set text 9
    text9.setFont(font);
    text9.setString("C - Cyan");
    text9.setCharacterSize(25);
    text9.setFillColor(sf::Color::Cyan);
    text9.setPosition(30, 880);
    window.draw(text9);
    //set line 2
    line2.setFont(font);
    line2.setString("----------------------------------------------------------------------------------------------------------------------");
    line2.setCharacterSize(30);
    line2.setFillColor(sf::Color::White);
    line2.setPosition(10, 950);
    window.draw(line2);
}
