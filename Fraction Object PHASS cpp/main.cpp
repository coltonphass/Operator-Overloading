#include <iostream>
#include "fraction.h"
using namespace std;

int main() {
    // Create fractions
    Fraction f1(4, 6);
    Fraction f2(4, 12);

    // Display fractions
    cout  << "Fraction 1: (simplified)" << endl << f1 << endl;
    cout << endl << "Fraction 2: (simplified) " << endl << f2 << endl;

    // Test arithmetic operations
    Fraction sum = f1 + f2;
    cout << endl << "Sum of f1 & f2: " << endl << sum << endl;

    Fraction diff = f1 - f2;
    cout << endl << "Difference between f1 & f2: " << endl << diff << endl;

    Fraction product = f1 * f2;
    cout << endl << "Product of f1 & f2: " << endl << product << endl;

    Fraction quotient = f1 / f2;
    cout << endl << "f1 divided by f2: " << endl << quotient << endl;

    return 0;
}
