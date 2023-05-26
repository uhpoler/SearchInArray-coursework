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

//���-�������
int Search::hashFunction(int value) {
    return value % 1000;
}

//������� ������ �������� �� ��������� ���-�������
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





//// ������� ��� ��������� ������ ���������� �����
//void generateRandomArray(Search& search) {
//    srand(static_cast<unsigned int>(time(nullptr)));
//    int* arr = search.GetArray();
//    for (int i = 0; i < search.GetArraySize(); i++) {
//        arr[i] = rand();
//    }
//}
//
//// ������� ��� ���������� ������ �� ���������� ���������� ��������
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






//������� ������ ���������� �� �����

void FileAditional::writeToFile(const std::string& filename, int searchValue) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {

        int* arr = GetArray();
        int size = GetArraySize();

        // �������� �������� ������ � ����
        for (int i = 0; i < size; i++) {
            file << arr[i] << std::endl;
        }


        // �������� ����� � �������� ���������� � ����
        int resultSequential = sequentialSearch(searchValue);
        int resultFibonacci = fibonacciSearch(searchValue);
        int resultInterpolation = interpolationSearch(searchValue);
        int resultHash = hashSearch(searchValue);

        file << "\n��������� ������ ����� " << searchValue << " ������ ��������: \n\n" << std::endl;

        file << "���������� �����: " << resultSequential << std::endl;
        file << "����� Գ�������: " << resultFibonacci << std::endl;
        file << "��������������� �����: " << resultInterpolation << std::endl;
        file << "����� ���-�������: " << resultHash << std::endl;
        file << "-------------------------------------------------------------------------" << std::endl;


        file.close();
        MessageBox::Show("���������� ��������� � ���� results.txt");


    }
    else {
        MessageBox::Show("������� ��� ������� ����� results.txt", "�������");
    }

}

