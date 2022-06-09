#include <iostream>
#include <cstdarg>

#define INPUT_NUMBERS( A, B, C, D, E ) {     \
int counter = 0;                             \
double input;                                \
cout << "Type 5 elements:" << endl;          \
cin >> A >> B >> C >> D >> E;                \
counter++;                                   \
}                                            \
cout << "Typed elements are: ";              \
cout << A << ", " << B << ", " << C          \
<< ", " << D << ", " << E << endl;           \

#define PRINT_SUM( SUM ) {                   \
cout << "Sum of numbers is: " << SUM << endl;\
}

using namespace std;

double getSum (int size, double first, ...) {
    double sum = 0, i = first;
    va_list marker;
    va_start( marker, first );
    for ( int counter = 0; counter < size; counter++ ) {
        sum += i;
        i = va_arg( marker, double);
    }
    va_end( marker );
    return sum;
}

int main() {
    double a, b, c, d, e;
    INPUT_NUMBERS( a, b, c, d, e )
    PRINT_SUM(getSum(5, a, b, c, d, e))
}