#include "Search.h"
#include <fstream>
#include <ctime>

//extern const int arraySize = 10;
//extern int array[arraySize];

Search::Search() {
    // Конструктор для ініціалізації масиву
}

Search::~Search() {
    // Деструктор для звільнення пам'яті
}


int Search::sequentialSearch(int value) {
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int Search::fibonacciSearch(int value) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < arraySize) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        int i = std::min(offset + fib2, arraySize - 1);

        if (array[i] < value) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (array[i] > value) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }

    if (fib1 == 1 && array[offset + 1] == value) {
        return offset + 1;
    }

    return -1;
}


int Search::interpolationSearch(int value) {
    int low = 0;
    int high = arraySize - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        // Використовуємо формулу інтерполяції для знаходження наближеної позиції шуканого елемента
        int position = low + ((value - array[low]) * (high - low)) / (array[high] - array[low]);

        if (array[position] == value) {
            return position; // Знайдено шуканий елемент
        }

        if (array[position] < value) {
            low = position + 1; // Шуканий елемент знаходиться в правій половині
        }
        else {
            high = position - 1; // Шуканий елемент знаходиться в лівій половині
        }
    }

    return -1; // Шуканий елемент не знайдено
}

int Search::hashFunction(int value) {
    return value % 1000;
}

int Search::hashSearch(int key) {
    int hash = hashFunction(key);
    int index = hash;

    while (array[index] != key) {
        if (array[index] == -1) {
            // Елемент не знайдено
            return -1;
        }

        index = (index + 1) % arraySize;

        if (index == hash) {
            // Проходження через весь масив, елемент не знайдено
            return -1;
        }
    }

    // Елемент знайдено
    return index;
}





void Search::writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}




// Функція для генерації масиву випадкових чисел
void generateRandomArray(Search& search) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < search.arraySize; i++) {
        search.array[i] = rand();
    }
}

// Функція для сортування масиву за алгоритмом сортування вставкою
void insertionSort(Search& search) {
    for (int i = 1; i < search.arraySize; i++) {
        int key = search.array[i];
        int j = i - 1;

        while (j >= 0 && search.array[j] > key) {
            search.array[j + 1] = search.array[j];
            j--;
        }

        search.array[j + 1] = key;
    }
}