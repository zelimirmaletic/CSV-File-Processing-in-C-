#pragma  once
#include <stdlib.h>
#include "Student.h"
#include <string.h>

#define NUMBEROFSTUDENTS 100
#define BUFFER_SIZE 40


STUDENT *parseCSV(const char *fileName) {

    STUDENT *studentArray = (STUDENT *) calloc(NUMBEROFSTUDENTS, sizeof(STUDENT));
    if (!studentArray) {
        printf("Memory allocation failiure!\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    FILE *stream = NULL;
    char *token;
    const char delim[2] = ",";

    if (stream = fopen(fileName, "r"))
    {
        for (int i = 0; i < NUMBEROFSTUDENTS; ++i)
        {
            fgets(buffer, BUFFER_SIZE, stream);

            token = strtok(buffer, delim);
            int counter = 0;
            while (token != NULL)
            {
                switch (counter)
                {
                    case 0:
                        studentArray[i].averageGrade = atof(token);
                        counter++;
                        break;
                    case 1:
                        studentArray[i].firstName = (char *) calloc(strlen(token), sizeof(char));
                        strcpy(studentArray[i].firstName, token);
                        counter++;
                        break;
                    case 2:
                        studentArray[i].lastName = (char *) calloc(strlen(token), sizeof(char));
                        strcpy(studentArray[i].lastName, token);
                        counter++;
                        break;
                    case 3:
                        studentArray[i].indexNumber = (char *) calloc(strlen(token), sizeof(char));
                        strcpy(studentArray[i].indexNumber, token);
                        counter++;
                        break;
                    case 4:
                        studentArray[i].yearOfStudy = atoi(token);
                        counter++;
                        break;
                }
                token = strtok(NULL, delim);
            }
        }
        printf("MESSAGE: CSV file parsed into an array.\n");
    }
    else
        {
            printf("!There was a problem with reading input CSV file!\n");
            printf("Please check:\n");
            printf("\t\t1. Spelling errors entered in parseCSV(...) function\n");
            printf("\t\t2. Exsistance of input file.\n");
            printf("\t\t3. Location of input file. It must be in build/debug folder.\n");
            printf("\t\t4. Input file extension.\n");
            printf("\n*********************************************************************\n\n");
        }
    fclose(stream);
    return studentArray;
}

