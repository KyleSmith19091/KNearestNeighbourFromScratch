#include <vector>
#include <eigen/3.3.8_1/include/eigen3/Eigen/Core>

#ifndef IMAGE_H
#define IMAGE_H

class Image{

    public:
        static const int rows = 28;
        static const int cols = 28;

        Image(std::vector<std::vector<unsigned char>>,unsigned char);
        Image();
        ~Image();
        Eigen::Matrix<int,rows,cols> getPixelData() const;
        int getLabel() const;

    private:
        Eigen::Matrix<int,rows,cols> pixels;
        int label;

};	

#endif
