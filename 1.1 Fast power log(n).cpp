#include <iostream>

double Power(double a, int n)
{
    // инвариант b^n * p = a^n
    double p = 1;
    double b = a;
    while (n > 0) {
        if ((n % 2) == 0) {
            n /= 2;
            b *= b;
        }
        else {
            n = n - 1;
            p *= b;
        }
    }
    return p;
}
int main()
{
    Power(3, 5);
}
