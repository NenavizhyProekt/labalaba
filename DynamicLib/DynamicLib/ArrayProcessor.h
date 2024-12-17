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
    
    static void bubbleSort(int arr[], int size);

    
    static int findElement(int arr[], int size, int element);

    
    static double findAverage(int arr[], int size);

};

#endif