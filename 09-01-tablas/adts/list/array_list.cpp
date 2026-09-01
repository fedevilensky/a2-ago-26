#pragma once

#include "list.cpp"
#include <assert.h>

template <class T> class arrayList : public list<T> {
private:
  int capacity;
  int count;
  T *arr;

  void grow() {
    int newCapacity = this->capacity * 2;
    T *newArr = new T[newCapacity];
    for (int i = 0; i < this->capacity; i++) {
      newArr[i] = arr[i];
    }

    this->arr = newArr;
    this->capacity = newCapacity;
  }

public:
  virtual void add(T data) override {
    if (this->count == this->capacity) {
      grow();
    }

    this->arr[count] = data;
    this->count++;
  }
  virtual int size() override { assert(false); }
  virtual T getPos(int p) override {
    assert(p < count);
    return this->arr[p];
  }
  virtual int findPos(T data) override { assert(false); }
  virtual void remove(T data) override { assert(false); }
  virtual void removePos(int pos) { assert(false); }
};
