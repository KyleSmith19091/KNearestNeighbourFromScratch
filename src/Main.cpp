#include "../include/DataHandler.hpp"
#include "../include/KNNAlgo.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

/*
    0000   32 bit int 2049 -> magic number
    0004   32 bit int 60000 -> number of items
    0008   unsigned byte -> label
    0009   unsigned byte -> label
    label value 0-9
* */

int main(){

    DataHandler dh;
    dh.prepareData("/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/train-images.idx3-ubyte", "/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/train-labels.idx1-ubyte",false);
    dh.prepareData("/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/t10k-images.idx3-ubyte", "/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/t10k-labels.idx1-ubyte",true);

    double count = 0;
    double iterNum = 10;

    for(int i = 0; i < iterNum; i++){
        bool eval = KNNAlgo::Classify(dh.get_Image_Data(), dh.get_Test_Image_Data()[i], 10);
        if(eval) count++;
    }

    cout << "Accuracy: " << (count/(iterNum)*100) << "\n";

    return 0;
}
