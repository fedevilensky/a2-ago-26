#pragma once

#include "hash_func.cpp"
#include <string>


class stringHash : public hashFunc<std::string> {
  virtual int hash(std::string s) override {
    // ESTO ES UNA MALA FUNCION EL QUE LA ENTREGA
    // PIERDE PUNTOS

    int n = 0;
    for (int i = 0; i < s.length(); i++) {
      n += s[i];
    }

    return n;
  }
};
