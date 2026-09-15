#pragma once

#include "../iterator/iterator.cpp"

template <class T> class list: public iterable<T> {
public:
  virtual void add(T data) = 0;
  virtual int size() = 0;
  virtual T getPos(int p) = 0;
  virtual int findPos(T data) = 0;
  virtual void remove(T data) = 0;
  virtual void removePos(int pos) = 0;
};
