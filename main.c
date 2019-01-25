#include <stdio.h>
#include "CSV.h"
#include "algorithm.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t shellSortTime, heapSortTime, quickSortTime, bubbleSortTime;

    printf("\n\n*************************SORTING CSV FILE*************************\n\n");
    STUDENT *studentArray=NULL;
    studentArray=parseCSV("StudentsRegister.csv");

    //SHELL SORT
    STUDENT *copyArray = copy(studentArray,NUMBEROFSTUDENTS);
    shellSortTime=clock();
    shellSort(copyArray,NUMBEROFSTUDENTS);
    shellSortTime = clock()-shellSortTime;
    printIntoFile("outputShellSort",copyArray,NUMBEROFSTUDENTS);
    printf("MESSAGE: Shell sort algorithm executed! New file has been created.\n");

    //QUICK SORT
    copyArray = copy(studentArray, NUMBEROFSTUDENTS);
    quickSortTime=clock();
    quickSort(copyArray,0,NUMBEROFSTUDENTS-1);
    quickSortTime=clock()-quickSortTime;
    printIntoFile("outputQuickSort",copyArray,NUMBEROFSTUDENTS);
    printf("MESSAGE: Quick sort algorithm executed! New file has been created.\n");

    //HEAP SORT
    copyArray = copy(studentArray, NUMBEROFSTUDENTS);
    heapSortTime=clock();
    heapSort(copyArray, NUMBEROFSTUDENTS);
    heapSortTime=clock()-heapSortTime;
    printIntoFile("outputHeapSort",copyArray,NUMBEROFSTUDENTS);
    printf("MESSAGE: Heap sort algorithm executed! New file has been created.\n");

    //BUBBLE SORT
    copyArray = copy(studentArray, NUMBEROFSTUDENTS);
    bubbleSortTime=clock();
    bubbleSortStudent(copyArray, NUMBEROFSTUDENTS);
    bubbleSortTime=clock()-bubbleSortTime;
    printIntoFile("outputBubbleSort",copyArray,NUMBEROFSTUDENTS);
    printf("MESSAGE: Bubble sort algorithm executed! New file has been created.\n\n");



    freeStudentArray(copyArray);
    freeStudentArray(studentArray);

    printf("\n\n********************TIME CONSUMPTION BY ALGORITHM********************\n\n");
    int numberOfAlgorithms = 4;
    ALGORITHM *algorithmArray = allocateAlgorithmArray(numberOfAlgorithms);


    addAlgorithm("Shell sort","n(log n)^2",shellSortTime,0,numberOfAlgorithms,algorithmArray);
    addAlgorithm("Quick sort","n(log n)",quickSortTime,1,numberOfAlgorithms,algorithmArray);
    addAlgorithm("Heap sort","n(log n)", heapSortTime,2,numberOfAlgorithms,algorithmArray);
    addAlgorithm("Bubble sort","n^2", bubbleSortTime,3, numberOfAlgorithms,algorithmArray);


    showAlgorithmStatistics(algorithmArray,numberOfAlgorithms);

    freeAlgorithmArray(algorithmArray,numberOfAlgorithms);
    return 0;
}