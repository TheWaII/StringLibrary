#define BOOST_TEST_MODULE StringLibraryTests

#include <boost/test/unit_test.hpp>
#include "../lib/myString.h"
#include <string>

BOOST_AUTO_TEST_SUITE(run_all_tests)

    BOOST_AUTO_TEST_SUITE(Aufgabenstellung_Teil_1)

        BOOST_AUTO_TEST_CASE(pass_create_string)
        {
            std::string expected = "Hello";
            String::myString myString("Hello");
            const char *actual = myString.c_str();

            BOOST_CHECK_EQUAL(expected, actual);
        }

        BOOST_AUTO_TEST_CASE(pass_concatenate)
        {
            std::string temp1 = "Hello";
            std::string temp2 = "World";

            std::string expected = temp1.append(temp2);

            String::myString myString("HelloWorld");
            const char *actual = myString.c_str();

            BOOST_CHECK_EQUAL(expected, actual);
        }

        BOOST_AUTO_TEST_CASE(pass_string_count)
        {
            std::string temp1 = "Hello";
            unsigned int expected = temp1.length();

            String::myString myString("Hello");
            unsigned int actual = myString.getLength();

            BOOST_CHECK_EQUAL(expected, actual);
        }

    BOOST_AUTO_TEST_SUITE_END()

//    BOOST_AUTO_TEST_SUITE(Aufgabenstellung_Teil_2)
//
//        BOOST_AUTO_TEST_CASE(pass_copy_constructor)
//        {
//            std::string temp1 = "Hello";
//            unsigned int expected = temp1.length();
//
//            String::myString myString("Hello");
//            unsigned int actual = myString.getLength();
//
//            BOOST_CHECK_EQUAL(expected, actual);
//        }
//
//    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


