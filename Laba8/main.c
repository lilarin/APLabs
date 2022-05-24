#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int lines,columns, min=10;
    do {
        printf("Enter the number of elements in the line:\n");
        scanf("%d", &lines);
        printf("Enter the number of elements in the column:\n");
        scanf("%d", &columns);
        if (lines!=columns) {
            printf("Error.\n");
        }
    } while (lines!=columns);
    int arr[lines][columns];

    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < lines; ++j) {
            arr[i][j] = rand() % 9 + 1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (arr[i][j]<min) {
                min = arr[i][j];
            }
        }
        printf("%d ", min);
        min = 10;
    }
    return 0;
}