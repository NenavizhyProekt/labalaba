#pragma once
#include <iostream>
#ifndef ARRAY_PROCESSOR_H
#define ARRAY_PROCESSOR_H
#ifdef MYDYNAMICLIB_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API ArrayProcessor {
public:
    // —татический метод сортировки массива (пузырькова€ сортировка)
    static void bubbleSort(int arr[], int size);

    // —татический метод поиска элемента в массиве (линейный поиск)
    static int findElement(int arr[], int size, int element);

    // —татический метод нахождени€ среднего значени€
    static double findAverage(int arr[], int size);

};

#endif // ARRAY_PROCESSOR_H