#pragma once

#include "list.cpp"
#include <cassert>

template <class T> class linkedList : public list<T> {
private:
  struct node{
    T data;
    node *next;

    node(T data){
      this->data = data;
    }
  };

  class linkedListIterator: public iterator<T>{
  private:
    node* curr;
  public:
    linkedListIterator(node* head){
      this->curr = head;
    }

    virtual bool hasNext() override{
      return this->curr != nullptr;
    }

    virtual T next() override{
      T elem = curr->data;
      curr = curr->next;
      return elem;
    }
  };

  node* head = nullptr;
  int count = 0;

public:
  linkedList(){}

  virtual iterator<T>* getIterator() override {
    return new linkedListIterator(this->head);
  }

  virtual void add(T data) override{
    count++;
    if(this->head == nullptr){
      this->head = new node(data);
      return
    }

    node aux = this->head;
    while(aux->next != nullptr){
      aux = aux->next;
    }
    aux->next= new node(data);
  }

  virtual int size() override{
    return count;
  }

  virtual T getPos(int p) override{
    assert(false)
  }
  virtual int findPos(T data) override{
    assert(false)
  }
  virtual void remove(T data) override{
    assert(false)
  }
  virtual void removePos(int pos) override{
    assert(false)
  }
  // TODO: implementar lista
};
