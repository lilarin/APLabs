#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void createFiles(char *fileName,char *newFileName);
void fillFile(char *fileName);
void writeStr(char* str,char *newFileName);
void readFile (char *fileName,char *newFileName,char *str);
int isEmpty(char *newFileName);
void readNewFile(char *newFileName);

FILE *writeBuffer;
FILE *readBuffer;

int main() {
    srand(time(NULL));
    char fileName[8]={"F"},newFileName[8]={"G"};
    strcat(fileName,".txt");  // об'єдную два рядка, шлях до
    strcat(newFileName,".txt"); // файлу та його розширення

    char str[100]; //рядок, у який вводять дані
    puts("Input string to find:");
    gets(str);

    createFiles(fileName,newFileName); // Створюю два файли
    fillFile(fileName); // Заповнюю файл випадковими значеннями
    readFile(fileName,newFileName,str); // Зчитую старий файл
    readNewFile(newFileName);  //  Якщо вони є - записую їх у новий файл

    return 1;
}

void createFiles(char *fileName,char *newFileName)
{	  				// створюю(якщо не існує)
    writeBuffer = fopen(fileName, "w"); // та відкриваю файл
    fclose(writeBuffer); // закриваю файл
    writeBuffer = fopen(newFileName, "w");
    fclose(writeBuffer);
}

void fillFile(char *fileName) {
    const int minWordLength = 2,maxWordLength = 6,maxSymbolInFile = 1048576;
    writeBuffer = fopen(fileName, "w");
    int currentWordLength = minWordLength + rand() % (maxWordLength - minWordLength),symbolsInFile = 0;
    while (symbolsInFile<maxSymbolInFile)
    {
        if (!currentWordLength)
        {
            fputc('\n',writeBuffer); // якщо довжина слова досягнута -
            symbolsInFile++;		// переходжу на новий рядок
            currentWordLength = minWordLength + rand() % (maxWordLength - minWordLength);
        }
        fputc((char)((rand() % ('z' - 'a' + 1)) + 'a'),writeBuffer);
        currentWordLength--; // генерую випадкову букву
        symbolsInFile++;
    }
    fclose(writeBuffer);
}


void readFile (char *fileName,char *newFileName,char *str) {
    readBuffer = fopen(fileName, "a+");
    char tempStr[100];
    int counter = 0,legthofCurrentWord,lengthOfWord;
    while(!feof(readBuffer)) // доки не закінчиься файл
    {
        fgets(tempStr, 256, readBuffer); // отримую рядок
        if (feof(readBuffer)) {
            break;
        }
        legthofCurrentWord = strlen(tempStr)-1;
        lengthOfWord = strlen(str);
        if (legthofCurrentWord==lengthOfWord && strncmp (tempStr, str, lengthOfWord)==0) {
            writeStr(tempStr,newFileName); // якщо слова співпадають -
            counter++;                     // записую слово зі старого 					     // файлу у новий
        }
    }
    if (counter>0) { // якщо були знайдені слова
        itoa(counter,tempStr,10); // int to string
        writeStr(tempStr,newFileName);
    }
    fclose(writeBuffer);
}

void writeStr(char* str,char *newFileName) {
    writeBuffer = fopen(newFileName, "a+");
    fputs(str,writeBuffer); //записую рядок у файл
    fclose(writeBuffer);
}

void readNewFile(char *newFileName) {
    if (!isEmpty(newFileName)) { // перевіряю чи містить файл дані
        readBuffer = fopen(newFileName, "a+");
        char str[100];
        printf("Data inside new file:\n");
        do {
            fgets(str, 256, readBuffer);
            printf("%s", str);
        }
        while(!feof(readBuffer));
    }
}

int isEmpty (char *newFileName) {
    readBuffer = fopen(newFileName, "r");
    fseek (readBuffer, 0, SEEK_END);
    int size = ftell(readBuffer);
    if (0 == size) {
        printf("No matches. New file is empty.\n");
        return 1;
    }
    return 0;
}
