#include "pch.h"
#include "ArrayProcessor.h"

// Реализация статических методов класса
void ArrayProcessor::bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int ArrayProcessor::findElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Возвращаем индекс найденного элемента
        }
    }
    return -1; // Элемент не найден
}

double ArrayProcessor::findAverage(int arr[], int size) {
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}
