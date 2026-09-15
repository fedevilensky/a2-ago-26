#pragma once

template <class T> class iterator{
public:
    // hasNext me dice si puedo seguir llamando a next() sin
    // que se rompa
    virtual bool hasNext() = 0;
    // next me devuelve el siguiente elemento
    // (y avanza el iterador)
    virtual T next() = 0;
};

template <class T> class iterable{
public:
    virtual iterator<T>* getIterator() = 0;
};

