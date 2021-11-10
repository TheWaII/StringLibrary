//
// Created by thewa on 16/09/2021.
//
#include "myString.h"
#include "iostream"


String::myString::myString() = default;

#pragma region Aufgabenstellung 1

String::myString::myString(const char *string) {

    stringSize = 0;
    while (string[stringSize] != '\0')
        stringSize++;

    newString = new char[stringSize + 1];
    for (size_t i = 0; i < stringSize; i++) {
        newString[i] = string[i];
    }

    newString[stringSize] = '\0';

}


String::myString &String::myString::Concatenate(const char *string) {

    size_t i = 0;

    char *tempString = newString;

    size_t newSize = stringSize;

    while (string[i] != '\0') {
        newSize++;
        i++;
    }

    newString = new char[newSize + 1];

    for (i = 0; i < stringSize; i++) {
        if (tempString != nullptr)
            newString[i] = tempString[i];
    }

    for (i = 0; i < newSize - stringSize; i++) {
        newString[i + stringSize] = string[i];
    }


    delete (tempString);

    newString[newSize] = '\0';
    stringSize = newSize;

    //return reference to the object
    return *this;
}

//return value is const; function read only.
const char *String::myString::c_str() const {
    return newString;
}

size_t String::myString::getLength() const {
    return stringSize;
}


#pragma endregion Aufgabenstellung 1


String::myString::myString(const String::myString &otherString) {

    unsigned int otherSize = otherString.stringSize;
    newString = new char[otherSize + 1];

    for (unsigned int i = 0; i < stringSize; ++i) {
        newString[i] = otherString.newString[i];
    }

    newString[otherSize] = '\0';
}

String::myString &String::myString::operator=(const String::myString &otherString) {

    if (this != &otherString) {
        delete[](newString);
        stringSize = otherString.stringSize;
        newString = new char[stringSize + 1];

        for (unsigned int i = 0; i < stringSize; i++) {
            newString[i] = otherString.newString[i];
        }
        newString[stringSize] = '\0';
    }

    return *this;
}

String::myString::myString(String::myString &&otherString) noexcept {

    if (this != &otherString) {
        newString = otherString.newString;
        otherString.newString = nullptr;
        otherString.stringSize = 0;
    }
}

String::myString &String::myString::operator=(String::myString &&otherString) noexcept {

    if (this != &otherString) {
        delete[](newString);
        newString = otherString.newString;
        stringSize = otherString.stringSize;
        otherString.newString = nullptr;
        otherString.stringSize = 0;
    }

    return *this;
}

String::myString &String::myString::operator+(const String::myString &otherString) {
    Concatenate(otherString.newString);
    return *this;
}

String::myString &String::myString::operator+(const char *otherString) {
    Concatenate(otherString);
    return *this;
}

String::myString &String::myString::operator+=(const String::myString &otherString) {

    Concatenate(otherString.newString);
    return *this;
}

String::myString &String::myString::operator+=(const char *otherString) {
    Concatenate(otherString);
    return *this;
}

