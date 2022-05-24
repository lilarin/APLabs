#include <stdio.h>

int digitsSum(int value) {
    int sum = 0;
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}
int main() {
    int value;
    printf("Enter the value:");
    scanf("%d", &value);

    printf("Sum of digits is: %d", digitsSum(value));
    return 0;
}