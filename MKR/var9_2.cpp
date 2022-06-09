// Прізвище: Кракович
// Група: ДА-12
// Середовище розробки: Clion
// Завдання: var9_2

// Аналіз задачі:
// Одиничний біт - 1. Щоб порахувати їх кількість у числі, потрібно перетворити
// число з десяткового запису у двійковий та пройти циклом по числу з умовою для лічильника

#include <iostream>

using namespace std;

// Переведення числа у двійкову систему числення
int DecimalToBinary(int decimalNumber)
{
    int binaryNumber = 0, remainder, product = 1;              // У рядку 13 ми ініціалізуємо змінні
    while (decimalNumber != 0) {                               // Бінарного числа, залишку та добутку
        remainder = decimalNumber % 2;
        binaryNumber = binaryNumber + (remainder * product);   // З рядків з 14 по 19 ми ініціалізуємо цикл while.
        decimalNumber = decimalNumber / 2;                     // У циклі ми обчислюємо залишки та частки для
        product *= 10;                                         // перетворення десяткового числа у двійковий еквівалент
    }
    return binaryNumber;
}
// лік одиничних бітів
int countingSingleBits(int decimalNumber)
{
    int count = 0;
    int BinaryNumber = DecimalToBinary(decimalNumber);
    int bit;

    // У циклі ми обчислюємо поки в числі залишились біти
    while (BinaryNumber > 0)
    {
        bit = BinaryNumber % 10;    // беремо крайній правий біт
        BinaryNumber /= 10;         // відкидаємо цей біт
        if (bit == 1) {     // якщо він рівний 1
            count++;        // оновлюємо лічильник
        }
    }

    return count;
}

int main()
{
    int number;
    cout << "Type number:" << endl;
    cin >> number;
    cout << "Amount of single bits: " << countingSingleBits(number) << std::endl;

    return 0;
}