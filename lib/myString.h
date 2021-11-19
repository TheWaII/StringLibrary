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

        myString &operator=(const myString &otherString);

        myString(myString &&otherString) noexcept;

        myString &operator=(myString &&otherString) noexcept;

        myString &operator+(const myString &otherString);

        myString &operator+(const char *otherString);

        myString &operator+=(const myString &otherString);

        myString &operator+=(const char *otherString);

        class FwdIterator {

        public:

            using iterator_category = std::input_iterator_tag;
            using value_type = char;
            using difference_type = std::ptrdiff_t;
            using pointer = char *;
            using reference = char &;

            char *fwdPtr;

            FwdIterator(pointer nFwdPtr = nullptr);

            FwdIterator(const FwdIterator &it);

            bool operator==(FwdIterator it);

            bool operator!=(FwdIterator it);

            FwdIterator &operator=(const FwdIterator &it);

            virtual FwdIterator &operator++();

            virtual FwdIterator &operator++(int);

            virtual FwdIterator &operator--();

            virtual FwdIterator &operator--(int);

            virtual value_type operator*();
        };

        class RevIterator : public FwdIterator {

        public:
            char *revPtr;

            RevIterator(pointer nRevPtr = nullptr);

            RevIterator(const RevIterator &it);

            bool operator==(RevIterator it);

            bool operator!=(RevIterator it);

            RevIterator &operator=(const RevIterator &it);

            RevIterator &operator++();

            RevIterator &operator++(int);

            RevIterator &operator--();

            RevIterator &operator--(int);

            value_type operator*();
        };

        FwdIterator FwdBegin() const;

        FwdIterator FwdEnd() const;

        RevIterator RevBegin() const;

        RevIterator RevEnd() const;

    };
}
#endif //STRINGLIBRARY_MYSTRING_H
