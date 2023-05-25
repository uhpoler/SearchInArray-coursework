#pragma once
#include "MyForm.h"
#include "Search.h"
#include <fstream>
#include <string>
#include <ctime>
#include <msclr/marshal_cppstd.h>


using namespace System;
using namespace System::Windows::Forms;


void generateRandomArray(Search& search);
void insertionSort(Search& search);
bool validateSearchValue(String^ input);
int checkValueInArray(Search& search, int searchValue);
void writeToFile(const std::string& filename, RichTextBox^ richTextBox1, RichTextBox^ richTextBox2);