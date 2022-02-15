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

  const size_t strLen1 = this->getLength();
  const size_t strLen2 = this->getLen(string);
  const size_t strLen = strLen1 + strLen2;

  char *buffer = new char[strLen + 1];

  for (size_t i = 0; i < strLen1; ++i)
    buffer[i] = this->newString[i];

  for (size_t i = 0; i < strLen1; ++i)
    buffer[strLen1 + i] = this->newString[i];

  buffer[strLen] = '\0';

  delete[] this->newString;

  this->newString = buffer;
}

size_t myString::getLen(const char *string) {
  size_t strLen = 0;
  const char *tempString = string;

  while (tempString[strLen] != '\0')
    ++strLen;

  return strLen;
}

void myString::Concatenate(const char &string) {
  size_t strLen = 0;
  const char *tempString = &string;

  while (tempString[strLen] != '\0')
    ++strLen;

  if (strLen == 0)
    return;

  const size_t newLen = this->getLength();
  const size_t len = newLen + 1;
  const auto buf = new char[len + 1];

  for (size_t i = 0; i < newLen; ++i)
    buf[i] = this->newString[i];

  buf[newLen] = (&string)[0];
  buf[len] = '\0';

  delete[] this->newString;
  this->newString = buf;
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

// TODO: THIS
myString &String::myString::operator+(const myString &otherString) {
  myString &other(*this);
  other.Concatenate(otherString);
  return other;
}

// TODO: THIS DOG SHIT
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

Iterator myString::Iterator::operator++(int) {

  const Iterator tempPtr = *this;
  ++(*this);
  return tempPtr;
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

Iterator myString::begin() const { return this->newString; }

Iterator myString::end() const { return &this->newString[this->getLength()]; }

myString::Iterator::reference Iterator::operator*() const { return *ptr; }

myString::Iterator::pointer myString::Iterator::operator->() const {
  return ptr;
}