#pragma once

#include "../iterator/iterator.cpp"

struct edge {
  int from, to, weight;

  edge(int from, int to, int weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
  }

  bool operator==(const edge &other) {
    return this->from == other.from && this->to == other.to;
  }
};

class graph {
public:
  virtual void addEdge(int v, int w) = 0;
  virtual void addWeightedEdge(int v, int w, int weight) = 0;
  virtual void removeEdge(int v, int w) = 0;
  virtual void removeAllEdges(int v) = 0;
  virtual bool hasEdge(int v, int w) = 0;
  virtual edge getEdge(int v, int w) = 0;
  virtual iterator<edge> *getAllEdges() = 0;
  virtual iterator<edge> *getNeighbors(int v) = 0;
  virtual int **adjMatrix() = 0;
  // how many vertices there are in the graph
  virtual int V() = 0;
};
