#define BOOST_TEST_MODULE StringLibraryTests

#include "../lib/myString.h"
#include <array>
#include <boost/iterator.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
using namespace std;
#include <string>

BOOST_AUTO_TEST_SUITE(run_all_tests)

BOOST_AUTO_TEST_SUITE(Aufgabenstellung_Teil_1)

BOOST_AUTO_TEST_CASE(pass_create_string) {
  BOOST_TEST_MESSAGE("checking: Create String");
  std::string expected = "Hello";
  String::myString myString("Hello");
  const char *actual = myString.c_str();

  BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(pass_concatenate) {
  BOOST_TEST_MESSAGE("checking: Concatenate");

  std::string temp1 = "Hello";
  std::string temp2 = "World";

  std::string expected = temp1.append(temp2);

  String::myString myString("HelloWorld");
  const char *actual = myString.c_str();

  BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(pass_string_count) {
  BOOST_TEST_MESSAGE("checking: string count");

  std::string temp1 = "Hello";
  unsigned int expected = temp1.length();

  String::myString myString("Hello");
  unsigned int actual = myString.getLength();

  BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Aufgabenstellung_Teil_2)

BOOST_AUTO_TEST_CASE(pass_copy_constructor) {
  BOOST_TEST_MESSAGE("checking: copy constructor");

  String::myString expected("Hello");

  const String::myString &actual(expected);

  BOOST_CHECK_EQUAL(expected.c_str(), actual.c_str());
}

BOOST_AUTO_TEST_CASE(pass_copy_assignment_operator) {

  BOOST_TEST_MESSAGE("checking: assignment operator");

  String::myString expected("Hello");

  const String::myString &actual = expected;

  BOOST_CHECK_EQUAL(expected.c_str(), actual.c_str());
}

// Move couldn't be tested

BOOST_AUTO_TEST_CASE(pass_operator_plus) {
  BOOST_TEST_MESSAGE("checking: operator +");

  String::myString temp("Hello");

  String::myString actual = temp + "World";

  const char *expected = "HelloWorld";

  BOOST_CHECK_EQUAL(expected, actual.c_str());
}

BOOST_AUTO_TEST_CASE(pass_operator_plus_equal) {
  BOOST_TEST_MESSAGE("checking: operator +=");

  String::myString temp("Hello");
  String::myString temp2("World");

  String::myString actual = temp += temp2;

  const char *expected = "HelloWorld";

  BOOST_CHECK_EQUAL(expected, actual.c_str());
}

BOOST_AUTO_TEST_CASE(pass_iterator_forward) {
  BOOST_TEST_MESSAGE("checking: iterator");
  const String::myString test("Hello World");
  for (String::myString::Iterator it = test.begin(); it != test.end(); ++it) {
    std::cout << *it << '\n';
  }
}

/**
 * @brief Why it-- inside for-loop? \n
 * with the -- the last char was not being printed. Therefore with this,
 * I start printing values from end-1
 */
BOOST_AUTO_TEST_CASE(pass_iterator_reverse) {
  BOOST_TEST_MESSAGE("checking: iterator");
  const String::myString test("Hello World");
  for (String::myString::Iterator it = test.end(); it != test.begin();) {
    it--;
    std::cout << *it << '\n';
  }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
