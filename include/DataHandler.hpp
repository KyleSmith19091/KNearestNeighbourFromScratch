#include <functional>
#include <string>
#include <vector>
#include "Image.hpp"

#pragma once
class DataHandler {
    private:
        int magic_number_label;
        int magic_number_image;
        int number_of_labels;
        int number_of_images;
        int number_of_rows;
        int number_of_cols;

        std::vector<Image> image_data;
        std::vector<unsigned char> labels;
        std::vector<Image> test_image_data;
        std::vector<unsigned char> test_labels;

        constexpr int reverseInt (int i){
            unsigned char c1=0, c2=0, c3=0, c4=0;
            c1 = i & 255;
            c2 = (i >> 8) & 255;
            c3 = (i >> 16) & 255;
            c4 = (i >> 24) & 255;
            return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
        };

        void read_Image_File(const std::string& image_file_path, bool);
        void read_Label_File(const std::string& label_file_path, bool);

    public:
      DataHandler();
      ~DataHandler();
      void prepareData(const std::string& image_file_path, const std::string& label_file_path, bool=false);


      int get_Magic_Number_Label();
      int get_Magic_Number_Image();
      int get_Number_Of_Labels()  ;
      int get_Number_Of_Images()  ;
      int get_Number_Of_Rows()    ;
      int get_Number_Of_Cols()    ;
      std::vector<Image> get_Image_Data();
      std::vector<Image> get_Test_Image_Data();  


};
