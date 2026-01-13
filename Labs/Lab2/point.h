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
            /// @brief Constructor for Point
            /// @param  X int
            /// @param  Y int
            /// @param  closestPoint Point* 
            Point(int = 0, int = 0, Point* = nullptr);
            /// @brief Destructor for Point (not needed for this lab)
            ~Point();

            //Getters
            
            /// @brief Getter for private attribute x
            /// @return int
            int getX();
            /// @brief Getter for private attribute y
            /// @return int
            int getY();
            /// @brief Getter for private attribute nearestPoint
            /// @return Point*
            Point* getNearestPoint();

            //Setters

            /// @brief Setter for private attribute x
            /// @param  X int
            void setX(int);
            /// @brief Setter for private attribute y
            /// @param  Y int
            void setY(int);
            /// @brief Setter for private attribute nearestPoint
            /// @param  newNearestPoint Point*
            void setNearestPoint(Point*);

            /// @brief This calculates the nearest point given an array of Point*.\n
            /// @brief Should loop through every point, calculate the distance from this to the point\n
            /// @brief and update nearestPoint with the correct Point*
            /// @param  points Point*[]
            /// @param  arrSize unsigned long 
            /// @return Point*
            Point* calcNearestPoint(Point*[], unsigned long);
            /// @brief Calculates the euclidean distance between this and the passed in point
            /// @param  point Point&
            /// @return double
            double distPoints(Point&);
    };
}