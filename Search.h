#pragma once
#ifndef SEARCH_H
#define SEARCH_H

#include <fstream>

class Search {
    
public:
    static const int arraySize = 10;  // ����� ������
    int array[arraySize];  // ����� ��� ������
    Search();  // ����������� ��� ����������� ������
    ~Search();  // ���������� ��� ��������� ���'��
    int sequentialSearch(int value);
    int fibonacciSearch(int value);
    int interpolationSearch( int value);
    int hashFunction(int value);
    int hashSearch(int value);

private:
    static void writeToFile(const std::string& filename, const std::string& content);
};

#endif

void generateRandomArray(Search& search);
void insertionSort(Search& search);