#include <iostream>
#include <sstream>
#include <cassert>
#include <fstream>
#include "tree.h"
#include "word.h"

using namespace std;

void test();
void readWord(string &, BST<Word> &);

int main(int argc, char *argv[])
{
    if (argc == 2 && (string)argv[1] == "test")
    {
        test();
        return 0;
    }

    ifstream fin;
    string fileName;

    cout << "Enter the path to a file to read in: ";
    getline(cin, fileName);

    fin.open(fileName);
    if (!fin.is_open())
    {
        cout << "File failed to open" << endl;
        return 0;
    }
    string tmpWord;

    BST<Word> *myTree = new BST<Word>();

    while (fin >> tmpWord)
    {
        readWord(tmpWord, *myTree);
    }

    myTree->inOrder();
    cout << endl;

    fin.close();
    delete myTree;
    return 0;
}

void readWord(string &inWord, BST<Word> &myTree)
{
    while (inWord.size() > 0 && (tolower(inWord.at(0)) < 'a' || tolower(inWord.at(0)) > 'z'))
    {
        inWord.erase(0, 1);
    }
    while (inWord.size() > 0 && (tolower(inWord.at(inWord.size() - 1)) < 'a' || tolower(inWord.size() - 1) > 'z'))
    {
        inWord.erase(inWord.size() - 1, 1);
    }

    if (inWord.size() > 0)
    {
        for (size_t i = 0; i < inWord.size(); i++)
        {
            inWord.at(i) = tolower(inWord.at(i));
        }
    }

    // Creating a word for checking if it exists in the tree. This word will not be saved as the tree will create its own node with the data
    Word newWord(inWord, 1);

    if (myTree.search(newWord))
    {
        myTree.increment(newWord);
    }
    else
    {
        myTree.insert(newWord);
    }
}

void test()
{
    BST<Word> *myTree = new BST<Word>();
    BST<Word> *myTree2 = new BST<Word>();

    stringstream buffer;
    ifstream fin("test1.txt");
    string token;
    while (fin >> token)
    {
        readWord(token, *myTree);
    }
    fin.close();
    string sampleWords = "a:3 another:1 be:2 count:3 final:1 is:4 on:2 program:3 sample:1 sentence:3 that:1 the:2 this:3 to:2 used:3 word:3 ";
    streambuf *backup = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    myTree->inOrder();
    string test1 = buffer.str();
    buffer.str(string());
    assert(test1 == sampleWords);

    fin.open("test2.txt");

    while (fin >> token)
    {
        readWord(token, *myTree2);
    }
    myTree2->inOrder();
    fin.close();
    sampleWords = "a:5 amazingly:1 an:1 ape-descended:1 are:2 arm:1 at:2 backwaters:1 blue-green:1 chuck:2 could:2 digital:1 distance:1 end:1 far:1 forms:1 galaxy:1 how:1 idea:1 if:1 in:1 insignificant:1 is:1 lies:1 life:1 little:1 miles:1 million:1 much:1 neat:1 ninety-eight:1 of:4 orbiting:1 out:1 planet:1 pretty:1 primitive:1 roughly:1 sea:1 seashore:1 sells:1 she:1 shells:1 small:1 so:1 spiral:1 still:1 sun:1 that:1 the:5 they:1 think:1 this:1 uncharted:1 unfashionable:1 unregarded:1 utterly:1 watches:1 western:1 whose:1 wood:2 woodchuck:2 yellow:1 a:5 amazingly:1 an:1 ape-descended:1 are:2 arm:1 at:2 backwaters:1 blue-green:1 chuck:2 could:2 digital:1 distance:1 end:1 far:1 forms:1 galaxy:1 how:1 idea:1 if:1 in:1 insignificant:1 is:1 lies:1 life:1 little:1 miles:1 million:1 much:1 neat:1 ninety-eight:1 of:4 orbiting:1 out:1 planet:1 pretty:1 primitive:1 roughly:1 sea:1 seashore:1 sells:1 she:1 shells:1 small:1 so:1 spiral:1 still:1 sun:1 that:1 the:5 they:1 think:1 this:1 uncharted:1 unfashionable:1 unregarded:1 utterly:1 watches:1 western:1 whose:1 wood:2 woodchuck:2 yellow:1 ";

    cout.rdbuf(buffer.rdbuf());
    myTree2->inOrder();
    string test2 = buffer.str();
    buffer.str(string());
    cout.rdbuf(backup);

    assert(test2 == sampleWords);

    cout.rdbuf(backup);
    cout << "All test cases passed" << endl;

    delete myTree;
    delete myTree2;
}
