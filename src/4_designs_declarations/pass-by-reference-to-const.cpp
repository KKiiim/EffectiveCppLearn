#include <iostream>
#include <string>
class Window {
public:
  std::string name() const { return "name()\n"; }
  virtual void display() const { std::cout << "Window display\n"; }
};

class WindowWithScrollBars : public Window {
public:
  virtual void display() const { std::cout << "WindowWithScrollBars display\n"; }
};

void printNameAndDisplay(Window w) {
  std::cout << w.name();
  w.display();
}

void referPrintNameAndDisplay(const Window &w) { // same as pointer
  std::cout << w.name();
  w.display();
}

int main() {
  WindowWithScrollBars wwsb;
  printNameAndDisplay(wwsb); // obj slicing, only value in Class-Windows remains.
  referPrintNameAndDisplay(wwsb);
}