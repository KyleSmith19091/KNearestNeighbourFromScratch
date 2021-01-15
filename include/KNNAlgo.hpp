#include <vector>
#include <iostream>
#include "../include/Image.hpp"
#ifndef KNNALGO
#define KNNALGO

class KNNAlgo{

    private:
        static int mode(std::vector<int>);
        static void euc_distance(std::vector<std::pair<int, int>>&, std::vector<Image>, Image);

    public:
        KNNAlgo(){};
        ~KNNAlgo(){};
        bool Classify(std::vector<Image>, Image, int=10, int (*choice_func)(std::vector<int>)=mode, void (*dist_func)(std::vector<std::pair<int,int>>&, std::vector<Image>, Image)=euc_distance);

};
#endif
