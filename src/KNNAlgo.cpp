#include "../include/KNNAlgo.hpp"

int KNNAlgo::mode(std::vector<int> v) {

  int maxCount = 1; // Assume max to be 1
  int mode = v[0];  // Init mode to first label value

  for_each(v.begin(), v.end(), [&](int i) {
    int d = std::count(v.begin(), v.end(), i);
    if (d > maxCount) {
      maxCount = d;
      mode = i;
    }
  });

  return mode;
}

void KNNAlgo::euc_distance(std::vector<std::pair<int, int>>& dist_and_k){
  for (int i = 0; i < data.size(); i++) {
    dist_and_k[i] = (std::make_pair(
                     (data[i].getPixelData() - query.getPixelData()).array().pow(2).sum(),
                     data[i].getLabel()
                     ));
  }
}

bool KNNAlgo::Classify(std::vector<Image> data, Image query, int k = 10,int (*choice_func)(std::vector<int>) = mode) {

  if (k == 0) {
    std::cout << "Please choose valid k value\n";
    throw "Invalid k value";
  }

  if (data.size() == 0) {
    std::cout << "Please provide a valid Image vector\n";
    throw "Invalid image vector";
  }

  std::vector<std::pair<int, int>> dist_and_k(data.size());

  // Distance calculation
  euc_distance(dist_and_k);

  // Sorting the according to distances
  sort(dist_and_k.begin(), dist_and_k.end(),
       [](std::pair<int, int> p, std::pair<int, int> p2) {
         return p.first < p2.first;
  });

  std::vector<int> k_labels(k);
  // Choose k labels
  for (int i = 0; i < k; i++) {
    k_labels[i] = dist_and_k[i].second;
  }

  return choice_func(k_labels) == query.getLabel();
}
