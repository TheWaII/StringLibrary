//
// Created by thewa on 16/09/2021.
//

#include "String.h"
#include "iostream"

char *myString;

String::String() = default;

String::String(const char *string) {

    size_t stringSize = sizeof(string + 1);

    myString = new char[stringSize];

    size_t i = 0;

    while (string[i] != '\0') {
        myString[i] = string[i];
        i++;
    }

    myString[i] = '\0';

    std::cout << myString << std::endl;
}

void String::concatenate(const char *concatenateString) {

}


