//
// Created by User on 20.05.2022.
//

#ifndef LABA14_UTILITY_H
#define LABA14_UTILITY_H

#include <stdio.h>
#include <string.h>

FILE* writebuffer;
FILE* readbuffer;

char path[32] = "C:/labsData/";
char filename[16] = "data.bin";

struct Town {
    char name[16];
};

struct University {
    char name[16];
    int speciality;
};

struct Faculty {
    char name[32];
    char speciality[64];
    int size;
};

struct Object {
    struct Town town;
    struct University university;
    struct Faculty faculty;
};

void writeData(FILE* writebuffer, const char* filepath, struct Object* data, size_t len)
{
    writebuffer = fopen(filepath, "ab");
    for (size_t i = 0; i < len; i++)
    {
        fwrite(&data[i], sizeof(struct Object), 1, writebuffer);
    }
    fclose(writebuffer);
}

void printData(FILE* readbuffer, const char* filepath)
{
    struct Object output;
    readbuffer = fopen(filepath, "rb");

    while (fread(&output, sizeof(output), 1, readbuffer) == 1)
    {
        printf("Town: %s, University: %s, Code: %d, Faculty: %s, Speciality: %s, Size: %d;\n",
               output.town.name,
               output.university.name,
               output.university.speciality,
               output.faculty.name,
               output.faculty.speciality,
               output.faculty.size
        );
    }
    fclose(readbuffer);
}

void editData(FILE* restrict writebuffer, const char* filepath, struct Object* data, int i)
{
    writebuffer = fopen(filepath, "rb+");
    fseek(writebuffer, sizeof(struct Object) * i, SEEK_SET);
    fwrite(data, sizeof(struct Object), 1, writebuffer);
    fclose(writebuffer);
}

void deleteData(FILE* restrict readbuffer, const char* filepath, int i)
{
    FILE *readbuffer_tmp;
    int found=0;
    struct Object output;

    readbuffer=fopen(filepath, "rb");
    if (!readbuffer) {
        printf("Unable to open file %s", filepath);
        return;
    }
    readbuffer_tmp=fopen("tmp.bin", "wb");
    if (!readbuffer_tmp) {
        printf("Unable to open file temp file.");
        return;
    }

    for (int j = 0; fread(&output, sizeof(struct Object), 1, readbuffer) == 1; j++)
    {
        if (i == j)
        {
            printf("Successfully deleted record at index %d\n", i);
            found = 1;
        }
        else fwrite(&output, sizeof(struct Object), 1, readbuffer_tmp);
    }
    if (!found) printf("Couldn't find a record at index %d\n", i);

    fclose(readbuffer);
    fclose(readbuffer_tmp);

    remove(filepath);
    rename("tmp.bin", filepath);
}

void findData(FILE* restrict readbuffer, const char* filepath, const char* data) {
    struct Object output;
    readbuffer = fopen(filepath, "rb");
    while (fread(&output, sizeof(output), 1, readbuffer) == 1)
    {
        if (strstr(output.faculty.speciality, data) != NULL) {
            printf("Town: %s, University: %s, Faculty: %s, Speciality: %s;\n",
            output.town.name, output.university.name, output.faculty.name, output.faculty.speciality);
        }
    }
    fclose(readbuffer);
}

void findBiggestSize(FILE* readbuffer, const char* filepath) {
    struct Object output;
    readbuffer = fopen(filepath, "rb");
    int maxNumber = 0;
    char speciality[32];
    while (fread(&output, sizeof(output), 1, readbuffer) == 1)
    {
        if (maxNumber < output.faculty.size)
        {
            maxNumber = output.faculty.size;
            strcpy(speciality,output.faculty.speciality);
        }
    }
    printf("Speciality with largest number of places: %s\n", speciality);
    fclose(readbuffer);
}

void printDataByNumber(FILE* readbuffer, const char* filepath, int index) {
    struct Object output;
    readbuffer = fopen(filepath, "rb");
    while (fread(&output, sizeof(output), 1, readbuffer) == 1)
    {
        if (index == output.university.speciality)
        {
            printf("Town: %s, University: %s, Faculty: %s;\n", output.town.name, output.university.name, output.faculty.name);
        }
    }
    fclose(readbuffer);
}

void clearFile(FILE* readbuffer,const char* filepath) {
    FILE *tmp;

    readbuffer=fopen(filepath, "rb");
    if (!readbuffer) {
        printf("Unable to open file %s", filepath);
        return;
    }
    tmp=fopen("tmp.bin", "wb");
    if (!tmp) {
        printf("Unable to open file temp file.");
        return;
    }

    fclose(readbuffer);
    fclose(tmp);

    remove(filepath);
    rename("tmp.bin", filepath);
}

void clearAndFillFile(FILE* readbuffer,const char* filepath) {
    clearFile(readbuffer, filepath);
    struct Object data[32] = {
        {
            {"Kiev"},
            {"KPI",122},
            {"IASA", "System Design", 85}
        },
        {
            {"Kiev"},
            {"KPI",124},
            {"IASA", "Math. Methods of System Analysis", 70}
        },
        {
            {"Kiev"},
            {"KPI",122},
            {"FBMI", "Biomedical Cybernetics", 60}
        },
        {
            {"Kiev"},
            {"KPI",122},
            {"EIT", "Computer Science", 95}
        },
        {
            {"Kiev"},
            {"KPI",121},
            {"EIT", "Software Engineering", 105}
        }
    };
    writeData(writebuffer, filepath, &data[0], 5);
}


#endif //LABA14_UTILITY_H
