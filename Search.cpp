#include "Search.h"




//функція послідовного пошуку
int Search::sequentialSearch(int value, RichTextBox^ richTextBox) {

    for (int i = 0; i < arraySize; i++) {
        if (array[i] == value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Green;
            return i;

        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;
            richTextBox->Refresh();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        richTextBox->Refresh(); // Оновлення richTextBox1
    }

}

//функція пошуку методом Фібоначі
int Search::fibonacciSearch(int value, RichTextBox^ richTextBox) {
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

        richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
        richTextBox->SelectionLength = array[i].ToString()->Length;
        richTextBox->SelectionColor = System::Drawing::Color::Yellow;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (array[i] < value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;

            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (array[i] > value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;
 

            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Green;

            return i;
        }

        richTextBox->Refresh();
    }

    if (fib1 == 1 && array[offset + 1] == value) {
        
        richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[offset + 1].ToString());
        richTextBox->SelectionLength = array[offset + 1].ToString()->Length;
        richTextBox->SelectionColor = System::Drawing::Color::Green;
        richTextBox->Refresh();
        return offset + 1;
    }

    return -1;
}

//функція пошуку інтерполяційним методом
int Search::interpolationSearch(int value, RichTextBox^ richTextBox) {
    int low = 0;
    int high = arraySize - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        //формула інтерполяції для знаходження наближеної позиції шуканого елемента
        int position = low + ((value - array[low]) * (high - low)) / (array[high] - array[low]);

        richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
        richTextBox->SelectionLength = array[position].ToString()->Length;
        richTextBox->SelectionColor = System::Drawing::Color::Yellow;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (array[position] == value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Green;

            return position; 
        }

        richTextBox->Refresh();

        if (array[position] < value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;

            low = position + 1; 
        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;

            high = position - 1; 


        }

        richTextBox->Refresh();
       
    }

    return -1; 
}





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



