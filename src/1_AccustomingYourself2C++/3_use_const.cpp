////////////////////////////////////////////////
////////////////////////////////////////////////

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

void f(void) {
  std::vector<int> vec = {1, 2, 3};

  const std::vector<int>::iterator iter = vec.begin();
  *iter = 10;
  // ++iter; // error: the pointer iter itselft is const.

  std::vector<int>::const_iterator cInter = vec.begin();
  //*cInter = 10; // error: the data cInter pointed is const value.
  ++cInter;
}

////////////////////////////////////////////////
////////////////////////////////////////////////
class Text {
 public:
  Text(std::string t) : text(t) {}
  const char &operator[](std::size_t position) const {
    printf("const []\n");
    return text[position];
  }

  char &operator[](std::size_t position) {
    printf("non-const []\n");
    //    return (const_cast<char &>(static_cast<Text&>(*this)[position])); ->
    //    call non-const recursive
    return const_cast<char &>(static_cast<const Text &>(*this)[position]);
  }

 private:
  std::string text;
};

class Text_constCallnonConst {
 public:
  Text_constCallnonConst(std::string t) : text(t) {}
  const char &operator[](std::size_t position) const {
    printf("const []\n");
    ///////////////////////////////////////////////
    //// never do this
    ///////////////////////////////////////////////
    return static_cast<const char &>(
        const_cast<Text_constCallnonConst &>(*this)[position]);
  }

  char &operator[](std::size_t position) {
    printf("non-const []\n");
    text[position] = 'p';
    return text[position];
  }

 private:
  std::string text;
};

int main() {
  Text text("hello");
  std::cout << text[0] << '\n' << '\n';
  /*
    non-const []
    const []
    h
  */

  const Text_constCallnonConst text2("hello");
  std::cout << text2[0] << '\n';
  /*
  const []
  non-const []
  p
*/
}
