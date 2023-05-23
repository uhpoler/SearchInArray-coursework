#include "MyForm.h"
#include "Search.h"



using namespace System;
using namespace System::Windows::Forms; // простір імен



[STAThreadAttribute] //точка входу для форми
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSOVANEW::MyForm form;
	Application::Run(% form);


}


Search search;

System::Void KURSOVANEW::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	

	generateRandomArray(search);
	insertionSort(search);

	for (int i = 0; i < search.arraySize; ++i) {
		richTextBox1->Text += System::Convert::ToString(search.array[i]);
		richTextBox1->Text += " ";
	}

	return System::Void();
}

System::Void KURSOVANEW::MyForm::buttonFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	int searchValue;
	searchValue = Convert::ToInt32(textBox->Text);

	//labelEnter->Text = System::Convert::ToString(searchValue);


	int resultSequential = search.sequentialSearch(searchValue);
	int resultFibonacci = search.fibonacciSearch(searchValue);
	int resultInterpolation = search.interpolationSearch(searchValue);
	int resultHash = search.hashSearch(searchValue);

	labelEnter->Text = System::Convert::ToString(resultSequential);

	return System::Void();
}
