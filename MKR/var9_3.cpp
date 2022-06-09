// Прізвище: Кракович
// Група: ДА-12
// Середовище розробки: Clion
// Завдання: var9_3

#include <iostream>

using namespace std;

double calculateFactorial(int number) {
    if (number == 0) {                                        // Якщо число 0,
        return 1;                                             // Повертаємо факторіал 0
    } else {                                                  // В іншому випадку
        return number *  calculateFactorial(number - 1);      // Продовжуємо рекурсію
    }
}

int calculatePower(int base, int powerRaised)
{
    if (powerRaised != 0) {
        return (base*calculatePower(base, powerRaised-1));
    }
    else {
        return 1;
    }
}

double recursionMethod(double eps, int x,int n) {
    if ((calculatePower(x,n)/ calculateFactorial(n)) < eps) { // Якщо член ряду менше eps
        return 0;                                             // виходимо з рекурсії
    }                                                         // В іншому випадку
    else {                                                    // Продовжуємо рекурсію
        return (calculatePower(x,n) /  calculateFactorial(n)) + recursionMethod(eps, x, n + 1);
    }
}

double iterativeMethod(double eps, int x) {
    double sum=0;
    int n=1;

    while ((calculatePower(x,n)/ calculateFactorial(n)) > eps) {// Поки член ряду менший за eps
        sum += (calculatePower(x,n)/ calculateFactorial(n));    // Додаємо член ряду до суми
        n += 1;
    }
    return sum;
}

int main()
{
    double eps;
    int x,n = 1;
    cout << "Type eps:" << endl;
    cin >> eps;
    cout << "Iterative method:" << endl;
    while (x < 10) {
        cout << "X = " << x << "; Iterative: " << iterativeMethod(eps,x) << "; Recursion: " << recursionMethod(eps,x,n) << endl;
        x++;
    }
    return 0;
}