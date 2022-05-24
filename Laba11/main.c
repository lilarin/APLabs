#include <stdio.h>

int main() {
    char str[100];
    puts("Type string:");
    gets(str);

    int lineSize = sizeof(str);
    for (int j=0; j<lineSize; j++) {
        int temp = j;
        if (str[j] == '.') {
            for (int k=lineSize - 2; k > j; k--) {
                str[k] = str[k-1];
                str[k+1] = str[k];
            }
            str[temp+1] = '.';
            str[temp+2] = '.';
            j+=2;
        }
    }
    printf("New string: \n%s",str);
    return 0;
}
