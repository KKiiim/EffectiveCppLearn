#include <iostream>

#if 0
class Rational {
public:
  Rational(int n = 0, int d = 1) : numerator_(n), denominator_(d) {}

private:
  int numerator_;
  int denominator_;
  friend const Rational &operator*(const Rational &lhs, const Rational &rhs);
  friend bool operator==(const Rational &lhs, const Rational &rhs);
};

// Unreasonable realization
// User unsafe, Multi-threads unsafe
const Rational &operator*(const Rational &lhs, const Rational &rhs) {
  static Rational res;
  res.denominator_ = lhs.denominator_ * rhs.denominator_;
  res.numerator_ = lhs.numerator_ * rhs.numerator_;
  return res;
}

bool operator==(const Rational &lhs, const Rational &rhs) {
  if (lhs.denominator_ == rhs.denominator_ && lhs.numerator_ == rhs.numerator_) {
    return true;
  }
  return false;
}

int main() {
  Rational a(1, 1), b(1, 1), c(2, 2), d(2, 2);
  // User unsafe
  if ((a * b) == (c * d)) {
    // always true
    std::cout << "a == b\n";
  } else {
    std::cout << "a != b\n";
  }
}

#endif

#if 1
class Rational {
 public:
  Rational(int n = 0, int d = 1) : numerator_(n), denominator_(d) {
    std::cout << "constructor \n";
  }
  ~Rational() { std::cout << "destructor \n"; }
  Rational(Rational &r) {
    numerator_ = r.numerator_;
    denominator_ = r.denominator_;
    std::cout << "copy constructor \n";
  }

 private:
  int numerator_;
  int denominator_;
  friend const Rational operator*(const Rational &lhs, const Rational &rhs);
  friend bool operator==(const Rational &lhs, const Rational &rhs);
};

inline const Rational operator*(const Rational &lhs, const Rational &rhs) {
  std::cout << "operator* \n";
  return Rational(lhs.numerator_ * rhs.numerator_,
                  lhs.denominator_ * rhs.denominator_);
}

bool operator==(const Rational &lhs, const Rational &rhs) {
  if (lhs.denominator_ == rhs.denominator_ &&
      lhs.numerator_ == rhs.numerator_) {
    return true;
  }
  return false;
}

int main() {
  Rational a(1, 1), b(1, 1), c(2, 2), d(2, 2);
  std::cout << "------------\n------------\n";
  if ((a * b) == (c * d)) {
    std::cout << "a == b\n";
  } else {
    std::cout << "a != b\n";
  }
  std::cout << "------------\n------------\n";
}

#endif