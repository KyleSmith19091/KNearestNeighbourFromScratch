#include "../include/DataHandler.hpp"
#include "../include/Image.hpp"
#include <fstream>
#include <iostream>

DataHandler::DataHandler(){
    this->magic_number_image = 0;
    this->magic_number_label = 0;
    this->number_of_labels   = 0;
    this->number_of_images   = 0;
    this->number_of_rows     = 0;
    this->number_of_cols     = 0;
}

DataHandler::~DataHandler(){}

void DataHandler::read_Label_File(const std::string &label_file_path){
    std::ifstream label_file(label_file_path);

    if(!label_file.is_open()){
        std::cout << "Could not open label file\n";
        return;
    }

    label_file.read((char*)&magic_number_label, sizeof(magic_number_label));
    this->magic_number_label = reverseInt(magic_number_label);

    label_file.read((char*)&number_of_labels,sizeof(number_of_labels));
    this->number_of_labels = reverseInt(number_of_labels);

    this->labels.resize(number_of_labels);
    unsigned char label;

    for(int i = 0; i < number_of_labels; i++){
        label_file.read((char*)&label,sizeof(label));
        labels[i] = label;
    }

    label_file.close();
}

void DataHandler::read_Image_File(const std::string &image_file_path){
    std::ifstream image_file(image_file_path);

    if(!image_file.is_open()){
        std::cout << "Could not open image file\n";
        return;
    }

    image_file.read((char*)&magic_number_image, sizeof(magic_number_image));
    this->magic_number_image = reverseInt(magic_number_image);

    image_file.read((char*)&number_of_images,sizeof(number_of_images));
    this->number_of_images = reverseInt(number_of_images);

    image_file.read((char*)&number_of_rows,sizeof(number_of_rows));
    this->number_of_rows = reverseInt(number_of_rows);

    image_file.read((char*)&number_of_cols,sizeof(number_of_cols));
    this->number_of_cols = reverseInt(number_of_cols);

    image_data.resize(number_of_images);
    std::vector<std::vector<unsigned char>> pixels(number_of_rows,std::vector<unsigned char>(number_of_cols));

    for (int i = 0; i < number_of_images; i++) {
      std::vector<std::vector<unsigned char>> pixels(number_of_rows,std::vector<unsigned char>(number_of_cols));
      for (int j = 0; j < number_of_rows; j++) {
        for (int k = 0; k < number_of_cols; k++) {
            unsigned char temp;
            image_file.read((char*)&temp,sizeof(temp));
            pixels[j][k] = temp;
        }
      }
      this->image_data[i] = Image(pixels,this->labels[i]);
    }

    image_file.close();
}

void DataHandler::prepareData(const std::string &image_file_path, const std::string label_file_path){
    read_Label_File(label_file_path);
    read_Image_File(image_file_path);
}

int DataHandler::get_Magic_Number_Image(){
    return this->magic_number_image;
}

int DataHandler::get_Magic_Number_Label(){
    return this->magic_number_label;
}

int DataHandler::get_Number_Of_Labels(){
    return this->number_of_labels;
}

int DataHandler::get_Number_Of_Images(){
    return this->number_of_images;
}

int DataHandler::get_Number_Of_Rows(){
    return this->number_of_rows;
}

int DataHandler::get_Number_Of_Cols(){
    return this->number_of_cols;
}

std::vector<Image> DataHandler::get_Image_Data(){
    return this->image_data;
}




