#include "../Headers/SierpinskiTriangle.hpp"

//Default Constructor
SierpinskiTriangle::SierpinskiTriangle() {

}

//Default Destructor
SierpinskiTriangle::~SierpinskiTriangle() {

}

//Setter for container to calculate where the triangle should go
void SierpinskiTriangle::setContainer(float x1, float y1, float x2, float y2) {
  container = sf::RectangleShape();
  container.setPosition(sf::Vector2f(x1, y1));
  container.setSize(sf::Vector2f(x2 - x1, y2 - y1));
}

//Setter for color
void SierpinskiTriangle::setColor(sf::Color color) {
  this->color = color;
}

void SierpinskiTriangle::generateSierpinskiTriangle(int w, int h, int iterations, sf::Color color, sf::RenderWindow & window) {
  setContainer(0, 0, w, h);
  setColor(color);
  sf::Vector2f bottomRightPoint = sf::Vector2f(container.getPosition().x + container.getSize().x, container.getPosition().y + container.getSize().y);
  sf::Vector2f topLeftPoint = sf::Vector2f(container.getPosition());
  sf::Vector2f topTrianglePoint = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, topLeftPoint.y);
  sf::Vector2f leftTrianglePoint = sf::Vector2f(topLeftPoint.x, bottomRightPoint.y);
  sf::Vector2f rightTrianglePoint = sf::Vector2f(bottomRightPoint.x, bottomRightPoint.y);
  drawSierpinskiTriangle(topTrianglePoint, leftTrianglePoint, rightTrianglePoint, iterations, window);
}

void SierpinskiTriangle::drawSierpinskiTriangle(sf::Vector2f &topTrianglePoint, sf::Vector2f &leftTrianglePoint, sf::Vector2f &rightTrianglePoint, int iteration, sf::RenderWindow &window) {
  sf::Color temp = color;
  int colorR = color.r;
  int colorG = color.g;
  int colorB = color.b;
  

  if(iteration == 0) {
    drawTriangle(topTrianglePoint, leftTrianglePoint, rightTrianglePoint, color, window);
    return;
  }
  sf::Vector2f midLeft = sf::Vector2f((leftTrianglePoint.x + topTrianglePoint.x)/2.0, (leftTrianglePoint.y+topTrianglePoint.y)/2.0);
  sf::Vector2f midRight = sf::Vector2f((rightTrianglePoint.x + topTrianglePoint.x)/2.0, (rightTrianglePoint.y + topTrianglePoint.y)/2.0);
  sf::Vector2f midBottom = sf::Vector2f((leftTrianglePoint.x+rightTrianglePoint.x)/2.0, (leftTrianglePoint.y+rightTrianglePoint.y)/2.0);
  if(iteration == 1) {
      color = sf::Color(colorR * midBottom.y/container.getSize().y, colorG * midBottom.y/container.getSize().y, colorB * midBottom.y/container.getSize().y);
      drawTriangle(topTrianglePoint, midLeft, midRight, color, window);
      color = sf::Color(colorR * midLeft.y/container.getSize().y, colorG * midLeft.y/container.getSize().y, colorB * midLeft.y/container.getSize().y);
      drawTriangle(midLeft, leftTrianglePoint, midBottom, color, window);
      color = sf::Color(colorR * midRight.y/container.getSize().y, colorG * midRight.y/container.getSize().y, colorB * midRight.y/container.getSize().y);
      drawTriangle(midRight, midBottom, rightTrianglePoint, color, window);
      color = temp;
  } else {
      drawSierpinskiTriangle(topTrianglePoint, midLeft, midRight, iteration-1, window);
      drawSierpinskiTriangle(midLeft, leftTrianglePoint, midBottom, iteration-1, window);
      drawSierpinskiTriangle(midRight, midBottom, rightTrianglePoint, iteration-1, window);
  }
}

void SierpinskiTriangle::drawTriangle(sf::Vector2f &topTrianglePoint, sf::Vector2f &leftTrianglePoint, sf::Vector2f &rightTrianglePoint, sf::Color &color, sf::RenderWindow &window) {
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, topTrianglePoint);
  triangle.setPoint(1, leftTrianglePoint);
  triangle.setPoint(2, rightTrianglePoint);
  triangle.setFillColor(color);
  window.draw(triangle);
}







 