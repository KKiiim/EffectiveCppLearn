#if 0  // can't compile
template <typename T>
class Rational {
 public:
  Rational(const T& numerator = 0, const T& denominator = 1);
  const T numerator() const;
  const T denominator() const;
};

template <typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {}

int main() {
  Rational<int> oneHalf(1, 2);
  Rational<int> result = oneHalf * 2;
  // can not compiled. error: no match for ‘operator*’ (operand types are
  // ‘Rational<int>’ and ‘int’)

  /*
  Implicit type conversion functions are never taken into account in template
  real parameter derivation. Such conversions are indeed used in function calls.
  But template inference is needed to determine what functions to call before
  calling it, which cannot be implicitly converted and therefore cannot be
  compiled.
  */
}
#endif

#if 0  // ld error
template <typename T>
class Rational {
 public:
  Rational(const T& numerator = 0, const T& denominator = 1);
  const T numerator() const;
  const T denominator() const;

  friend const Rational operator*(const Rational<T>& lhs,
                                  const Rational<T>& rhs);
  // in a class template. const Rational operator*(...); AKA
  // const Rational<T> operator*(...);
};

template <typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {}

int main() {
  Rational<int> oneHalf(1, 2);
  Rational<int> result = oneHalf * 2;
}
#endif

template <typename T>
class Rational {
 public:
  Rational(const T& numerator = 0, const T& denominator = 1)
      : numerator_(numerator), denominator_(denominator) {}
  const T numerator() const { return numerator_; };
  const T denominator() const { return denominator_; };

  friend const Rational operator*(const Rational<T>& lhs,
                                  const Rational<T>& rhs) {
    return Rational(lhs.numerator() * rhs.numerator(),
                    lhs.denominator() * rhs.denominator());
  }

 private:
  T numerator_;
  T denominator_;
};

int main() {
  Rational<int> oneHalf(1, 2);
  Rational<int> result = oneHalf * 2;
}