#pragma once

template <class T> class bst {
public:
  virtual void add(T data) = 0;
  virtual void remove(T data) = 0;
  virtual int size() = 0;
  virtual T max() = 0;
  virtual T min() = 0;
};
