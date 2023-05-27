#pragma once
#include "MyForm.h"
#include <fstream>
#include <string>
#include <ctime>
#include <msclr/marshal_cppstd.h>

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
    int hashFunction(int value);
    int hashSearch(int value);

    static const int GetArraySize() { return arraySize; }
    int* GetArray() { return array; }

};

class FileAditional : public Search{
public:
    void writeToFile(const std::string& filename, int searchValue);
};

#endif
