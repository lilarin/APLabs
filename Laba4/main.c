#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int sum=0, size=5;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (610 - 585) + 585;
        sum += arr[i];
    }

    for(int i = 0; i < size; ++i) {
        printf("Year: %d | Value: %d | Deviation: %d\n", i+1, arr[i], sum/size - arr[i]);
    }
    printf("Average = %d ", sum / size);
    return 0;
}
