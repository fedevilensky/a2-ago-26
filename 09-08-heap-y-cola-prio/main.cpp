#include "adts/priority_queue/min_priority_queue.cpp"
#include <iostream>
#include <ostream>
#include <string>

int main() {

  std::cerr << "Hola esto es un error" << std::endl;
  std::cout << "Cuantos elementos queres agregar?" << std::endl;
  int N;
  std::cin >> N;
  priorityQueue<std::string, int> *pq =
      new minPriorityQueue<std::string, int>(N);

  for (int i = 0; i < N; i++) {
    std::string elem;
    int prio;
    std::cin >> elem >> prio;
    pq->push(elem, prio);
    std::cout << "Elemento mas chico es: " << pq->top() << std::endl;
    std::cout << "El heap contiene " << pq->size() << " elementos" << std::endl;
  }

  while (!pq->isEmpty()) {
    std::cout << "Elemento mas chico es " << pq->pop() << std::endl;
  }
}
