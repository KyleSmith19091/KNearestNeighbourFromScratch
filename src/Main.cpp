#include "../include/DataHandler.hpp"
#include "../include/KNNAlgo.hpp"
#include "../include/Classifier.hpp"
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
    dh.prepareData("/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/train-images.idx3-ubyte", "/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/train-labels.idx1-ubyte");
    Classifier::Train(dh);


    

    return 0;
}
