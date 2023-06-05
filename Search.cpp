#include "Search.h"




//������� ����������� ������

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

        richTextBox->Refresh(); // ��������� richTextBox1
    }

}




//������� ������ ������� Գ������
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




//������� ������ ��������������� �������
int Search::interpolationSearch(int value, RichTextBox^ richTextBox) {
    int low = 0;
    int high = arraySize - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        //������� ������������ ��� ����������� ��������� ������� �������� ��������
        int position = low + ((value - array[low]) * (high - low)) / (array[high] - array[low]);

        richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[low].ToString());
        richTextBox->SelectionLength = array[high].ToString()->Length;
        richTextBox->SelectionColor = System::Drawing::Color::Yellow;
        richTextBox->Refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (array[position] == value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Green;
            richTextBox->Refresh();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            return position; 
        }



        if (array[position] < value) {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;
            richTextBox->Refresh();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            low = position + 1; 
        }
        else {
            richTextBox->SelectionStart = richTextBox->Text->IndexOf(array[position].ToString());
            richTextBox->SelectionLength = array[position].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Yellow;
            richTextBox->Refresh();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            high = position - 1; 


        }
       
    }

    return -1; 
}

/*
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
*/
















//������� ������ �������� �� ��������� ���-�������
int Search::hashSearch(int key, int* array, RichTextBox^ richTextBox) {
    Hashing hashTable(10); // ��������� ���-������� � 10 �����
    int index = 0;
    // ��������� �������� �� ���-�������
    for (int i = 0; i < arraySize; i++) {
        hashTable.insertKey(array[i], i, richTextBox);

        // ����� ����� � ���-�������
        index = hashTable.searchKey(key, array, richTextBox);
    }


    return index;
}


Hashing::Hashing(int b) {
    this->hashBucket = b;
    hashTable = new std::list<int>[hashBucket];
}

//�������, ��� ���� ���� �� ���-�������
void Hashing::insertKey(int key, int value, RichTextBox^ richTextBox) {
    int index = hashFunction(key);
    hashTable[index].push_back(value);
}

//���-�������
int Hashing::hashFunction(int x) {
    return (x % hashBucket);
}

// ����� ����� � ���-�������
int Hashing::searchKey(int key, int* arr, RichTextBox^ richTextBox) {
    int index = hashFunction(key);
    std::list<int>::iterator it;

    for (it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
        richTextBox->SelectionStart = richTextBox->Text->IndexOf(arr[*it].ToString());
        richTextBox->SelectionLength = arr[*it].ToString()->Length;
        richTextBox->SelectionColor = System::Drawing::Color::Yellow;
        richTextBox->Refresh(); 
       // std::this_thread::sleep_for(std::chrono::seconds(1));

        if (key == arr[*it])
        {

            richTextBox->SelectionStart = richTextBox->Text->IndexOf(arr[index].ToString());
            richTextBox->SelectionLength = array[*it].ToString()->Length;
            richTextBox->SelectionColor = System::Drawing::Color::Green;
            richTextBox->Refresh();

            return *it;
        }
    }

    return -1;
}



