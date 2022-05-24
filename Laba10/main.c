#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Заповнюємо двомірний масив випадковими знаеннями
void fillArray(int **arr, int columns, int lines) {
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < lines; ++j) {
            arr[i][j] = rand() % 9 + 1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Шукаємо у масиві потрібні значення та виводимо їх у консоль
void search(int **arr, int columns, int lines) {
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < lines; ++j) {
            if (arr[i][j]%3==0) {
                printf("%d ", arr[i][j]);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Видаляємо масив після всіх операцій з ним
void deleteArr(int **arr, int lines) {
    for(int k = 0; k < lines; k++) {
        free(arr[k]);
    }
    free(arr);
}

int main() {
    srand(time(NULL));
    int columns,lines;
    printf("Type number of elements in the first matrix:");
    scanf("%d %d",&columns, &lines);

    int **arr = (int **)malloc(lines*sizeof(int *));
    for(int i = 0; i < lines; i++) {
        arr[i] = (int *)malloc(columns*sizeof(int));
    }

    fillArray(arr,columns,lines);
    search(arr,columns,lines);

    printf("\nType number of elements in the second matrix:");
    scanf("%d %d",&columns, &lines);

    **arr = (int **)malloc(lines*sizeof(int *));
    for(int i = 0; i < lines; i++) {
        arr[i] = (int *)malloc(columns*sizeof(int));
    }
    fillArray(arr,columns,lines);
    search(arr,columns,lines);

    deleteArr(arr,lines);
    return 0;
}