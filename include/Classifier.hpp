#include "./KNNAlgo.hpp"
#include "DataHandler.hpp"
#include <iostream>

namespace Classifier{

    double Accuracy = 0;

    void Train(DataHandler& dh, int EPOCH=10){
      double correct = 0;
      double total = 100;

      for (int i = 0; i < total; i++) {
        Eigen::Matrix<int, Image::rows, Image::cols> test_img =
            dh.get_Image_Data()[i].getPixelData();

        int guess =
            KNNAlgo::Classify(dh.get_Image_Data(), test_img, 10, KNNAlgo::mode);

        if (guess == dh.get_Image_Data()[i].getLabel())
          correct++;
        std::cout << i << "\n";
      }

      Accuracy = correct/total * 100;

      std::cout << (correct / total * 100) << "\n";
    }


};
