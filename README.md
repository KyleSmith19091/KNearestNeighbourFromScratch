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
    // False to specify that it is training dataset
    dh.prepareData("path_image_file", "path_label_file",false);
    // True to indicate that data is test dataset
    dh.prepareData("path_image_file_test", "path_label_file_test",true);

    double count = 0;
    double iterNum = 10;
    KNNAlgo knn;

    for(int i = 0; i < iterNum; i++){
        bool eval = knn.Classify(dh.get_Image_Data(), dh.get_Test_Image_Data()[i]);
        if(eval) count++;
    }

    cout << "Accuracy: " << (count/iterNum*100) << "%\n";

    return 0;
}

```

## What I learned
- KNearest Neighbour Algorithm
- Parsing MNIST file
- Eigen Matrix Library
