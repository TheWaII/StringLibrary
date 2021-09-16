//
// Created by thewa on 16/09/2021.
//

#ifndef STRINGLIBRARY_STRING_H
#define STRINGLIBRARY_STRING_H


class String {

    const char *string{};

public:

    String();

    explicit String(const char *string);

    void concatenate(const char *string);

    ~String() { delete string; }

};


#endif //STRINGLIBRARY_STRING_H
