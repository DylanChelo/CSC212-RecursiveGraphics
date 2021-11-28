#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>


class fractal {
    private:
        std::vector<std::vector<int>> image;
        int imageX;
        int imageY;
        int triangleH;
        int numRecursion;

    public:
        fractal();
        ~fractal(); 
        std::vector<std::vector<int>> getImage();
        void initializeImage(int x, int y, int color);
        int fractalGen();
        void triangleGen();

};