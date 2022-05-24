#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int size, i, j;
    printf("Enter the number of elements in the line:\n");
    scanf("%d", &size);
    int arr[size * size];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            arr[size * i + j] = rand() % 9 + 1;
            printf("%d ", arr[size * i + j]);
        }
        printf("\n");
    }printf("\n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if (j<i) {
                printf("  ");
            }
            else {
                printf("%d ", arr[size * i + j]);}
        }
        printf("\n");
    }
    return 0;
}