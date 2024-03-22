class A {
 public:
  void foo() {}
};
class B {
 private:
  void foo() {}
};

class Derive : public A, public B {};

int main() {
  Derive d;
  d.foo();
}
