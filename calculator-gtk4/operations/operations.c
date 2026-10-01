#include "operations.h"
#include <math.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0.0) {
        return 0.0;
    }
    return a / b;
}

double modulo(double a, double b) {
    if (b == 0.0) {
        return 0.0;
    }
    return fmod(a, b);
}

double power(double a, double b) {
    return pow(a, b);
}

double square_root(double a) {
    if (a < 0.0) {
        return 0.0;
    }
    return sqrt(a);
}

double percentage(double a, double b) {
    if (b == 0.0) {
        return 0.0;
    }
    return (a * b) / 100.0;
}
