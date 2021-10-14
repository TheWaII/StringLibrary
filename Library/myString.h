//
// Created by thewa on 16/09/2021.
//

#ifndef STRINGLIBRARY_MYSTRING_H
#define STRINGLIBRARY_MYSTRING_H

#include <cstdio>

namespace String {

    class myString {

    private:
        char *ptr{};
        size_t size{};

    public:

        myString();

        explicit myString(const char* string);

        myString& Concatenate(const char* string);

        size_t getLength() const;

        const char *c_str() const;

    };

}
#endif //STRINGLIBRARY_MYSTRING_H
