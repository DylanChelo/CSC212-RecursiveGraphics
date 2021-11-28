#include "fractal.hpp"

fractal::fractal() {

}

fractal::~fractal() {

}

void fractal::initializeImage(int x, int y, int color) {
    for (int i = 0; i < x; i++) {
        std::vector<int> newRow;
        for (int j = 0; j < y; j++) {
            newRow.push_back(color);
        }
        this->image.push_back(newRow);
    }
}

std::vector<std::vector<int>> fractal::getImage(){
            return image;
        }

int fractal::fractalGen() {
    
    return 0;
}

fractal::triangleGen(int startX, int)