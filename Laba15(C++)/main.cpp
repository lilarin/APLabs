#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void createAndFill_File(const char* filename);
void createEmptyFile(const char* filename);
void searchForLetters(const char* fileG,const char* fileF,const char* fileH);
void readFile (const char* fileH);

int main()
{
    srand(time(nullptr));           // в ц?й робот?, нав?дм?ну
    const char* fileG = "../G.txt"; // в?д попередн?х я вир?шив
    const char* fileF = "../F.txt"; // одразу визначити назву та
    const char* fileH = "../H.txt"; // розширення файлу
    createAndFill_File(fileG);
    createAndFill_File(fileF);  // Створюю два файли та заповнюю їх
    createEmptyFile(fileH);  // Створюю порожн?й файл, куди буду записувати значення
    searchForLetters(fileG,fileF,fileH); // Шукаю зб?жност? та записую їх у новий файл
    readFile(fileH); // читаю вм?ст нового файлу

    return 1;
}

void createAndFill_File(const char* filename)
{
    const int minWordLength = 2,maxWordLength = 10,maxSymbolInFile = 1024;
    ofstream fin(filename);
    int currentWordLength = minWordLength + rand() % (maxWordLength - minWordLength),symbolsInFile = 0;
    while (symbolsInFile<maxSymbolInFile)
    {
        if (!currentWordLength)
        {
            fin << "\n"; // ставлю знак переходу на новий рядок
            symbolsInFile++;
            currentWordLength = minWordLength + rand() % (maxWordLength - minWordLength);
        }
        fin << (char)((rand() % ('z' - 'a' + 1)) + 'a'); // додаю випадкову букву
        currentWordLength--;
        symbolsInFile++;
    }
    fin.close();
}

void createEmptyFile(const char* filename)
{
    ofstream fout(filename);
    fout.close();
}

void searchForLetters(const char* fileG,const char* fileF,const char* fileH)
{
    ofstream fout(fileH); // в?дкриваю файл для запису
    ifstream finG(fileG); // в?дкриваю файли для читання
    ifstream finF(fileF);
    char g[10],f[10];
    int counter=0;
    while (finG.getline(g,10) && finF.getline(f,10))
    {
        counter++;
        if (g[0]==f[0])
        {
            fout << g[0] << "(" << counter << ") ";
        }
    }
    fout.close(); // закриваю вс? файли
    finG.close();
    finF.close();
}

void readFile (const char* fileH)
{
    ifstream fout(fileH);
    string str;
    while(fout >> str)
    {
        cout << str << " ";
    }
    fout.close();
}