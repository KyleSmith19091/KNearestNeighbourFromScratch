#include "../include/Image.hpp"
#include <vector>

Image::Image(){}

Image::Image(std::vector<std::vector<unsigned char>> pixels, unsigned char label){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->pixels(i,j) = pixels[i][j];
        }
    }
    this->label = (int)label;
}

Image::~Image(){}

Eigen::Matrix<int,28,28> Image::getPixelData() const{
    return this->pixels;
}

int Image::getLabel() const{
    return this->label;
}
