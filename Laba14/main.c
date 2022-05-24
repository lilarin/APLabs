#include <stdio.h>
#include <string.h>
#include "utility.h"

int main() {
    char* filepath = strcat(path, filename);
    clearFile(readbuffer, filepath);

    struct Object tempData[1];
    struct Object data[32];

    int user_input,index,numberOfElements=0;
    char dataToFind[16],answer;
    printf(
            "\tMenu\n"
            "[ 1 ] Add data\n"
            "[ 2 ] Edit data\n"
            "[ 3 ] Remove data\n"
            "[ 4 ] Display data\n"
            "[ 5 ] Find data (keyword)\n"
            "[ 6 ] Find data (by code)\n"
            "[ 7 ] Find biggest size\n"
            "[ 8 ] Fill file with data\n"
            "[ 9 ] Clear all data\n");
    do {
        user_input = getchar();
        switch (user_input) {
            case '1':
                do {
                    printf("Town:");
                    scanf("%s", data[0].town.name);
                    printf("University:");
                    scanf("%s", data[0].university.name);
                    printf("Speciality code:");
                    scanf("%d", &data[0].university.speciality);
                    printf("Faculty:");
                    scanf("%s", data[0].faculty.name);
                    printf("Speciality:");
                    getchar(); // Clear buffer
                    gets(data[0].faculty.speciality);
                    printf("Size:");
                    scanf("%d", &data[0].faculty.size);

                    printf("continue? (y/n)\n");
                    do {
                        answer = getchar();
                    } while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N');
                    writeData(writebuffer, filepath, &data[0], 1);
                    numberOfElements++;
                } while (answer != 'n' && answer != 'N');
                break;
            case '2':
                if (numberOfElements == 0) {
                    printf("File is empty:\n");
                    break;
                }
                printf("Type index of the element:\n");
                scanf("%d", &index);
                if (index > numberOfElements || index < 0) {
                    printf("Out of range.\n");
                    break;
                }
                printf("Town:");
                scanf("%s", tempData[0].town.name);
                printf("University:");
                scanf("%s", tempData[0].university.name);
                printf("Speciality code:");
                scanf("%d", &tempData[0].university.speciality);
                printf("Faculty:");
                scanf("%s", tempData[0].faculty.name);
                printf("Speciality:");
                getchar(); // Clear buffer
                gets(tempData[0].faculty.speciality);
                printf("Size:");
                scanf("%d", &tempData[0].faculty.size);
                editData(writebuffer, filepath, tempData, index);
                break;
            case '3':
                if (numberOfElements == 0) {
                    printf("File is empty:\n");
                    break;
                }
                printf("Enter index to delete:\n");
                scanf("%d", &index);
                deleteData(readbuffer, filepath, index);
                numberOfElements--;
                break;
            case '4':
                if (numberOfElements == 0) {
                    printf("File is empty.\n");
                    break;
                }
                printData(readbuffer, filepath);
                break;
            case '5':
                if (numberOfElements == 0) {
                    printf("File is empty.\n");
                    break;
                }
                printf("Enter keyword:");
                scanf("%s",dataToFind);
                findData(readbuffer, filepath, dataToFind);
                break;
            case '6':
                if (numberOfElements == 0) {
                    printf("File is empty.\n");
                    break;
                }
                printf("Enter speciality code:");
                scanf("%d",&index);
                printDataByNumber(readbuffer, filepath, index);
                break;
            case '7':
                if (numberOfElements == 0) {
                    printf("File is empty.\n");
                    break;
                }
                findBiggestSize(readbuffer, filepath);
                break;
            case '8':
                clearAndFillFile(readbuffer, filepath);
                printf("File filled.\n");
                numberOfElements = 5;
                break;
            case '9':
                clearFile(readbuffer, filepath);
                numberOfElements = 0;
                printf("File cleared.\n");
                break;
            default:;
        }
    }
    while (user_input != 0);
    return 0;
}