#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "..\..\StaticLib\StaticLib\array_utils.h"
#include "ArrayProcessor.h"
#include "iostream"

namespace MyLib {
    void hello() {
        std::cout << "Hello from MyLib namespace!" << std::endl;
    }
}

// Функция для безопасного ввода целого числа
int safe_input(const char* prompt) {
    int value;
    char buffer[100];

    while (1) {
        printf("%s", prompt);

        // Считываем строку
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Ошибка ввода. Попробуйте снова.\n");
            continue;
        }

        // Пытаемся преобразовать строку в число
        char* endptr;
        long parsed_value = strtol(buffer, &endptr, 10);

        // Проверяем корректность преобразования
        if (endptr == buffer) {
            printf("Введено не число. Попробуйте снова.\n");
            continue;
        }

        // Проверяем, что после числа нет посторонних символов
        while (*endptr != '\0') {
            if (*endptr != '\n' && *endptr != ' ') {
                printf("Некорректный ввод. Попробуйте снова.\n");
                break;
            }
            endptr++;
        }

        // Проверяем диапазон
        if (parsed_value > INT_MAX || parsed_value < INT_MIN) {
            printf("Число вне допустимого диапазона. Попробуйте снова.\n");
            continue;
        }

        value = (int)parsed_value;
        break;
    }

    return value;
}

void printArray(int arr[], int size, const char* message) {
    printf("%s", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    setlocale(LC_ALL, "RUS");
    int size;

    // Безопасный ввод размера массива
    size = safe_input("Введите размер массива (1-1000): ");

    // Дополнительная проверка размера массива
    while (size <= 0 || size > 1000) {
        printf("Размер должен быть от 1 до 1000.\n");
        size = safe_input("Введите размер массива (1-1000): ");
    }

    // Выделение памяти для массива
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Заполнение массива случайными числами
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Случайные числа от 0 до 99
    }

    // Вывод исходного массива
    printArray(arr, size, "Исходный массив: ");

    // Сортировка массива
    bubbleSort(arr, size);
    printArray(arr, size, "Отсортированный массив: ");

    // Поиск элемента
    int searchValue = safe_input("\nВведите число для поиска: ");

    int position = findElement(arr, size, searchValue);
    if (position != -1) {
        printf("Число %d найдено на позиции %d\n", searchValue, position);
    }
    else {
        printf("Число %d не найдено в массиве\n", searchValue);
    }

    // Вычисление среднего значения
    double avg = findAverage(arr, size);
    printf("\nСреднее значение элементов: %.2f\n", avg);

    // Дополнительная статистика
    printf("\nСтатистика массива:");
    printf("\n- Минимальное значение: %d", arr[0]);
    printf("\n- Максимальное значение: %d", arr[size - 1]);

    // Подсчет количества элементов больше среднего
    int countAboveAvg = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > avg) countAboveAvg++;
    }
    printf("\n- Количество элементов больше среднего: %d\n", countAboveAvg);

    // Меню действий
    int choice;
    do {
        printf("\nВыберите действие:");
        printf("\n1. Найти другой элемент");
        printf("\n2. Пересортировать массив");
        printf("\n3. Вывести текущий массив");
        printf("\n4. Выход");

        choice = safe_input("\nВаш выбор: ");

        switch (choice) {
        case 1: {
            searchValue = safe_input("Введите число для поиска: ");
            position = findElement(arr, size, searchValue);
            if (position != -1) {
                printf("Число %d найдено на позиции %d\n", searchValue, position);
            }
            else {
                printf("Число %d не найдено в массиве\n", searchValue);
            }
            break;
        }
        case 2:
            bubbleSort(arr, size);
            printArray(arr, size, "Отсортированный массив: ");
            break;
        case 3:
            printArray(arr, size, "Текущий массив: ");
            break;
        case 4:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 4);

    // Освобождение выделенной памяти
    free(arr);
   



    int myarray[3] = { 1, 2, 3 };

    std::cout << "Dynamic lib test" << std::endl;
    std::cout << ArrayProcessor::findAverage(myarray, 3) << std::endl;


    MyLib::hello();
    while (true) {

    }
    

    return 0;
}