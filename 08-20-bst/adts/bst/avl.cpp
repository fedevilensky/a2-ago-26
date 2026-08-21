#pragma once

#include "bst.cpp"
#include <assert.h>

template <class T> class avl : public bst<T> {
private:
  struct node {
    T data;
    node *left = nullptr;
    node *right = nullptr;
    int height = 1;

    // constructor
    node(T data) { this->data = data; }
  };

  node *root = nullptr;

  int size(node *n) {
    if (n == nullptr) {
      return 0;
    }

    return 1 + size(n->left) + size(n->right);
  }

  int max(int a, int b) {
    if (a > b)
      return a;
    return b;
  }

  int height(node *n) {
    if (n == nullptr) {
      return 0;
    }
    return n->height;
  }

  node *add(node *n, T data) {
    if (n == nullptr) {
      return new node(data);
    }

    // else
    if (data < n->data) {
      n->left = add(n->left, data);
    } else {
      n->right = add(n->right, data);
    }

    n->height = 1 + max(height(n->left), height(n->right));

    // si no esta balanceado, lo balanceamos
  }

public:
  avl() {}

  virtual void add(T data) override { this->root = add(this->root, data); }
  virtual void remove(T data) override { assert(false); }
  virtual int size() override { return size(root); }
  virtual T max() override { assert(false); }
  virtual T min() override { assert(false); }
};
