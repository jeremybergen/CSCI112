#pragma once

template <class T1>
class Node
{
    private:
    T1 _data;
    Node<T1>* _left;
    Node<T1>* _right;

    public:
    Node();
    void setData(T1);
    void setLeft(Node<T1>*);
    void setRight(Node<T1>*);
    T1 getData();
    Node<T1>* getLeft();
    Node<T1>* getRight();
};

template <class T1>
Node<T1>::Node()
{
    _left = nullptr;
    _right = nullptr;
}

template <class T1>
void Node<T1>::setData(T1 data)
{
    _data = data;
}

template <class T1>
void Node<T1>::setLeft(Node<T1>* left)
{
    _left = left;
}

template <class T1>
void Node<T1>::setRight(Node<T1>* right)
{
    _right = right;
}

template <class T1>
T1 Node<T1>::getData()
{
    return _data;
}

template <class T1>
Node<T1>* Node<T1>::getLeft()
{
    return _left;
}

template <class T1>
Node<T1>* Node<T1>::getRight()
{
    return _right;
}