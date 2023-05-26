#include "Search.h"



//функція послідовного пошуку
int Search::sequentialSearch(int value) {
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

//функція пошуку методом Фібоначі
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
        int i = (((offset + fib2) < (arraySize - 1)) ? (offset + fib2) : (arraySize - 1));
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

//функція пошуку інтерполяційним методом
int Search::interpolationSearch(int value) {
    int low = 0;
    int high = arraySize - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        //формула інтерполяції для знаходження наближеної позиції шуканого елемента
        int position = low + ((value - array[low]) * (high - low)) / (array[high] - array[low]);

        if (array[position] == value) {
            return position; 
        }

        if (array[position] < value) {
            low = position + 1; 
        }
        else {
            high = position - 1; 
        }
    }

    return -1; 
}

//Хеш-функція
int Search::hashFunction(int value) {
    return value % 1000;
}

//функція пошуку елементу за допомогою Хеш-функції
int Search::hashSearch(int key) {
    int hash = hashFunction(key);
    int index = hash;

    while (array[index] != key) {
        if (array[index] == -1) {
            return -1;
        }

        index = (index + 1) % arraySize;

        if (index == hash) {
            return -1;
        }
    }

    return index;
}





//// Функція для генерації масиву випадкових чисел
//void generateRandomArray(Search& search) {
//    srand(static_cast<unsigned int>(time(nullptr)));
//    int* arr = search.GetArray();
//    for (int i = 0; i < search.GetArraySize(); i++) {
//        arr[i] = rand();
//    }
//}
//
//// Функція для сортування масиву за алгоритмом сортування вставкою
//void insertionSort(Search& search) {
//    int* arr = search.GetArray();
//    for (int i = 1; i < search.GetArraySize(); i++) {
//        int key = arr[i];
//        int j = i - 1;
//
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j--;
//        }
//
//        arr[j + 1] = key;
//    }
//}






//функція запису результатів до файлу

void FileAditional::writeToFile(const std::string& filename, int searchValue) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {

        int* arr = GetArray();
        int size = GetArraySize();

        // Записуємо елементи масиву у файл
        for (int i = 0; i < size; i++) {
            file << arr[i] << std::endl;
        }


        // Виконуємо пошук і записуємо результати у файл
        int resultSequential = sequentialSearch(searchValue);
        int resultFibonacci = fibonacciSearch(searchValue);
        int resultInterpolation = interpolationSearch(searchValue);
        int resultHash = hashSearch(searchValue);

        file << "\nРезультат пошуку числа " << searchValue << " різними методами: \n\n" << std::endl;

        file << "Послідовний метод: " << resultSequential << std::endl;
        file << "Метод Фібоначчі: " << resultFibonacci << std::endl;
        file << "Інтерполяційний метод: " << resultInterpolation << std::endl;
        file << "Метод Хеш-функції: " << resultHash << std::endl;
        file << "-------------------------------------------------------------------------" << std::endl;


        file.close();
        MessageBox::Show("Результати збережено у файлі results.txt");


    }
    else {
        MessageBox::Show("Помилка при відкритті файлу results.txt", "Помилка");
    }

}

