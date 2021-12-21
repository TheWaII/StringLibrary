//
// Created by thewa on 16/09/2021.
//

#ifndef STRINGLIBRARY_MYSTRING_H
#define STRINGLIBRARY_MYSTRING_H

#include <algorithm>
#include <cstdio>

namespace String {

class myString {

public:
  explicit myString(const char *string);

  ~myString();

  myString &Concatenate(const char *string);

  size_t getLength() const;

  const char *c_str() const;

  myString(const myString &str);

  myString &operator=(const myString &otherString);

  myString(myString &&otherString) noexcept;

  operator const char *() const { return c_str(); };

  myString &operator=(myString &&otherString) noexcept;

  myString &operator+(const myString &otherString);

  myString &operator+(const char *otherString);

  myString &operator+=(const myString &otherString);

  myString &operator+=(const char *otherString);

  /**
   * \Iterator
   * I have inherited the class 'bidirectional_iterator_tag' for my Iterator
   * class as a base template to work with. It provides me with nested type
   * which I then implement myself.
   *
   * \bidirectional_iterator_tag
   * This class inherits from forward_iterator_tag which inherits from
   * 'input_iterator_tag'. With this, the following members are provided:\n
   *          -> iterator_category\n
   *          -> value_type\n
   *          -> difference_type\n
   *          -> pointer\n
   *          -> reference\n
   *
   * @see https://www.cplusplus.com/reference/iterator/iterator/
   * */
  class Iterator : public std::iterator<std::bidirectional_iterator_tag, char> {

  private:
    char *ptr;

  public:
    explicit Iterator(pointer iPtr);

    Iterator(const Iterator &it);

    ~Iterator();

    bool operator==(const Iterator &it) const;

    bool operator!=(const Iterator &it);

    Iterator &operator=(const Iterator &it);

    Iterator &operator++();

    Iterator &operator++(int);

    Iterator &operator--();

    Iterator &operator--(int);

    value_type operator*() const;
  };

  Iterator begin() const;

  Iterator end() const;

private:
  char *newString{};
  size_t stringSize{};
};

} // namespace String

#endif // STRINGLIBRARY_MYSTRING_H