#include "../include/DataHandler.hpp"
#include "../include/KNNAlgo.hpp"
#include <iostream>

using namespace std;

int main(){

    DataHandler dh;
    dh.prepareData("/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/train-images.idx3-ubyte", "/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/train-labels.idx1-ubyte",false);
    dh.prepareData("/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/t10k-images.idx3-ubyte", "/Users/kylesmith/Development/C++_Code_Projects/MachineLearning/KNearestNeighbour/res/t10k-labels.idx1-ubyte",true);

    double count = 0;
    double iterNum = 10;
    KNNAlgo knn;

    for(int i = 0; i < iterNum; i++){
        bool eval = knn.Classify(dh.get_Image_Data(), dh.get_Test_Image_Data()[i]);
        if(eval) count++;
    }

    cout << count << "\n";
    cout << "Accuracy: " << (count/iterNum) << "\n";

    return 0;
}
