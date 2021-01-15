# KNearest Neighbour Algorithm
This is an implementation of the KNearest Neighbour algorithm in C++, this repo reads data from the MNIST dataset.
I added a MNIST file parser to read image data and labels. The image data is wrapped in an Image object where the pixel
data is stored in a Eigen Matrix to allow for effiecent calculation of the euclidian distance when using the algorithm.

**Caution this project is dependent on the Eigen Library**

Type make to create the executable binary and to run the program
```bash
$ make
```

Example Main.cpp
```c++

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

```

## What I learned
- KNearest Neighbour Algorithm
- Parsing MNIST file
- Eigen Matrix Library
