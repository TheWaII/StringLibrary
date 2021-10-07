#include "Library/String.h"

int main() {

    myString::String myString("Hello");

    myString::String::concatenate((const myString::String &) "World");

    myString::String::concatenate(myString);


    //myString.concatenate("World");

    //myString.concatenate(myString);

    //String otherString(myString);
    //String yetAnotherString("AnotherWorld");

    //otherString = yetAnotherString;

    //std::cout << otherString.c_str();

    return 0;
}
