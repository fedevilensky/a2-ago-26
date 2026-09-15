#include <iostream>
#include "adts/list/array_list.cpp"

void print(iterable<int>* iter) {
    iterator<int> * it = iter->getIterator();
    while(it->hasNext()){
        int i = it->next();
        std::cout << i << std::endl;
    }
}

int main(){
    list<int> *l  = new arrayList<int>(10);

    for (int i = 0; i<10;i++){
        l->add(i);
    }

    print(l);
}