//
// Created by thewa on 16/09/2021.
//
#include "myString.h"
#include "iostream"


String::myString::myString() = default;


String::myString::myString(const char *string) {

    size = 0;
    while (string[size] != '\0')
        size++;

    ptr = new char[size + 1];
    for (unsigned int i = 0; i < size; i++) {
        ptr[i] = string[i];
    }

    ptr[size] = '\0';

}


String::myString &String::myString::Concatenate(const char *string) {

    size_t i = 0;

    char *buffer = ptr;

    size_t newSize = size;

    while (string[i] != '\0') {
        newSize++;
        i++;
    }

    ptr = new char[newSize + 1];

    for (i = 0; i < size; i++) {
        if (buffer != nullptr)
            ptr[i] = buffer[i];
    }

    for (i = 0; i < newSize - size; i++) {
        ptr[i + size] = string[i];
    }

    delete[](buffer);

    ptr[newSize] = '\0';
    size = newSize;

    return *this;
}

const char *String::myString::c_str() const {
    return ptr;
}

size_t String::myString::getLength() const {
    return size;
}