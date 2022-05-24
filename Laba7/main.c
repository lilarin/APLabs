#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int size,number,sum=0;
    printf("Type amount of numbers:");
    scanf("%d",&size);
    for (int i=0; i<size; i++){
        number = rand() % 10;
        printf("%d\t", number);
        if (number%3==0){
            number *= number;
            sum += number;
        }
        else if (number%3==1) {
            sum += number;
        }
        else {
            number /= 3;
            sum += number;
        }
    }
    printf("\nSum is: %d", sum);

    return 0;
}
