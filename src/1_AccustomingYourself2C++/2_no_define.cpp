////////////////////////////////////////////////
////////////////////////////////////////////////
/*
    constValue: use const/enums for #defines
    funcMacros: use inline function for #defines
*/
////////////////////////////////////////////////
////////////////////////////////////////////////
class Test1 {
private:
  static const int number = 5;
  int arra[number];
};
class Test2 {
private:
  static const int number;
  // int arra[number];
};
const int Test2::number = 5;

// enum hack
class Test3 {
private:
  enum { number = 5 };
  int arra[number];
};

#define number 5
class Test4 {
private:
  int arra[number];
};
/////////////////////////////////////////
/////////////////////////////////////////

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

template <typename T> inline void callWithMax(const T &a, const T &b) { f(a > b ? a : b); }