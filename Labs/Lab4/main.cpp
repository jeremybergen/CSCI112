#include <iostream>
#include <cassert>
#include "list.h"

using namespace std;

void test();

int main(int argc, char* argv[])
{
    if(argc >= 2 && (string)argv[1] == "test")
    {
        test();
        return 0;
    }
    List<int> myList;
    int insertNumber = 0;

    cout << "Enter -999 to quit entering elements: ";
    cin >> insertNumber;
    while(insertNumber != -999)
    {
        
        myList.push_back(insertNumber);
        cout << "Enter -999 to quit entering elements: ";
        cin >> insertNumber;
    }
    
    cout << "You entered " << myList.size() << " elements." << endl;
    cout << "The first element is: " << myList.front() << endl;
    cout << "The last element is: " << myList.back() << endl;
    cout << "The entire list is: " << myList << endl;
    
    cout << endl;
    cout << "Removing the first element: " << myList.pop_front() << endl;
    cout << "Removing the last element: " << myList.pop_back() << endl;
    cout << "The size of the list now is: " << myList.size() << endl;
    cout << "The entire list is now: " << myList << endl;

    return 0;
}

void test()
{
    List<int> testList1;
    size_t listSize = 10;
    for(size_t i = 0; i < listSize; i++)
    {
        testList1.push_back(i*42);
        assert(testList1.size() == i + 1);
    }
    assert(testList1.empty() == false);
    assert(testList1.size() == 10);
    for(size_t i = 0; i < listSize; i++)
    {
        assert((size_t)testList1.pop_front() == i*42);
        assert(testList1.size() == listSize - i - 1);
    }
    assert(testList1.empty() == true);

    cout << "All test cases passed" << endl;
}