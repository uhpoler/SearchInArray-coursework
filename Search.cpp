#include "Search.h"




//������� ����������� ������
int Search::sequentialSearch(int value) {
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

//������� ������ ������� Գ������
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

//������� ������ ��������������� �������
int Search::interpolationSearch(int value) {
    int low = 0;
    int high = arraySize - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        //������� ������������ ��� ����������� ��������� ������� �������� ��������
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

//������� ������ ���������� �� �����
void Search::writeToFile(const std::string& filename, int searchValue) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {

        int* arr = Search::GetArray();
        // �������� �������� ������ � ����
        for (int i = 0; i < GetArraySize(); i++) {
            file << arr[i] << " ";
        }


        // �������� ����� � �������� ���������� � ����
        int resultSequential = sequentialSearch(searchValue);
        int resultFibonacci = fibonacciSearch(searchValue);
        int resultInterpolation = interpolationSearch(searchValue);
        int resultHash = hashSearch(searchValue, arr);

        file << "\n\n��������� ������ ����� " << searchValue << " ������ ��������: \n" << std::endl;

        file << "���������� �����: " << resultSequential << std::endl;
        file << "����� Գ�������: " << resultFibonacci << std::endl;
        file << "��������������� �����: " << resultInterpolation << std::endl;
        file << "����� ���-�������: " << resultHash << "\n" << std::endl;



        file.close();
        MessageBox::Show("���������� ��������� � ���� results.txt");


    }
    else {
        MessageBox::Show("������� ��� ������� ����� results.txt", "�������");
    }

}

//-------------------------------------------------------------------------------------


//������� ������ �������� �� ��������� ���-�������
int Search::hashSearch(int key, int* array) {
    Hashing hashTable(10); // ��������� ���-������� � 10 �����
    int index = 0;
    // ��������� �������� �� ���-�������
    for (int i = 0; i < arraySize; i++) {
        hashTable.insertKey(array[i], i);

        // ����� ����� � ���-�������
        index = hashTable.searchKey(key, array);
    }
    return index;
}


Hashing::Hashing(int b) {
    this->hashBucket = b;
    hashTable = new std::list<int>[hashBucket];
}

//�������, ��� ���� ���� �� ���-�������
void Hashing::insertKey(int key, int value) {
    int index = hashFunction(key);
    hashTable[index].push_back(value);
}

//���-�������
int Hashing::hashFunction(int x) {
    return (x % hashBucket);
}

// ����� ����� � ���-�������
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



