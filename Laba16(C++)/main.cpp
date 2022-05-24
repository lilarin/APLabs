#include <iostream>
#include <cstdarg>

using namespace std;

double getsum (int count, ...)
{
    va_list args; // Вiдкриваю список параметр?в
    va_start (args, count); // Встановлюю вказiвник args та кажу розмiр масиву

    double sum = 0;
    double *num;

    num = va_arg(args, double*); // передаю N значень з макроса
    for (int i = 0; i < count; i++) {
        sum += num[i];
    }

    va_end(args); // Закриваю список параметр?в
    return sum;
}


int main() {
    int size=0;
    double *arr = new double[10],number;   //Створюю масив, у якому буду зберiгати числа, якi введе користувач
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
    // передаю у функцiю розмiр масиву та числа, з якими буду працювати
    // arr тут виступає аналогом n-ої кiлькостi чисел, якi ми паредаємо
    // у всiх прикладах подiбнi функцiї передають фiксовану кiлькiсть аргументiв,
    // а приймають один параметр - кiлькiсть аргументiв. Оскiльки в завданнi потрiбно
    // передати N елементiв, я першим аргументом явно передаю розмiр масиву, а другим сам масив.
    // Функцiя приймає першим параметром кiлькiсть аргументiв, а далi за допомогою макросу
    // обробки змiнного числа параметрiв, я обраховую суму чисел.

    cout << "Sum is: " <<sum;
    delete[] arr;
}