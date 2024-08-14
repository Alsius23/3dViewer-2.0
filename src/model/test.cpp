#include "model.h"

int main(){

    auto start = std::chrono::steady_clock::now();

    s21::Model md;

    md.read_file("../object_files/bosel.obj");
    //std::cout << "\n\n\n\n";
    //md.write_data();

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl; 

    return 0;
}