#include <iostream>
#include "../lib/myString.h"

using namespace String;

int main() {

#pragma region Aufgabenstellung Teil 1

    myString string("Hello");
    string.Concatenate("World");
    string.Concatenate(string.c_str());
    myString otherString(string);
    myString yetAnotherString("AnotherWorld");
    otherString = yetAnotherString;
    std::cout << otherString.c_str() << std::endl;

#pragma endregion

#pragma region Aufgabenstellung Teil 2

    myString s1("Hello");
    const myString s2("World");
    s1 += s2;
    myString s3 = s1 + s2;
    s3 += "Hello";
    const myString s4 = s3 + "World";
    //    puts(s4);

#pragma endregion Aufgabenstellung Teil 2

#pragma region Aufgabenstellung Teil 3

    const String::myString test("Hello World!");
    for (String::myString::Iterator it = test.begin(); it != test.end(); --it) {
      std::cout << *it << '\n';
    }

        std::cout << (std::find(test.begin(), test.end(), 'W') != test.end())
        << '\n';

#pragma endregion Aufgabenstellung Teil 3

    return 0;
}
