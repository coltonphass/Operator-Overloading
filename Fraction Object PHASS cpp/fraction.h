#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    void reduce(); // Helper function to reduce fraction


public:
    // Constructors
    Fraction(); // Default constructor (0/1)
    Fraction(int num, int den); // Parameterized constructor

    // setters and getters
    bool setNumerator(int num);
    bool setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;


    // Arithmetic operator overloads
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Friend function for stream insertion
    friend ostream& operator<<(ostream& outputStream, const Fraction& frac);
};

#endif
