#pragma once
#include "heap.cpp"
#include <cassert>

template <class T> class minHeap : public heap<T> {
private:
  T *arr;
  int arrLength;
  int count;

  void grow(int newlength) {
    T *newArr = new T[newlength];
    for (int i = 0; i < this->arrLength; i++) {
      newArr[i] = this->arr[i];
    }

    //  delete[] this->arr;
    this->arr = newArr;
  }

  void swap(int posA, int posB) {
    T aux = this->arr[posA];
    this->arr[posA] = this->arr[posB];
    this->arr[posB] = aux;
  }

  void siftUp(int pos) {
    if (pos == 1) {
      return;
    }

    // comparo con el padre
    int parentPos = pos / 2;

    T elem = this->arr[pos];
    T parent = this->arr[parentPos];

    // si el padre es mayor ?
    if (parent > elem) {
      swap(pos, parentPos);
      siftUp(parentPos);
    }
  }

public:
  minHeap(int expectedSize) {
    this->arr = new T[expectedSize + 1];
    this->arrLength = expectedSize + 1;
    this->count = 0;
  }

  virtual void push(T elem) override {
    if (this->count == this->arrLength) {
      grow(this->arrLength * 2);
    }

    this->count++;
    this->arr[this->count] = elem;

    siftUp(this->count);
  }
  virtual T top() override {
    assert(size() >= 1);

    return this->arr[1];
  }
  virtual T pop() override { assert(false); }
  virtual int size() override { return this->count; }

  virtual bool isEmpty() override { return size() == 0; }
};
