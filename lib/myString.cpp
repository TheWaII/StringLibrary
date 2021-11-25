//
// Created by thewa on 16/09/2021.
//
#include "myString.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "err_member_decl_does_not_match"
using namespace String;

using Iterator = myString::Iterator;

myString::~myString() { delete[] newString; }

#pragma region Aufgabenstellung 1

myString::myString(const char *string = "") {

  stringSize = 0;
  while (string[stringSize] != '\0')
    stringSize++;

  newString = new char[stringSize + 1];

  size_t i = 0;

  for (i = 0; i < stringSize; i++) {
    newString[i] = string[i];
  }

  newString[i + 1] = '\0';
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

  // return reference to the object
  return *this;
}

//return value is const; function read only.
const char *myString::c_str() const {
    return newString;
}

size_t myString::getLength() const {
    return stringSize;
}

myString::operator const char *() const { return newString; }

#pragma endregion Aufgabenstellung 1

#pragma region Aufgabenstellung 2

myString::myString(const myString &otherString) : stringSize(otherString.stringSize) {

  newString = new char[stringSize];

  for (unsigned int i = 0; i < stringSize; ++i) {
    newString[i] = otherString.newString[i];
  }

  newString[stringSize + 1] = '\0';
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
  myString newString(*this);
  Concatenate(otherString.newString);
  return *this;
}

myString &myString::operator+(const char *otherString) {
  myString newString(*this);
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

bool myString::Iterator::operator==(const Iterator &it) const {
  return !(ptr - it.ptr);
}
myString::Iterator::Iterator(char *ptr = nullptr) : ptr(ptr) {}

myString::Iterator::~Iterator(){};

myString::Iterator::Iterator(const Iterator &it) : ptr(it.ptr) {}

bool myString::Iterator::operator!=(const Iterator &it) { return ptr - it.ptr; }

Iterator &myString::Iterator::operator++() {

  ++ptr;
  return *this;
}

Iterator &myString::Iterator::operator++(int) {

  ++ptr;
  return *this;
}

Iterator &myString::Iterator::operator--() {
  --ptr;
  return *this;
}
Iterator &myString::Iterator::operator--(int) {
  --ptr;
  return *this;
}

char myString::Iterator::operator*() { return *ptr; }

Iterator &myString::Iterator::operator=(const Iterator &it) {
  ptr = it.ptr;
  return *this;
}

Iterator myString::begin() const {
  Iterator it(&newString[0]);
  return it;
}
Iterator myString::end() const {
  Iterator it(&newString[stringSize]);
  return it;
}