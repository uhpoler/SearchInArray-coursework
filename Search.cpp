#include "Search.h"
#include "AdditionalFunctions.h"




//функція послідовного пошуку
int Search::sequentialSearch(int value, RichTextBox^ richTextBox) {


    for (int i = 0; i < arraySize; i++) {
        if (array[i] == value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Green;
            return i;

        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;
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
        richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (array[i] < value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;

            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (array[i] > value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;
 

            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[i].ToString());
            richTextBox->SelectionLength = array[i].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Green;

            return i;
        }

        richTextBox->Refresh();
    }

    if (fib1 == 1 && array[offset + 1] == value) {
        
        richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[offset + 1].ToString());
        richTextBox->SelectionLength = array[offset + 1].ToString()->Length;
        richTextBox->SelectionBackColor = System::Drawing::Color::Green;
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
        richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (array[position] == value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Green;

            return position; 
        }

        richTextBox->Refresh();

        if (array[position] < value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;

            low = position + 1; 
        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionBackColor = System::Drawing::Color::Yellow;

            high = position - 1; 


        }

        richTextBox->Refresh();
       
    }

    return -1; 
}

// Функція для визначення найбільшого ключа
int Search::getMaxKey() {
    int maxKey = array[0];
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > maxKey) {
            maxKey = array[i];
        }
    }
    return maxKey;
}


/*
//функція пошуку елементу за допомогою Хеш-функції
int Search::hashSearch(int key, int* array, RichTextBox^ richTextBox) {
    Hashing hashTable(1000); // Створення хеш-таблиці з 1000 блоків
    int index = 0;
    // Додавання елементів до хеш-таблиці
    for (int i = 0; i < arraySize; i++) {
        hashTable.insertKey(array[i], i);
        index = hashTable.searchKey(key, array, richTextBox);
    }

    //index = hashTable.searchKey(key, array, richTextBox);
    // Виведення хеш-таблиці з виділенням елементів
    hashTable.PrintHashTable(richTextBox, key);


    return index;
}
*/

int Search::hashSearch(int key, int* array, RichTextBox^ richTextBox) {
   // int maxKey = getMaxKey();
    Hashing* hashTable = new Hashing(500); // Создание объекта Hashing на куче
    int index = 0;

    // Добавление элементов в хеш-таблицу
    for (int i = 0; i < arraySize; i++) {
        hashTable->insertKey(array[i], i);
        index = hashTable->searchKey(key, array, richTextBox);
    }

    // Вывод хеш-таблицы с выделением элементов
    hashTable->PrintHashTable(richTextBox, key);

    delete hashTable; // Освобождение памяти, выделенной под объект Hashing

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
int Hashing::searchKey(int key, int* arr, RichTextBox^ richTextBox) {
    int index = hashFunction(key);

    std::list<int>::iterator it;

    for (it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
        if (key == arr[*it]) {


            return *it;
        }

       
    }

    return -1;
}



// Виведення хеш-таблиці в richTextBox
void Hashing::PrintHashTable(RichTextBox^ richTextBox, int key) {
    richTextBox->Clear();
    System::Drawing::Color lightBlueColor = System::Drawing::Color::FromArgb(135, 206, 250);

    for (int i = 0; i < hashBucket; i++) {
        std::list<int> bucket = hashTable[i];
        richTextBox->AppendText("Bucket " + i + ": ");

     
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                int startIndex = richTextBox->TextLength; 
                int length = System::Convert::ToString(*it)->Length; 

                richTextBox->SelectionStart = startIndex;
                richTextBox->SelectionLength = length;
                richTextBox->SelectionBackColor = System::Drawing::Color::Green;

               
            }
            else {
                // Зняти виділення колірного фону
                int startIndex = richTextBox->TextLength;
                int length = System::Convert::ToString(*it)->Length;

                richTextBox->SelectionStart = startIndex;
                richTextBox->SelectionLength = length;
                richTextBox->SelectionBackColor = lightBlueColor;
              
            }
          

            richTextBox->AppendText(System::Convert::ToString(*it) + " ");
           
        }

        richTextBox->AppendText(Environment::NewLine);
    }
}
