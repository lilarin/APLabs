#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ExamResult{
    char surname[32];
    int mark;
};

int mark() {
    return rand() % 6 + 7;
}

int main() {
    srand(time(NULL));
    int markToSearch,count=0;
    printf("Type mark to search student:");
    scanf("%d",&markToSearch);
    struct ExamResult arr[10] = {
        {"Kyznetsov",mark()},
        {"Melnyk",mark()},
        {"Kirov",mark()},
        {"Illyk",mark()},
        {"Mariev",mark()},
        {"Pavlov",mark()},
        {"Sirev",mark()},
        {"Nikitov",mark()},
        {"Abramov",mark()},
        {"Dyshkin",mark()}
    };
    for (int i=0; i<10; i++) {
        printf("%s %d\n",arr[i].surname,arr[i].mark);
    }
    printf("\nList of students with mark: %d",markToSearch);
    for (int i=0; i<10; i++) {
        if (arr[i].mark == markToSearch) {
            printf("\n%s ",arr[i].surname);
            count += 1;
        }
    }
    if (count==0) {
        printf("\nThere is no student with that mark.");
    }
    return 0;
}