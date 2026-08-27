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

  node *leftRotation(node *n) {
    //       z
    //     /   \
    //   z_l    y
    //         /  \
    //       y_l   x

    //       y
    //     /   \
    //    z     x
    //   /  \
    // z_l  y_l

    node *z = n;
    node *y = z->right;
    node *y_l = y->left;

    z->right = y_l;
    y->left = z;

    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
  }
  node *rightRotation(node *n) { assert(false); }

  node *rightLeftRotation(node *n) { assert(false); }

  node *leftRightRotation(node *n) { assert(false); }

  node *balance(node *n) {
    // bf => Balance Factor
    int bF = height(n->left) - height(n->right);

    if (bF == -2) {
      // desbalance der-?
      int bFRight = height(n->right->left) - height(n->right->right);
      if (bFRight == -1) {
        // desbalance der-der
        n = leftRotation(n);
      } else {
        // desbalance der-izq
        n = rightLeftRotation(n);
      }
    } else if (bF == 2) {
      // desbalance izq-?

      int bFLeft = height(n->left->left) - height(n->left->right);
      if (bFLeft == -1) {
        // desbalance izq-der
        n = leftRightRotation(n);
      } else {
        // desbalance izq-izq
        n = rightRotation(n);
      }
    }

    return n;
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
    n = balance(n);

    return n;
  }

public:
  avl() {}

  virtual void add(T data) override { this->root = add(this->root, data); }
  virtual void remove(T data) override { assert(false); }
  virtual int size() override { return size(root); }
  virtual T max() override { assert(false); }
  virtual T min() override { assert(false); }
};
