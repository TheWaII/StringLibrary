#include <iostream>
#include "Library/myString.h"

int main() {

    String::myString newString("Hello");

    newString.Concatenate("World");

    String::myString otherString(newString);

    String::myString yetAnotherString("AnotherWorld");

    otherString = yetAnotherString;

    std::cout << otherString.c_str() << std::endl;

    std::cout << "string length: "  << otherString.getLength() << std::endl;
    return 0;
}
