#ifndef CALC_H
#define CALC_H

template <class T> class calc {
 public:
  T add(T x, T y) {
    return x + y;
  }
  T multiply(T x, T y) {
    return x * y;
  }
};

#endif
