#pragma once
#include "MyForm.h"
#ifndef SEARCH_H
#define SEARCH_H

#include <fstream>
#include <string>


class Search {
    
public:
    static const int arraySize = 10;  // Розмір масиву
    int array[arraySize];  // Масив для пошуку
    int sequentialSearch(int value);
    int fibonacciSearch(int value);
    int interpolationSearch( int value);
    int hashFunction(int value);
    int hashSearch(int value);

private:
    //static void writeToFile(const std::string& filename, const std::string& content);
};

#endif

void generateRandomArray(Search& search);
void insertionSort(Search& search);
bool validateSearchValue(std::string s);
std::string& ConvertString(System::String^ input);
System::String^ ConvertString(std::string& ss, System::String^ s);
bool ValidateSearchValue(System::String^ input);
int getValidatedSearchValue(Search& search, int searchValue);
void writeToFile(const std::string& filename, System::Windows::Forms::RichTextBox^ richTextBox1, System::Windows::Forms::RichTextBox^ richTextBox2);