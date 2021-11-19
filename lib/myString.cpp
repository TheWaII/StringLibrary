//
// Created by thewa on 16/09/2021.
//
#include "myString.h"
#include "iostream"

using namespace String;
using fItr = myString::FwdIterator;
using rItr = myString::RevIterator;

myString::myString() = default;

#pragma region Aufgabenstellung 1

myString::myString(const char *string) {

    stringSize = 0;
    while (string[stringSize] != '\0')
        stringSize++;

    newString = new char[stringSize + 1];
    for (size_t i = 0; i < stringSize; i++) {
        newString[i] = string[i];
    }

    newString[stringSize] = '\0';
}

myString &myString::Concatenate(const char *string) {

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
const char *myString::c_str() const {
    return newString;
}

size_t myString::getLength() const {
    return stringSize;
}


#pragma endregion Aufgabenstellung 1

#pragma region Aufgabenstellung 2

myString::myString(const myString &otherString) : stringSize(otherString.stringSize) {

    newString = new char[stringSize + 1];

    for (unsigned int i = 0; i < stringSize; ++i) {
        newString[i] = otherString.newString[i];
    }

    newString[stringSize] = '\0';
}

myString &myString::operator=(const myString &otherString) {

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

myString::myString(myString &&otherString) noexcept {

    if (this != &otherString) {
        this->newString = otherString.newString;
        this->stringSize = otherString.stringSize;
        otherString.newString = nullptr;
        otherString.stringSize = 0;
    }
}

myString &myString::operator=(String::myString &&otherString) noexcept {

    if (this != &otherString) {
        this->newString = otherString.newString;
        this->stringSize = otherString.stringSize;
        otherString.newString = nullptr;
        otherString.stringSize = 0;
    }

    return *this;
}

myString &String::myString::operator+(const myString &otherString) {
    Concatenate(otherString.newString);
    return *this;
}

myString &myString::operator+(const char *otherString) {
    Concatenate(otherString);
    return *this;
}

myString &myString::operator+=(const myString &otherString) {
    Concatenate(otherString.newString);
    return *this;
}

myString &myString::operator+=(const char *otherString) {
    Concatenate(otherString);
    return *this;
}

#pragma endregion Aufgabenstellung 2

#pragma region Aufgabenstellung 3

#pragma region FwdIterator

fItr myString::FwdBegin() const {

    return String::myString::FwdIterator(&newString[0]);
}

fItr myString::FwdEnd() const {
    return myString::FwdIterator(&newString[stringSize]);
}


fItr::FwdIterator(char *nFwdPtr) : fwdPtr(nFwdPtr) {

}

fItr::FwdIterator(const fItr &iterator) = default;

bool fItr::operator==(const fItr &fwdIt) const {
    return !(fwdPtr - fwdIt.fwdPtr);
}

bool fItr::operator!=(const fItr &fwdIt) const {
    return fwdPtr - fwdIt.fwdPtr;
}

fItr &fItr::operator=(const fItr &fwdIt) = default;

fItr &fItr::operator++() {
    fwdPtr += sizeof(char);
    return *this;
}

fItr &fItr::operator++(int) {
    fwdPtr += sizeof(char);
    return *this;
}

fItr &fItr::operator--() {
    fwdPtr -= sizeof(char);
    return *this;
}

fItr &fItr::operator--(int) {
    fwdPtr -= sizeof(int);
    return *this;
}

char fItr::operator*() {
    return *fwdPtr;
}

#pragma endregion FwdIterator

#pragma region RevIterator

rItr myString::RevBegin() const {

    return rItr(&newString[stringSize]);
}

rItr myString::RevEnd() const {
    return rItr(&newString[-1]);
}

rItr::RevIterator(char *nRevPtr) : revPtr(nRevPtr) {

}

rItr::RevIterator(const rItr &rIt) = default;

bool rItr::operator==(const myString::RevIterator &revIt) const {
    return !(revPtr - revIt.revPtr);
}

bool rItr::operator!=(const myString::RevIterator &revIt) const {
    return revPtr - revIt.revPtr;
}

rItr &rItr::operator++() {
    revPtr -= sizeof(char);
    return *this;
}

rItr &rItr::operator++(int) {
    revPtr -= sizeof(char);
    return *this;
}

rItr &rItr::operator--() {
    revPtr += sizeof(char);
    return *this;
}

rItr &rItr::operator--(int) {
    revPtr += sizeof(char);
    return *this;
}

char rItr::operator*() {
    return *revPtr;
}

rItr &rItr::operator=(const rItr &rIt) = default;

#pragma endregion RevIterator

#pragma endregion Aufgabenstellung 3