//
// Created by thewa on 16/09/2021.
//
#include "myString.h"
#include <iostream>

using namespace String;

using Iterator = myString::Iterator;

myString::~myString() {
  delete[] newString;
  std::cout << "destructor called" << std::endl;
}

myString::myString(const char *string) {

  size_t i = 0;
  while (string[i] != '\0')
    i++;

  newString = new char[stringSize + 1];

  size_t j;
  for (j = 0; j < stringSize; j++) {
    newString[j] = string[j];
  }

  newString[j] = '\0';
}

myString::myString(const myString &string) : myString(string.newString) {}

myString::myString(myString &&otherString) noexcept {

  if (this != &otherString) {
    this->newString = otherString.newString;
    this->stringSize = otherString.stringSize;
    otherString.newString = nullptr;
    otherString.stringSize = 0;
  }
}

void myString::Concatenate(const char *string) {

  size_t i = 0;

  char *tempString = newString;

  size_t sizeOfNewString = sizeof(string) / sizeof(string[0]);

  size_t newSize = stringSize + sizeOfNewString;

  while (string[i] != '\0') {
    newSize++;
    i++;
  }

  for (i = 0; i < stringSize; i++) {
    if (tempString != nullptr)
      newString[i] = tempString[i];
  }

  for (i = 0; i < newSize - stringSize; i++) {
    newString[i + stringSize] = string[i];
  }

  newString[newSize] = '\0';
  stringSize = newSize;
}

void myString::Concatenate(const char &string) {
  size_t strLen = 0;
  const char *tempString = &string;

  while(tempString[strLen] != '\0')
    ++strLen;

  if(strLen == 0)
    return;

  const size_t
}

// return value is const; function read only.
const char *myString::c_str() const { return newString; }

size_t myString::getLength() const { return stringSize; }

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
  myString &other(*this);
  other.Concatenate(otherString);
  return other;
}

myString &myString::operator+(const char *otherString) {
  myString &other(*this);
  other.Concatenate(otherString);
  return other;
}

myString &myString::operator+=(const char &otherString) {
  myString &other(*this);
  Concatenate(otherString);
  return other;
}
myString &myString::operator+=(const myString &otherString) {
  Concatenate(otherString.newString);
  return *this;
}

myString &myString::operator+=(const char *otherString) {
  Concatenate(otherString);
  return *this;
}

bool myString::Iterator::operator==(const Iterator &it) const {
  return !(ptr - it.ptr);
}
myString::Iterator::Iterator(char *ptr) : ptr(ptr) {}

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

Iterator &myString::Iterator::operator=(const Iterator &it) {
  ptr = it.ptr;
  return *this;
}

/**
 * Starting from 0th index would remove the first letter. That is the reason to
 * start from -1th index.
 */

Iterator myString::begin() const {
  Iterator it(&newString[-1]);
  return it;
}
Iterator myString::end() const {
  Iterator it(&newString[stringSize]);
  return it;
}

char myString::Iterator::operator*() const { return *ptr; }
