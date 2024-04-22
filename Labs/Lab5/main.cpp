#include <iostream>
#include "tree.h"
#include <sstream>
#include <cassert>

using namespace std;

void test();

int main(int argc, char* argv[])
{
    if (argc == 2 && (string)argv[1] == "test")
    {
        test();
        return 0;
    }

    BST<int> *myTree = new BST<int>();
    int nodeVal;
    char delAgain = 'y';

    do
    {

        cout << "Enter a value to add to the tree. Enter -999 to stop: ";
        cin >> nodeVal;
        if (nodeVal == -999)
            break;
        myTree->insert(nodeVal);
        myTree->inOrder();
        cout << endl;
    } while (true);

    myTree->inOrder();
    cout << endl;

    do
    {
        cout << "What node do you want to delete? ";
        cin >> nodeVal;
        if (myTree->search(nodeVal))
        {
            cout << "removing: " << nodeVal << endl;
            myTree->remove(nodeVal);
        }
        else
        {
            cout << "Node not found" << endl;
        }
        myTree->inOrder();
        cout << endl;
        cout << "Do you want to delete another? ";
        cin >> delAgain;
    } while (tolower(delAgain) == 'y');

    delete myTree;
    return 0;
}

void test()
{
    stringstream buffer;
    BST<int>* myTree = new BST<int>();
    int numbers1[10] = {37, 95, 67, 87, 39, 27, 25, 8, 74, 30};
    int numbers2[10] = {77, 41, 31, 35, 12, 80, 32, 59, 51, 83};
    int numbers3[10] = {92, 64, 10, 47, 39, 16, 70, 19, 52, 84};
    for(int num : numbers1)
    {
        myTree->insert(num);
    }
    streambuf* backup = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    myTree->inOrder();
    string test1 = buffer.str();
    buffer.str(string());
    
    BST<int>* myTree2 = new BST<int>();
    for(int num : numbers2)
    {
        myTree2->insert(num);
    }
    myTree2->inOrder();
    string test2 = buffer.str();
    buffer.str(string());

    BST<int>* myTree3 = new BST<int>();
    for(int num : numbers3)
    {
        myTree3->insert(num);
    }
    myTree3->inOrder();
    string test3 = buffer.str();
    buffer.str(string());
    cout.rdbuf(backup);


    assert(test1 == "8 25 27 30 37 39 67 74 87 95 ");
    assert(test2 == "12 31 32 35 41 51 59 77 80 83 ");
    assert(test3 == "10 16 19 39 47 52 64 70 84 92 ");
    cout << "All test cases passed" << endl;
    delete myTree;
    delete myTree2;
    delete myTree3;
}
