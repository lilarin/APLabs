#include <iostream>
#include <cstdarg>

using namespace std;

double getsum (int count, ...)
{
    va_list args; // �i��ਢ�� ᯨ᮪ ��ࠬ���?�
    va_start (args, count); // ��⠭����� ����i���� args � ���� ஧�i� ��ᨢ�

    double sum = 0;
    double *num;

    num = va_arg(args, double*); // ��।�� N ���祭� � �����
    for (int i = 0; i < count; i++) {
        sum += num[i];
    }

    va_end(args); // ���ਢ�� ᯨ᮪ ��ࠬ���?�
    return sum;
}


int main() {
    int size=0;
    double *arr = new double[10],number;   //�⢮��� ��ᨢ, � 类�� ��� ����i��� �᫠, �i ����� �����㢠�
    cout << "Type numbers to sum and type 0 to stop:" << endl;
    for (int i=0;true;i++) {
        cin >> number;
        if (number == 0) {
            break;
        }
        arr[i]=number;
        size++;
    }

    double sum = getsum(size,arr);
    // ��।�� � �㭪�i� ஧�i� ��ᨢ� � �᫠, � 直�� ��� ����
    // arr ��� ����㯠� �������� n-�� �i�쪮��i �ᥫ, �i �� ��।��
    // � ��i� �ਪ����� ���i��i �㭪�i� ��।���� �i�ᮢ��� �i��i��� ��㬥��i�,
    // � �਩����� ���� ��ࠬ��� - �i��i��� ��㬥��i�. ��i�쪨 � �������i ����i���
    // ��।�� N �������i�, � ���訬 ��㬥�⮬ � ��।�� ஧�i� ��ᨢ�, � ��㣨� ᠬ ��ᨢ.
    // �㭪�i� �਩��� ���訬 ��ࠬ��஬ �i��i��� ��㬥��i�, � ���i �� ��������� ������
    // ��஡�� ��i����� �᫠ ��ࠬ���i�, � ���客�� ��� �ᥫ.

    cout << "Sum is: " <<sum;
    delete[] arr;
}