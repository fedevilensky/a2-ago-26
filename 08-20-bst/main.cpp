#include "adts/bst/avl.cpp"
#include "adts/bst/bst.cpp"
#include <iostream>

int main() {
  bst<int> *tree = new avl<int>();
  std::cout << "Tamano de mi arbol " << tree->size() << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << "Agrego el " << i << std::endl;
    tree->add(i);
  }

  std::cout << "Tamano de mi arbol " << tree->size() << std::endl;
}
