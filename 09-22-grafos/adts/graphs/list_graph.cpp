#pragma once

#include "../list/linked_list.cpp"
#include "graph.cpp"
#include <cassert>

class list_graph : public graph {
private:
  int vertices;
  bool isDirected;
  list<edge> **listArr;

public:
  list_graph(int vertices, bool isDirected) {
    this->vertices = vertices;
    this->isDirected = isDirected;

    // inicializamos el array de listas
    this->listArr = new list<edge> *[vertices + 1];
    for (int i = 1; i <= vertices; i++) {
      this->listArr[i] = new linkedList<edge>();
    }
  }

  virtual void addEdge(int v, int w) override {
    //
    addWeightedEdge(v, w, 1);
  }

  virtual void addWeightedEdge(int v, int w, int weight) override {
    assert(v > 0);
    assert(v <= this->vertices);
    assert(w > 0);
    assert(w <= this->vertices);
    assert(weight != 0);

    edge newEdge = edge(v, w, weight);
    listArr[v]->remove(newEdge);
    listArr[v]->add(newEdge);

    if (!this->isDirected) {
      edge newEdge = edge(w, v, weight);
      listArr[w]->remove(newEdge);
      listArr[w]->add(newEdge);
    }
  }
  virtual void removeEdge(int v, int w) override { assert(false); }

  virtual void removeAllEdges(int v) override { assert(false); }

  virtual bool hasEdge(int v, int w) override { assert(false); }

  virtual edge getEdge(int v, int w) override { assert(false); }

  virtual iterator<edge> *getAllEdges() override {
    list<edge> *collection = new linkedList<edge>();

    for (int i = 1; i < this->vertices; i++) {
      iterator<edge> *it = this->listArr[i]->getIterator();
      while (it->hasNext()) {
        collection->add(it->next());
      }
    }

    return collection->getIterator();
  }

  virtual iterator<edge> *getNeighbors(int v) override {
    assert(v > 0);
    assert(v <= this->vertices);

    return this->listArr[v]->getIterator();
  }

  virtual int **adjMatrix() override {
    int **mat = new int *[this->vertices + 1];
    for (int i = 1; i <= this->vertices; i++) {
      mat[i] = new int[this->vertices + 1];
    }

    iterator<edge> *it = getAllEdges();
    while (it->hasNext()) {
      edge e = it->next();
      mat[e.from][e.to] = e.weight;
    }

    return mat;
  }

  // how many vertices there are in the graph
  virtual int V() override { return this->vertices; }
};
