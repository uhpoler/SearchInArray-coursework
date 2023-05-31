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

//функція запису результатів до файлу
void Search::writeToFile(const std::string& filename, int searchValue) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {

        int* arr = Search::GetArray();
        // Записуємо елементи масиву у файл
        for (int i = 0; i < GetArraySize(); i++) {
            file << arr[i] << " ";
        }


        // Виконуємо пошук і записуємо результати у файл
        int resultSequential = sequentialSearch(searchValue);
        int resultFibonacci = fibonacciSearch(searchValue);
        int resultInterpolation = interpolationSearch(searchValue);
        int resultHash = hashSearch(searchValue, arr);

        file << "\n\nРезультат пошуку числа " << searchValue << " різними методами: \n" << std::endl;

        file << "Послідовний метод: " << resultSequential << std::endl;
        file << "Метод Фібоначчі: " << resultFibonacci << std::endl;
        file << "Інтерполяційний метод: " << resultInterpolation << std::endl;
        file << "Метод Хеш-функції: " << resultHash << "\n" << std::endl;



        file.close();
        MessageBox::Show("Результати збережено у файлі results.txt");


    }
    else {
        MessageBox::Show("Помилка при відкритті файлу results.txt", "Помилка");
    }

}

//-------------------------------------------------------------------------------------


//функція пошуку елементу за допомогою Хеш-функції
int Search::hashSearch(int key, int* array) {
    Hashing hashTable(10); // Створення хеш-таблиці з 10 блоків
    int index = 0;
    // Додавання елементів до хеш-таблиці
    for (int i = 0; i < arraySize; i++) {
        hashTable.insertKey(array[i], i);

        // Пошук числа в хеш-таблиці
        index = hashTable.searchKey(key, array);
    }
    return index;
}


Hashing::Hashing(int b) {
    this->hashBucket = b;
    hashTable = new std::list<int>[hashBucket];
}

//функція, яка додає ключ до хеш-таблиці
void Hashing::insertKey(int key, int value) {
    int index = hashFunction(key);
    hashTable[index].push_back(value);
}

//Хеш-функція
int Hashing::hashFunction(int x) {
    return (x % hashBucket);
}

// Пошук числа в хеш-таблиці
int Hashing::searchKey(int key, int* arr) {
    int index = hashFunction(key);
    std::list<int>::iterator it;

    for (it = hashTable[index].begin(); it != hashTable[index].end(); it++) {

        if (key == arr[*it])
        {
            return *it;
        }
    }

    return -1;
}



