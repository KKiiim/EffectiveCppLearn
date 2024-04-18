#include <cstdint>
#include <vector>
template <typename T>
class SmartPtr {
 public:
  SmartPtr(T* realPtr) : heldPtr(realPtr) {}
  template <typename U>
  SmartPtr(SmartPtr<U>& other) : heldPtr(other.get()) {}
  T* get() { return heldPtr; }

 private:
  T* heldPtr;
};

int main() {
  int x = 1;
  SmartPtr<int> iiint(&x);

  SmartPtr<double> dddouble(iiint);
  SmartPtr<unsigned int> uuuint(iiint);

  double y = 1.1;
  SmartPtr<double> ydouble(&y);
  SmartPtr<int> yint(ydouble);

  unsigned int z = 1;
  SmartPtr<unsigned int> zuint(&z);
  SmartPtr<int> zint(zuint);

  uint32_t u32int = 1;
  SmartPtr<uint32_t>    u32intPtr(&u32int);
  SmartPtr<uint16_t> u16intPtr(u32intPtr);
}