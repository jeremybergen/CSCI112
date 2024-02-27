#include <cassert>
#include "fractions.h"

void tests();

int main(int argc, char* argv[])
{
    if(argc >= 2 && (string)argv[1] == "test")
    {
        tests();
        return 0;
    }

    cout << "Fraction 1: " << endl;
    fractions::Fraction frac1;
    cout << "Fraction 2: " << endl;
    fractions::Fraction frac2;

    cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << endl;
    cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << endl;
    cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << endl;
    cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << endl;

    return 0;
}

void tests()
{
    //test1
    fractions::Fraction testFrac1(2, 3);
    fractions::Fraction testFrac2(3, 5);
    fractions::Fraction ansFrac(0, 1);
    ansFrac = testFrac1 + testFrac2;
    assert(ansFrac == fractions::Fraction(19, 15));
    ansFrac = testFrac1 - testFrac2;
    assert(ansFrac == fractions::Fraction(1, 15));
    ansFrac = testFrac1 * testFrac2;
    assert(ansFrac == fractions::Fraction(2, 5));
    ansFrac = testFrac1 / testFrac2;
    assert(ansFrac == fractions::Fraction(10, 9));

    fractions::Fraction testFrac3(5, 7);
    fractions::Fraction testFrac4(-2, 9);
    ansFrac = testFrac3 + testFrac4;
    assert(ansFrac == fractions::Fraction(31, 63));
    ansFrac = testFrac3 - testFrac4;
    assert(ansFrac == fractions::Fraction(59, 63));
    ansFrac = testFrac3 * testFrac4;
    assert(ansFrac == fractions::Fraction(-10, 63));
    ansFrac = testFrac3 / testFrac4;
    assert(ansFrac == fractions::Fraction(45, -14));
    cout << "All test cases passed" << endl;
}