#include <iostream>
#include "String.h"
#include "Array.h"
#include "DynamicArray.h"

int main() {

    DynamicArray<std::string> vector;
    vector.pushBack("Logan");
    vector.pushBack("Bontrager");
    vector.emplaceBack("Yep");
    vector.popBack();

    for (int i = 0; i < vector.size(); i++)
        std::cout << vector[i] << std::endl;

    std::cout << "------------------------" << std::endl;

    vector.clear();
    vector.emplaceBack("Hi");
    vector.emplaceBack("There");
    vector.emplaceBack("Hi");
    vector.emplaceBack("There");
    vector.emplaceBack("Hi");
    vector.emplaceBack("There");

    for (int i = 0; i < vector.size(); i++)
        std::cout << vector[i] << std::endl;

    /*
    Array<int, 3> arr; //= {1, 2, 5};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 5;

    for (auto value : arr)
        std::cout << value << std::endl;


    Array<double, 2> dbl_arr;
    dbl_arr[0] = 0.5;
    dbl_arr[1] = 1.5;
    for (auto dbl_val : dbl_arr)
        std::cout << dbl_val << std::endl;

    Array<std::string, 2> string_arr;
    string_arr[0] = "Logan";
    string_arr[1] = "Bontrager";

    for (auto str : string_arr)
        std::cout << str << std::endl;

    */

    return 0;
}
