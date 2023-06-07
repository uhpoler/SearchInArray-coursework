#pragma once
#include "MyForm.h"
#include <fstream>
#include <string>
#include <list>
#include <cstdlib>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <unordered_map>
#include <windows.h>
#include <sstream>
#include <ctime>
#include <chrono>
#include <thread>



#ifndef SEARCH_H
#define SEARCH_H


using namespace System;
using namespace System::Windows::Forms;


class Search {
protected:
    static const int arraySize = 1000;
    int array[arraySize];
public:

    int sequentialSearch(int value, RichTextBox^ richTextBox1);
    int fibonacciSearch(int value, RichTextBox^ richTextBox);
    int interpolationSearch( int value, RichTextBox^ richTextBox);
    int hashSearch(int value, int* array, RichTextBox^ richTextBox);
   

    static const int GetArraySize() { return arraySize; }
    int* GetArray() { return array; }
    

};


class Hashing : public Search {
    int hashBucket;
    std::list<int>* hashTable;
public:
    Hashing(int V);
    void insertKey(int key, int value);
    int hashFunction(int x);
    int searchKey(int key, int* array);
   
    void printHashTable(RichTextBox^ richTextBox, int searchKey, int* array);
};




#endif
