#include <iostream>
#include "String.h"

int main() {
    String str = "Logan";
    String str2 = str;
    str2[1] = 'e';
    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    return 0;
}
