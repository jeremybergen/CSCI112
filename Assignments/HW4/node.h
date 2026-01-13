#pragma once

template <class T1>
class Node
{
    private:
    T1 _data;
    Node<T1>* _prev;
    Node<T1>* _next;

    public:
    Node();
    void setData(T1);
    void setPrev(Node<T1>*);
    void setNext(Node<T1>*);
    T1 getData();
    Node<T1>* getPrev();
    Node<T1>* getNext();
};

template <class T1>
Node<T1>::Node()
{
    _prev = nullptr;
    _next = nullptr;
}

template <class T1>
void Node<T1>::setData(T1 data)
{
    _data = data;
}

template <class T1>
void Node<T1>::setPrev(Node<T1>* prev)
{
    _prev = prev;
}

template <class T1>
void Node<T1>::setNext(Node<T1>* next)
{
    _next = next;
}

template <class T1>
T1 Node<T1>::getData()
{
    return _data;
}

template <class T1>
Node<T1>* Node<T1>::getPrev()
{
    return _prev;
}

template <class T1>
Node<T1>* Node<T1>::getNext()
{
    return _next;
}