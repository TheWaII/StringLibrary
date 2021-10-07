//
// Created by thewa on 16/09/2021.
//
#include "String.h"
#include "iostream"

using namespace myString;

String::String() = default;

String::String(const char *string) {

    size_t stringSize = sizeof(string);

    newString = new char[stringSize + 1];

    size_t i = 0;

    while (string[i] != '\0') {
        newString[i] = string[i];
        i++;
    }

    //newString[i] = '\0';

    //std::cout << newString << std::endl;
}

void String::concatenate(const String& concatenateString) {

}
