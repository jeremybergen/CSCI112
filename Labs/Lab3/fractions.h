#pragma once
#include <iostream>

using namespace std;

namespace fractions
{
    class Fraction {
        private:
            int _numerator;
            int _denominator;

        public:
            /*
            Constructor for Fraction.
            Default: 0/1

            Must check to verify denominator is not 0
            */
            Fraction(int = 0, int = 0);
            

            /*
            Function to simplify Fraction to the GCD.
            Should call gcd method from inside simplify

            Overloaded method is static so it can be called without instantiating class
            Takes in a Fraction and returns a simplified Fraction
            */
            void simplify();
            static Fraction simplify(Fraction);

            /*
            Calculate the greatest common divisor

            Find min(a, b)
            Assume that the greatest is 1 and start at 1
            while i <= min, if a and b % i == 0, that's the gcd
            otherwise increment i

            Alternatively, recursively call the method, passing in b, a%b and return a when b == 0
            */
            static int gcd(int, int);

            // Operator overloading
            /*
            Each overload should calculate a new fraction from this and the passed in fraction
            make sure you simplify the fraction after calculating the new fraction.
            Return new fraction

            Keep note that creating an instance of a fraction inside of the fraction class will have
            access to private attributes!
            */
            Fraction operator+(Fraction const&);
            Fraction operator-(Fraction const&);
            Fraction operator*(Fraction const&);
            Fraction operator/(Fraction const&);

            /*
            Returns true if both this and passed in fraction are equal
            */
            bool operator==(Fraction const&);

            /*
            Build output for when the << operator is called on a fraction
            */
            friend ostream& operator<<(ostream&, const Fraction&);
    };

    //This is to remove the warning about the friend overload not declared in fractions namespace
    ostream& operator<<(ostream&, const Fraction&);
}