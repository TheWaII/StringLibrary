//
// Created by thewa on 16/09/2021.
//

#ifndef STRINGLIBRARY_STRING_H
#define STRINGLIBRARY_STRING_H

namespace myString {


    class String {


    public:

        char *newString{};

        String();

        explicit String(const char *string);

        static void concatenate(const String& string);

        ~String() { delete newString; }

    };

}
#endif //STRINGLIBRARY_STRING_H
