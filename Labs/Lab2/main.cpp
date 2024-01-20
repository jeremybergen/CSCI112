#include "point.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <cassert>

using namespace std;

size_t getArrSize();
void generatePoints(points::Point*[], size_t);
void printPoints(points::Point*[], size_t);
points::Point* promptTestPoint();
void tests();

int main(int argc, char* argv[])
{
    if(argc >= 2 && (string)argv[1] == "test")
    {
        tests();
        return 0;
    }

    //Initialize random seed
    srand(time(0));

    size_t arrSize = 0;
    arrSize = getArrSize();

    points::Point* pointList[arrSize];

    cout << "Generating " << arrSize << " random points..." << endl;
    generatePoints(pointList, arrSize);
    printPoints(pointList, arrSize);


    points::Point* testPoint = promptTestPoint();

    testPoint->setNearestPoint(testPoint->calcNearestPoint(pointList, arrSize));

    cout << "The closest point to (" << testPoint->getX() << ", " << testPoint->getY() 
         << ") is (" << testPoint->getNearestPoint()->getX() << ", " << testPoint->getNearestPoint()->getY() 
         << ") with a distance of: " << testPoint->distPoints(*testPoint->getNearestPoint()) << "." << endl;

    // Cleanup
    for(size_t i = 0; i < arrSize; i++)
    {
        delete pointList[i];
    }
    delete testPoint;

    return 0;
}

void tests()
{
    const double epsilon = 1e-4;
    srand(42);

    size_t arrSize = 10;

    points::Point* pointList[arrSize];

    generatePoints(pointList, arrSize);
    points::Point* test1 = new points::Point(0, 0);
    points::Point* test2 = new points::Point(17, 4);
    points::Point* test3 = new points::Point(-100, 100);

    test1->setNearestPoint(test1->calcNearestPoint(pointList, arrSize));
    test2->setNearestPoint(test2->calcNearestPoint(pointList, arrSize));
    test3->setNearestPoint(test3->calcNearestPoint(pointList, arrSize));

    assert(abs(test1->distPoints(*test1->getNearestPoint()) - 17.4642) <= epsilon);
    assert(abs(test2->distPoints(*test2->getNearestPoint()) - 0) <= epsilon);
    assert(abs(test3->distPoints(*test3->getNearestPoint()) - 43.6807) <= epsilon);

    cerr << "All test cases passed" << endl;

    for(size_t i = 0; i < arrSize; i++)
    {
        delete pointList[i];
    }
    delete test1;
    delete test2;
    delete test3;
}

size_t getArrSize()
{
    size_t arrSize = 999;
    while(!(arrSize >= 0 && arrSize <= 100))
    {
        cout << "Enter the size of array of points to generate [0-100]: ";
        cin >> arrSize;
    }
    return arrSize;
}

void generatePoints(points::Point* pointList[], size_t arrSize)
{
    for(size_t i = 0; i < arrSize; i++)
    {
        points::Point* newPoint = new points::Point(rand()%200 - 100, rand()%200 - 100);
        pointList[i] = newPoint;
    }
}

void printPoints(points::Point* pointList[], size_t arrSize)
{
    for(size_t i = 0; i < arrSize; i++)
    {
        cout << setw(3) << i+1 << ": (" << pointList[i]->getX() << ", " << pointList[i]->getY() << ")" << endl;
    }
}

points::Point* promptTestPoint()
{
    int x = 999;
    int y = 999;
    while(!(x >= -100 && x <= 100))
    {
        cout << "Enter the X coordinate for a point [-100, 100]: ";
        cin >> x;
    }

    while(!(y >= -100 && y <= 100))
    {
        cout << "Enter the Y coordinate for a point [-100, 100]: ";
        cin >> y;
    }

    points::Point* newPoint = new points::Point(x, y);
    return newPoint;
}