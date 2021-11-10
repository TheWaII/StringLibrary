//
// Created by thewa on 16/09/2021.
//

#ifndef STRINGLIBRARY_MYSTRING_H
#define STRINGLIBRARY_MYSTRING_H

#include <cstdio>
#include "gtest/gtest.h"

namespace String {

    class myString {

    private:

        char *newString{};
        size_t stringSize{};

    public:

        myString();

        explicit myString(const char *string);

        myString &Concatenate(const char *string);

        size_t getLength() const;

        const char *c_str() const;

        myString(const myString &str);

        String::myString &operator=(const String::myString &otherString);

        myString(myString &&otherString) noexcept;

        String::myString &operator=(String::myString &&otherString) noexcept;

        String::myString &operator+(const String::myString &otherString);

        String::myString &operator+(const char *otherString);

        String::myString &operator+=(const String::myString &otherString);

        String::myString &operator+=(const char *otherString);

    };

}
#endif //STRINGLIBRARY_MYSTRING_H
