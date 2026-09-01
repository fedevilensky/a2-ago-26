#pragma once

#include "../hash_func/hash_func.cpp"
#include "table.cpp"
#include <assert.h>

template <class K, class V> class closedHashTable : public table<K, V> {

private:
  struct bucket {
    K key;
    V value;
    bool isDeleted = false;

    bucket(K key, V value) {
      this->key = key;
      this->value = value;
    }
  };

  // bucket*[]
  bucket **array;
  int cantidad, capacidad, largoArray;
  hashFunc<K> *h;
  float fc;

  bool esPrimo(int num) {
    if (num <= 1)
      return false;
    if (num == 2)
      return true;
    if (num % 2 == 0)
      return false;
    for (int i = 3; i <= num / 2; i += 2) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }

  int primoSup(int num) {
    while (!esPrimo(++num))
      ;
    return num;
  }

  int abs(int x) {
    if (x < 0)
      return -x;

    return x;
  }

public:
  closedHashTable(int capacidad, hashFunc<K> *h) {
    this->cantidad = 0;
    this->capacidad = capacidad;
    this->fc = 0.0;
    this->largoArray = primoSup(capacidad);
    this->array = new bucket *[largoArray]();
    this->h = h;
  }

  virtual void set(K key, V value) override {
    remove(key);

    int collissions = 0;
    while (true) {
      int pos = abs(this->h->hash(key) + collissions % this->largoArray);
      bucket *b = this->array[pos];

      if (b == nullptr || b->isDeleted) {
        if (b == nullptr) {
          this->array[pos] = new bucket(key, value);
        } else {
          b->isDeleted = false;
          b->key = key;
          b->value = value;
        }

        break;
      }

      collissions++;
    }

    this->cantidad++;
    // mas cosas, como checkear factor de carga y hacer rehashing
  }

  virtual bool exists(K key) override { assert(false); }

  virtual V get(K key) override { assert(false); }

  virtual int size() override { return this->cantidad; }

  virtual void remove(K key) override { assert(false); }
};
