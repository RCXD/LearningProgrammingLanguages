#include <iostream>
using namespace std;

int myabs(int number)
{
    if (number < 0)
        number = -number;

    return number;
}
double myabs(double base, double exponent)
{
    double result = base;
    for (int i = 1; i < exponent; i++) {
        result *= base;
    }
}

void main() {
    double u = 2.5;
    double v = 3.0;
    double x, y, w;

    x = myabs(u, v);
    y = myabs(2.0, 3.2);
    w = myabs(u, 7);

    int abs = myabs(-0.5);
    cout << "absolute value of -0.5 is " << abs << endl;
}