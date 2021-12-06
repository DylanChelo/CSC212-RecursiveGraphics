#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>


class fractal {
    private:
        std::vector<std::vector<std::string>> image;
        int imageX;
        int imageY;
        int triangleH;
        int numRecursion;

    public:
        fractal();
        ~fractal(); 
        std::vector<std::vector<std::string>>* getImage();
        void initializeImage(int x, int y, std::string color);
        int fractalGen();
        void triangleGen();

};