#pragma once
#include "MyForm.h"
#include <fstream>
#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <unordered_map>

#ifndef SEARCH_H
#define SEARCH_H


using namespace System;
using namespace System::Windows::Forms;


class Search {
protected:
    static const int arraySize = 1000;
    int array[arraySize];
public:

    int sequentialSearch(int value);
    int fibonacciSearch(int value);
    int interpolationSearch( int value);
    int hashSearch(int value, int* array);

    static const int GetArraySize() { return arraySize; }
    int* GetArray() { return array; }
    
    void writeToFile(const std::string& filename, int searchValue);
};


class Hashing : public Search {
    int hashBucket;
    std::list<int>* hashTable;
public:
    Hashing(int V);
    void insertKey(int key, int value);
    int hashFunction(int x);
    int searchKey(int key, int* array);
};




#endif
