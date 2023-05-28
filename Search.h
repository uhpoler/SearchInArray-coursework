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
    int hash_bucket;
public:

    int sequentialSearch(int value);
    int fibonacciSearch(int value);
    int interpolationSearch( int value);
    int hashSearch(int value, int* array);

    static const int GetArraySize() { return arraySize; }
    int* GetArray() { return array; }
    
};


class Hashing {
    int hash_bucket; 
    std::list<int>* hashtable; 

public:
    Hashing(int V); 
    void insert_key(int val, int value);
    int hashFunction(int x);
    int searchKey(int key, int* array);
};

class FileAditional : public Search{
public:
    void writeToFile(const std::string& filename, int searchValue);
};




#endif
