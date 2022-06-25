// ��?����: �ࠪ����
// ��㯠: ��-12
// ��।���� ஧஡��: Clion
// ��������: var9_3

#include <iostream>

using namespace std;

double calculateFactorial(int number) {
    if (number == 0) {                                        // ��� �᫮ 0,
        return 1;                                             // ������� 䠪��?�� 0
    } else {                                                  // � ?�讬� �������
        return number *  calculateFactorial(number - 1);      // �த����� ४���?�
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
    if ((calculatePower(x,n)/ calculateFactorial(n)) < eps) { // ��� 童� ��� ���� eps
        return 0;                                             // ��室��� � ४���?�
    }                                                         // � ?�讬� �������
    else {                                                    // �த����� ४���?�
        return (calculatePower(x,n) /  calculateFactorial(n)) + recursionMethod(eps, x, n + 1);
    }
}

double iterativeMethod(double eps, int x) {
    double sum=0;
    int n=1;

    while ((calculatePower(x,n)/ calculateFactorial(n)) > eps) {// ���� 童� ��� ���訩 �� eps
        sum += (calculatePower(x,n)/ calculateFactorial(n));    // ����� 童� ��� �� �㬨
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