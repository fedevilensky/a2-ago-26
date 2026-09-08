#pragma once

#include "../heap/min_heap.cpp"
#include "priority_queue.cpp"
#include <cassert>

template <class E, class P>
class minPriorityQueue : public priorityQueue<E, P> {

private:
  struct pair {
    E elem;
    P prio;

    pair() {}

    pair(E elem, P prio) {
      this->elem = elem;
      this->prio = prio;
    }

    // this < other
    bool operator<(const pair &other) { return this->prio < other.prio; }
    bool operator>(const pair &other) { return this->prio > other.prio; }
    bool operator<=(const pair &other) { return this->prio <= other.prio; }
    bool operator>=(const pair &other) { return this->prio >= other.prio; }
    bool operator==(const pair &other) { return this->prio == other.prio; }
  };

  minHeap<pair> *h;

public:
  minPriorityQueue(int expectedSize) {
    this->h = new minHeap<pair>(expectedSize);
  }

  virtual void push(E elem, P prio) override {
    pair p = pair(elem, prio);
    this->h->push(p);
  }
  virtual E top() override {
    pair t = this->h->top();
    return t.elem;
  }

  virtual E pop() override {
    pair t = this->h->pop();
    return t.elem;
  }

  virtual int size() override { return this->h->size(); }
  virtual bool isEmpty() override { return this->h->isEmpty(); }
};
