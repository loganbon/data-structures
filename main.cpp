#include <iostream>
#include "String.h"
#include "Array.h"

int main() {
    Array<int, 3> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 5;

    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;


    Array<std::string, 2> string_arr;
    string_arr[0] = "Logan";
    string_arr[1] = "Bontrager";

    for (size_t i = 0; i < string_arr.size(); i++)
        std::cout << string_arr[i] << std::endl;

    return 0;
}
