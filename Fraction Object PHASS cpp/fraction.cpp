#include "fraction.h"

// Helper function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduce function to simplify fraction
void Fraction::reduce() {
    int gcdVal = gcd(abs(this->numerator), abs(this->denominator));
    this->numerator /= gcdVal;
    this->denominator /= gcdVal;
    if (this->denominator < 0) { // Handle negative denominator
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}

// Default constructor
Fraction::Fraction() : numerator(0), denominator(1) {}

// Parameterized constructor
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        cout << "Error: Denominator cannot be zero. Setting fraction to 0/1." << endl;
        this->numerator = 0;
        this->denominator = 1;
    }
    else {
        this->reduce();
    }
}

// Setters and getters with validation
bool Fraction::setNumerator(int num) {
    this->numerator = num;
    this->reduce();
    return true;
}

bool Fraction::setDenominator(int den) {
    if (den == 0) {
        cout << "Error: Denominator cannot be zero." << endl;
        return false;
    }
    this->denominator = den;
    this->reduce();
    return true;
}

int Fraction::getNumerator() const {
    return this->numerator;
}

int Fraction::getDenominator() const {
    return this->denominator;
}

// Overloaded addition operator
Fraction Fraction::operator+(const Fraction& other) const {
    int num = this->numerator * other.denominator + other.numerator * this->denominator;
    int den = this->denominator * other.denominator;
    return Fraction(num, den);
}

// Overloaded subtraction operator
Fraction Fraction::operator-(const Fraction& other) const {
    int num = this->numerator * other.denominator - other.numerator * this->denominator;
    int den = this->denominator * other.denominator;
    return Fraction(num, den);
}

// Overloaded multiplication operator
Fraction Fraction::operator*(const Fraction& other) const {
    int num = this->numerator * other.numerator;
    int den = this->denominator * other.denominator;
    return Fraction(num, den);
}

// Overloaded division operator
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        cout << "Error: Division by zero." << endl;
        return Fraction(0, 1); // Return default fraction if divide by zero
    }
    int num = this->numerator * other.denominator;
    int den = this->denominator * other.numerator;
    return Fraction(num, den);
}

// Overloaded stream insertion operator for output
ostream& operator<<(ostream& outputStream, const Fraction& frac) {
    outputStream << "  " << frac.numerator << endl
    << "-----" << endl << "  " << frac.denominator;
    return outputStream;
}
