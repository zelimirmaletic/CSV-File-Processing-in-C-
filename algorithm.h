#pragma once
#include "Student.h"
#include <time.h>

typedef struct algorithm
{
    char *algorithmName;
    char *timeComplexity;
    double timeTaken;
}ALGORITHM;

void swapStudent(STUDENT *a, STUDENT *b)
{
    STUDENT t = *a;
    *a = *b;
    *b = t;
}

void printIntoFile(const char *fileName, STUDENT *copyArray, int numberOfElements)
{
    FILE *stream;
    stream=fopen(fileName,"w");
   // fprintf(stream,"AVER.|FIRST NAME| LAST NAME|   INDEX  |YEAR\n");
    //fprintf(stream,"-------------------------------------------\n");
    for (int k = 0; k < numberOfElements; ++k)
        fprintf(stream,"%5.2f,%s,%s,%s,%d\n",copyArray[k].averageGrade,copyArray[k].firstName,copyArray[k].lastName,copyArray[k].indexNumber,copyArray[k].yearOfStudy);
    //fprintf(stream,"-------------------------------------------\n");
    fclose(stream);
}


//SHELL SORT
void shellSort(STUDENT *copyArray, int numberOfElements)
{
    int i, j, k;
    STUDENT tmp;
    for (i = numberOfElements / 2; i > 0; i = i / 2)
    {
        for (j = i; j < numberOfElements; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (copyArray[k+i].averageGrade >= copyArray[k].averageGrade)
                    break;
                else
                        swapStudent(&copyArray[k], &copyArray[k+i]);
                }
            }
        }
}
//QUICK SORT
int partition (STUDENT *array, int low, int high)
{
    double pivot = array[high].averageGrade;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j].averageGrade <= pivot)
        {
            i++;
            swapStudent(&array[i], &array[j]);
        }
    }
    swapStudent(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(STUDENT *studentArray, int low, int high)
{
    if (low < high)
    {
        int pi = partition(studentArray, low, high);

        quickSort(studentArray, low, pi - 1);
        quickSort(studentArray, pi + 1, high);
    }
}

//HEAP SORT
void buildHeap(STUDENT *array, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    if (l < n && array[l].averageGrade > array[largest].averageGrade)
        largest = l;

    if (r < n && array[r].averageGrade > array[largest].averageGrade)
        largest = r;

    if (largest != i)
    {
        swapStudent(&array[i], &array[largest]);
        buildHeap(array, n, largest);
    }
}

void heapSort(STUDENT  *array, int numberOfElements)
{
    // Build heap (rearrange array)
    for (int i = numberOfElements / 2 - 1; i >= 0; i--)
        buildHeap(array, numberOfElements, i);

    // One by one extract an element from heap
    for (int i=numberOfElements-1; i>=0; i--)
    {
        // Move current root to end
        swapStudent(&array[0], &array[i]);

        // call max heapify on the reduced heap
        buildHeap(array, i, 0);
    }
}

//BUBBLE SORT

void bubbleSortStudent(STUDENT *array, int numberOfElements)
{
    int i, j;
    for (i = 0; i < numberOfElements-1; i++)
        for (j = 0; j < numberOfElements-i-1; j++)
            if (array[j].averageGrade > array[j+1].averageGrade)
                swapStudent(&array[j], &array[j+1]);
}



/*
 *ALGORITHM DATA STRUCTURE FUNCTIONS
 */

//BUBBLE SORT
void swapAlgorithm(ALGORITHM *xp, ALGORITHM *yp)
{
    ALGORITHM temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSortAlgorithm(ALGORITHM *array, int numberOfElements)
{
    int i, j;
    for (i = 0; i < numberOfElements-1; i++)
        for (j = 0; j < numberOfElements-i-1; j++)
            if (array[j].timeTaken > array[j+1].timeTaken)
                swapAlgorithm(&array[j], &array[j+1]);
}

void freeAlgorithmArray(ALGORITHM *array, int numberOFElements)
{
    for (int i = 0; i <numberOFElements ; ++i)
    {
        free(array[i].algorithmName);
        free(array[i].timeComplexity);
    }
    free(array);
}

ALGORITHM *allocateAlgorithmArray(int numberOfElemets)
{
    return (ALGORITHM *)calloc(numberOfElemets, sizeof(ALGORITHM));
}

void addAlgorithm(const char *algorithmName,const char *timeComplexity, time_t timeTaken, int index, int numberOfElements, ALGORITHM *algorithmArray)
{
    if(index<0 || index>numberOfElements)
        printf ("MESSAGE: Indexing error occured in function addAlgorithm(...)\n");
    algorithmArray[index].algorithmName = (char *)calloc(strlen(algorithmName+1), sizeof(char));
    strcpy(algorithmArray[index].algorithmName,algorithmName);

    algorithmArray[index].timeComplexity = (char *)calloc(strlen(timeComplexity+1), sizeof(char));
    strcpy(algorithmArray[index].timeComplexity,timeComplexity);

    //conversion to seconds
    algorithmArray[index].timeTaken=((double)timeTaken)/CLOCKS_PER_SEC;
}

void showAlgorithmStatistics(ALGORITHM *algorithmArray, int numberOfAlgorithms)
{
    bubbleSortAlgorithm(algorithmArray,numberOfAlgorithms);

    printf("-----------------------------------------------\n");
    printf("NUM    ALGORITHM       TIME COMPLEX.   TIME [s]\n");
    printf("-----------------------------------------------\n");
    for(int i=0;i<numberOfAlgorithms;i++)
        printf("%d.    %11s     %13s   %f\n",i+1,algorithmArray[i].algorithmName,algorithmArray[i].timeComplexity,algorithmArray[i].timeTaken);
    printf("-----------------------------------------------\n");
    printf("\n*********************************************************************\n\n");
}
