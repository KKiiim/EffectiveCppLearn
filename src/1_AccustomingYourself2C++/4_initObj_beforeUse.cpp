#include <thread>
class Singleton {
 public:
  inline static Singleton &ins() {
    static Singleton s;
    return s;
  }

  Singleton(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton &operator=(Singleton &&) = delete;

 private:
  Singleton() = default;
};

int main() {
  Singleton &s = Singleton::ins();

  std::thread t([] {});
}