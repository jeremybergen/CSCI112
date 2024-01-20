#pragma once
#include <cmath>
#include <iostream>

using namespace std;

namespace points
{
    class Point
    {
        private:
            int x;
            int y;
            Point* nearestPoint;

        public:
            //Constructor
            Point(int = 0, int = 0, Point* = nullptr);
            //Destructor
            ~Point();

            //Getters
            int getX();
            int getY();
            Point* getNearestPoint();

            //Setters
            void setX(int);
            void setY(int);
            void setNearestPoint(Point*);

            Point* calcNearestPoint(Point*[], unsigned long);
            double distPoints(Point&);
    };
}