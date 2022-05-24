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
    srand(time(nullptr));           // � �?� ஡��?, ���?��?��
    const char* fileG = "../G.txt"; // �?� ����।�?� � ���?訢
    const char* fileF = "../F.txt"; // ��ࠧ� ������� ����� �
    const char* fileH = "../H.txt"; // ஧�७�� 䠩��
    createAndFill_File(fileG);
    createAndFill_File(fileF);  // �⢮��� ��� 䠩�� � �������� ��
    createEmptyFile(fileH);  // �⢮��� ��஦�?� 䠩�, �㤨 ��� �����㢠� ���祭��
    searchForLetters(fileG,fileF,fileH); // �㪠� ��?�����? � ������� �� � ����� 䠩�
    readFile(fileH); // ��� ��?�� ������ 䠩��

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
            fin << "\n"; // �⠢�� ���� ���室� �� ����� �冷�
            symbolsInFile++;
            currentWordLength = minWordLength + rand() % (maxWordLength - minWordLength);
        }
        fin << (char)((rand() % ('z' - 'a' + 1)) + 'a'); // ����� ��������� �㪢�
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
    ofstream fout(fileH); // �?��ਢ�� 䠩� ��� ������
    ifstream finG(fileG); // �?��ਢ�� 䠩�� ��� �⠭��
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
    fout.close(); // ���ਢ�� ��? 䠩��
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