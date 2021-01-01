#include <vector>
#include <iostream>
#include "../include/Image.hpp"
#ifndef KNNALGO
#define KNNALGO

namespace KNNAlgo{

    inline int mode(std::vector<int> v) {

      int maxCount = 1;
      int mode = v[0];

      for_each(v.begin(), v.end(), [&](int i) {
        int d = std::count(v.begin(), v.end(), i);
        if (d > maxCount) {
          maxCount = d;
          mode = i;
        }
      });
      return mode;
    }

    inline int Classify(std::vector<Image> data, Eigen::Matrix<int,Image::rows,Image::cols> query, int k, int (*choice_func)(std::vector<int>)=mode){
       
      if(k==0){
        std::cout << "Please choose valid k value\n";
      }

      if(data.size()==0){
        std::cout << "Please provide a valid Image vector\n";
      }
    
      std::vector<std::pair<int, int>> dist_and_k;

      for (int i = 0; i < data.size(); i++) {
        dist_and_k.push_back(std::make_pair(
            (data[i].getPixelData() - query).array().pow(2).sum(),
            data[i].getLabel()));
      }

      sort(dist_and_k.begin(), dist_and_k.end(),
           [](std::pair<int, int> p, std::pair<int, int> p2) {
             return p.first < p2.first;
           });

      std::vector<int> k_labels(k);

      for (int i = 0; i < k; i++) {
        k_labels[i] = dist_and_k[i].second;
      }

      return choice_func(k_labels);
    }
};
#endif
