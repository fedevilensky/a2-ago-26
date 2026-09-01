#include "adts/hash_func/int_identity.cpp"
#include "adts/table/closed_hash_table.cpp"
#include "adts/table/table.cpp"
#include <iostream>
#include <string>


int main() {
  table<int, std::string> *t =
      new closedHashTable<int, std::string>(4, new intIdentity());

  std::cout << "El largo de la tabla es " << t->size() << std::endl;

  std::cout << "Agrego el 1" << std::endl;
  t->set(1, "1");

  std::cout << "El largo de la tabla es " << t->size() << std::endl;

  std::cout << "Agrego el 2" << std::endl;
  t->set(2, "2");
  std::cout << "El largo de la tabla es " << t->size() << std::endl;

  std::cout << "Agrego el 3" << std::endl;
  t->set(3, "3");
  std::cout << "El largo de la tabla es " << t->size() << std::endl;

  std::cout << "Agrego el 4" << std::endl;
  t->set(4, "4");
  std::cout << "El largo de la tabla es " << t->size() << std::endl;
}
