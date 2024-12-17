#pragma once
#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

// Функция сортировки массива (пузырьковая сортировка)
void bubbleSort(int arr[], int size);

// Функция поиска элемента в массиве (линейный поиск)
int findElement(int arr[], int size, int element);

// Функция нахождения среднего значения
double findAverage(int arr[], int size);

#endif