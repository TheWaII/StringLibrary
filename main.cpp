#include <iostream>
#include "Library/myString.h"

int main() {

#pragma region Aufgabenstellung Teil 1
    String::myString myString("Hello");
    myString.Concatenate("World");
    myString.Concatenate(myString.c_str());
    String::myString otherString(myString);
    String::myString yetAnotherString("AnotherWorld");
    otherString = yetAnotherString;
    std::cout << otherString.c_str();

#pragma endregion

#pragma region Aufgabenstellung Teil 2

    String::myString s1("Hello");
    const String::myString s2("World");
    s1 += s2;
    String::myString s3 = s1 + s2;
    s3 += "Hello";
    const String::myString s4 = s3 + "World";
    puts(s4.c_str());

#pragma endregion Aufgabenstellung Teil 2


    return 0;


}
