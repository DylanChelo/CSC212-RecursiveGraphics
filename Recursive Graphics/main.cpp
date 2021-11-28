#include "fractal.hpp"

void ReadFile(std::string file_name, std::vector<std::vector<int>> * imageData) {
    std::ifstream file(file_name);
    std::string str;
    while (std::getline(file,str)) {
        std::vector<int> newRow;
        std::stringstream stringStream(str);
        int temp;
        while(stringStream>>temp) {
            newRow.push_back(temp);
        }
        imageData->push_back(newRow);
    }
}

void WriteFile(std::string fileName, std::vector<std::vector<int>> * imageData) {
    std::ofstream outputFile(fileName);
    for(unsigned int i = 0; i < imageData->size(); i++) {
        for (unsigned int j = 0; j < (*imageData)[i].size(); j++) {
            outputFile << (*imageData)[i][j] << " ";
        }
        outputFile << "\n";
    }
}

int main(int argc, char**argv) {
    std::string x = argv[1];
    std::string y = argv[2];
    std::string color = argv[3];
    std::string outputFile = argv[4];
    fractal test;
    test.initializeImage(std::stoi(x), std::stoi(y), std::stoi(color));
    WriteFile(outputFile, &(test.getImage()));
}
    