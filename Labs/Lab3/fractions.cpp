#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    return Fraction(0, 1);
}

void fractions::Fraction::simplify()
{
}

int fractions::Fraction::gcd(int a, int b)
{
    return 0;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}