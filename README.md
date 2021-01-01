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
#include "../include/Classifier.hpp"

int main(){
    
    DataHandler dh;
    dh.prepareData(Image_File_Path,Label_file_Path);

    // For a single classification
    int guess = KNNAlgo::Classify(dh.get_Image_Data(),dh.get_Image_Data()[1].getPixelData(),10);

    // To train on a set of data
    Classifier::Train(dh,EPOCH=3);

    return 0;
}

```

## What I learned
- KNearest Neighbour Algorithm
- Parsing MNIST file
- Eigen Matrix Library
