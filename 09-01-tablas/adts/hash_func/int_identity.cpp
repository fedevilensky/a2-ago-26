#pragma once

#include "hash_func.cpp"

class intIdentity : public hashFunc<int> {
public:
  virtual int hash(int i) override { return i; }
};
