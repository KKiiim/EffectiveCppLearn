#include <cstdio>
class Base {
public:
   void foo() {
       int x = 1;
       printf("%d\n",x);
   }
};

class Derived : public Base {
public:
   void bar() {
       Base::foo(); // Forwarding function call to Base::foo()
   }
};

int main(){
    Derived d;
    d.bar();
}