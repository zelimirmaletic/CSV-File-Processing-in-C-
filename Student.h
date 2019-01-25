#pragma  once


#include <stdio.h>
#include <string.h>
#define NUMBEROFSTUDENTS 100


typedef struct Student
{
    double averageGrade;
    int yearOfStudy;
    char *firstName;
    char *lastName;
    char *indexNumber;
}STUDENT;


void printStudent(STUDENT other)
{
    printf("%5.2f %10s %10s %7s %d\n",other.averageGrade,other.firstName,other.lastName,other.indexNumber,other.yearOfStudy);
}

void printStudentCSVFormat(STUDENT other)
{
    printf("%5.2f,%s,%s,%s,%d\n",other.averageGrade,other.firstName,other.lastName,other.indexNumber,other.yearOfStudy);
}

void freeStudentArray(STUDENT *studentArray)
{
    for (int i = 0; i <NUMBEROFSTUDENTS ; ++i)
    {
        free(studentArray[i].firstName);
        free(studentArray[i].lastName);
        free(studentArray[i].indexNumber);
        studentArray[i].firstName=studentArray[i].lastName=studentArray[i].indexNumber=NULL;
    }
    free(studentArray);
    studentArray=NULL;
    printf("MEMORY CLEANUP: %3.1f kB released!\n", (double)(NUMBEROFSTUDENTS* sizeof(STUDENT))/1000);
}

STUDENT *copy(STUDENT *originalArray, int numberOfElements)
{
    STUDENT *copyArray =(STUDENT *)calloc(numberOfElements, sizeof(STUDENT));
    for (int i = 0; i <numberOfElements ; ++i)
    {
        copyArray[i].averageGrade = originalArray[i].averageGrade;
        copyArray[i].yearOfStudy=originalArray[i].yearOfStudy;
        copyArray[i].firstName =(char *)calloc(strlen(originalArray[i].firstName)+1, sizeof(char));
        strcpy(copyArray[i].firstName,originalArray[i].firstName);
        copyArray[i].lastName =(char *)calloc(strlen(originalArray[i].lastName)+1, sizeof(char));
        strcpy(copyArray[i].lastName,originalArray[i].lastName);
        copyArray[i].indexNumber =(char *)calloc(strlen(originalArray[i].indexNumber)+1, sizeof(char));
        strcpy(copyArray[i].indexNumber,originalArray[i].indexNumber);
    }
    return copyArray;
}

