// Прізвище: Кракович
// Група: ДА-12
// Середовище розробки: Clion
// Завдання: var9_1

// Аналіз задачі:
// Для виконання завдання потрібно створити матрицю, заповнити її.
// Пройти по матриці та підрахувати суму за ключем та у випадку,
// якщо потрібно поміняти місцями рядки - міняємо.

#include <iostream>
#include <iomanip> // Для відступів при виведенні
#include <ctime>

using namespace std;

void swapElements (int *a, int *b) { // Міняю елементи місцями за допомогою власної функції
    int temp = *a;                   // Також, можна використовувати функцію swap(a,b)
    *a = *b;
    *b = temp;
}

void fillMatrix(int size,int *arr) {        // Заповнюю матрицю випадковими числами
    for(int i = 0; i < size; i++) {
        for(int j = 0; j <  size; j++) {
            arr[size*i+j] = rand() % 199 - 99;
        }
    }
}

void printMatrix(int size, int *arr) { // Друкую матрицю
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << arr[size*i+j] << " ";
        }
        cout << endl;
    }
}

//Рахую суму від’ємних непарних елемнтів стовпця
int countSumOfElements(int size,const int *arr, int column) {
    int sum = 0;
    for(int i = column; i < size; i+=3) {
        if(arr[i] % 2 == -1) {
            sum += arr[i];
        }
    }
    return sum;
}

void sortColumns(int size,int *arr) { // Сортую стовпці
    if (countSumOfElements(size,arr,0)>countSumOfElements(size,arr,1)) {
        for (int i = 0; i < size; i+=3) {
            swapElements(&arr[i], &arr[i+1]);
        }
    }
    if (countSumOfElements(size,arr,1)>countSumOfElements(size,arr,2)) {
        for (int i = 1; i < size; i+=3) {
            swapElements(&arr[i], &arr[i+1]);
        }
    }
    if (countSumOfElements(size,arr,0)>countSumOfElements(size,arr,1)) {
        for (int i = 0; i < size; i+=3) {
            swapElements(&arr[i], &arr[i+1]);
        }
    }
}

int main() {
    srand(time(nullptr));
    // Ініціалізую розмір матриці, ширину\довжину та масив(матрицю)
    int sizeOfMatrix = 3,sizeOfArray = sizeOfMatrix*sizeOfMatrix,*arr = new int[sizeOfArray];
    cout << "Matrix on the beginning:" << endl;
    fillMatrix(sizeOfMatrix,arr);
    printMatrix(sizeOfMatrix,arr);
    cout << "Matrix after sorting:" << endl;
    sortColumns(sizeOfArray,arr);
    printMatrix(sizeOfMatrix,arr);

    delete[] arr; // видаляю динамічний масив у кінці програми
    return 1;
}