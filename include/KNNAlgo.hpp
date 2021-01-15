#include <vector>
#include <iostream>
#include "../include/Image.hpp"
#ifndef KNNALGO
#define KNNALGO

class KNNAlgo{

    private:
        static std::vector<Image> data;       
        static Image query;
        static int mode(std::vector<int>);
        static void euc_distance(std::vector<std::pair<int, int>>&);

    public:
        KNNAlgo(){};
        ~KNNAlgo(){};
        bool Classify(std::vector<Image>, Image, int, int (*choice_func)(std::vector<int>));

};
#endif
