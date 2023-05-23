/*#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Search.h"
#include <Windows.h>


int main() {
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    const int arraySize = 1000;  // Розмір масиву
    int array[arraySize];
 
    generateRandomArray(array, arraySize);
    insertionSort(array, arraySize);


    
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }


    std::cout << "Елемент з номером 3: ";
    std::cout << array[3] << std::endl;


    int searchValue;
    std::cout << "Введіть значення для пошуку: ";
    std::cin >> searchValue;

    // Пошук значення в масиві за різними методами
    Search search(array, arraySize);
    int resultSequential = search.sequentialSearch(searchValue);
    int resultFibonacci = search.fibonacciSearch(searchValue);
    int resultInterpolation = search.interpolationSearch(searchValue);
    int resultHash = search.hashSearch(searchValue);


    // Збереження результату послідовного пошуку у файл
    //Search::writeToFile("sequential_result.txt", sequentialResult);

    std::cout << "Послідовний метод: " << resultSequential << std::endl;
    std::cout << "Метод Фібоначчі: " << resultFibonacci << std::endl;
    std::cout << "Інтерполяційний метод: " << resultInterpolation << std::endl;
    std::cout << "Метод Хеш-функції: " << resultHash << std::endl;




    // Збереження результатів у текстовий файл
    std::ofstream outputFile("results.txt");
    if (outputFile.is_open()) {
        outputFile << "Послідовний метод: " << resultSequential << std::endl;
        outputFile << "Метод Фібоначчі: " << resultFibonacci << std::endl;
        outputFile << "Інтерполяційний метод: " << resultInterpolation << std::endl;
        outputFile << "Метод Хеш-функції: " << resultHash << std::endl;
        outputFile.close();
        std::cout << "Результати збережено у файлі results.txt" << std::endl;
    }
    else {
        std::cout << "Помилка при відкритті файлу results.txt" << std::endl;
    }

    return 0;
}
*/