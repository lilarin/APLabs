#include <iostream>

using namespace std;

void triangleOfPascal(int tail, int head, int *arr, int &position);
void fillEncodedString (int *arr,string& str,string& encodedString,int lengthOfString);
void encode(string& str,string& encodedString,int lengthOfString);
void print(string encodedString);

int main()
{
    string str,encodedString;
    cout << "Type text to encode" << endl;
    cin >> str;
    int lengthOfString = str.length();
    encode(str,encodedString,lengthOfString);
    cout << "Encoded text:" << endl;
    print(encodedString);
}

void triangleOfPascal(int tail, int head, int *arr, int &position) {
    int x = 1;
    for (int k = 0; k <= tail-head-1; k++) {
        arr[position]=x;
        x = x * ((tail-head-1) - k) / (k + 1);
        position++;
    }
    arr[position]=0;
    position++;

    // Генерую трикутник паскаля та зберігаю його значення у масив.
    // Основа ідея - Для кожного символу у строці, за індексом я паралельно
    // зберігаю кількість повторів, які потрібно буде зробити для кодування
}

void encode(string& str,string& encodedString,int lengthOfString) {
    int head=0,tail=0,position = 0;
    int arr[100];

    for (int i=0; i <= lengthOfString; i++) {
        if (str[i]=='_' || i == lengthOfString) {
            triangleOfPascal(tail,head,arr,position);
            head = i+1;
            tail++;
        }
        else {
            tail++;
        }
    }
    // Тут я пройшов по всій строці та вже сгенерував дзеркальний масив чисел, з яким буду працювати

    fillEncodedString(arr,str,encodedString,lengthOfString); // Викликаю функцію для заповнення нової строки
}

void fillEncodedString (int* arr,string& str,string& encodedString,int lengthOfString) {
    for (int i=0; i < lengthOfString; i++) {
        if (arr[i]==0) {
            encodedString.push_back('_');
        }
        for (int j=0; j < arr[i]; j++) {
            encodedString.push_back(str[i]);
        }
    }

    // Заповнив нову строку
}

void print(string encodedString) {
    int lengthOfEncodedString = encodedString.length();
    for (int i=0; i < lengthOfEncodedString; i++) {
        cout << encodedString[i];
    }

    // Друкую нову строку із зашифрованим текстом
}