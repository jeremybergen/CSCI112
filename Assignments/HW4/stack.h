#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
    private:
        Node<double> *_top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(double);
        double pop();
        double top();
};

// set to nullptr and initialize stackSize
Stack::Stack()
{
}

// iteratively delete the stack starting at top
Stack::~Stack()
{
}

// return true if the Stack is empty, false otherwise.
// Do not just check stackSize, should actually check top
bool Stack::empty()
{
}

// return number of elements in Stack
size_t Stack::size()
{
}

// add an element to the beginning of the Stack, updating top
void Stack::push(double data)
{
}

// return the first element in the Stack.
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::top()
{
}

// remove the first element from the Stack and return its data
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::pop()
{
}