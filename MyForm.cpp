#include "MyForm.h"
#include "Search.h"
#include "AdditionalFunctions.h"


// простори імен
using namespace System;
using namespace System::Windows::Forms; 



//точка входу для форми
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSOVANEW::MyForm form;
	Application::Run(% form);


}

Search search;
bool isButton1Clicked = false;

//кнопка генерації масиву
System::Void KURSOVANEW::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e)
{
	isButton1Clicked = true;
	richTextBox1->Clear();

	generateRandomArray(search);
	insertionSort(search);

	//виведення масиву в richTextBox1
	int* arr = search.GetArray();
	for (int i = 0; i < search.GetArraySize(); ++i) {
		richTextBox1->Text += System::Convert::ToString(arr[i]);
		richTextBox1->Text += " ";
	}

	return System::Void();
}

//кнопка пошуку значень, які ввів користувач
System::Void KURSOVANEW::MyForm::buttonFind_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked){
		MessageBox::Show("Помилка: Спочатку згенеруйте масив!");
		return;
	}

	richTextBox2->Clear();
	String^ input = textBox->Text;
		

	if (validateSearchValue(input)) {

		int searchValue = Convert::ToInt32(input);
		searchValue = checkValueInArray(search, searchValue);


		if (searchValue == 0) {
			textBox->Clear();

		}
		else {

			//пошук числа в масиві
			int resultSequential = search.sequentialSearch(searchValue);
			int resultFibonacci = search.fibonacciSearch(searchValue);
			int resultInterpolation = search.interpolationSearch(searchValue);
			int resultHash = search.hashSearch(searchValue, search.GetArray());
			
			//вивід результатів
			richTextBox2->Text += "Результат пошуку числа " + input  + " різними методами: \n\n";
			richTextBox2->Text += "Послідовний метод: " + System::Convert::ToString(resultSequential) + "\n";
			richTextBox2->Text += "Метод Фібоначчі: " + System::Convert::ToString(resultFibonacci) + "\n";
			richTextBox2->Text += "Інтерполяційний метод: " + System::Convert::ToString(resultInterpolation) + "\n";
			richTextBox2->Text += "Метод Хеш-функції: " + System::Convert::ToString(resultHash) + "\n\n";

			//запис у файл
			search.writeToFile("result.txt", searchValue);
		}
	}
			


	return System::Void();
}

//про програму
System::Void KURSOVANEW::MyForm::AboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("\tЦя програма здійснює пошук заданих елементів у масиві \n\t\tДля цього використовуються методи:\n\n -послідовний\n-Фібоначі\n -інтерполяційний\n -Хеш-функцій\n\n Виконала Скрипець Ольга ІП-21", "Інформація про програму");
	return System::Void();
}

//вимкнення можливість введення тексту в richTextBox1
System::Void KURSOVANEW::MyForm::richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox1->ReadOnly = true;
	return System::Void();
}

//вимкнення можливість введення тексту в richTextBox2
System::Void KURSOVANEW::MyForm::richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox2->ReadOnly = true;
	return System::Void();
}







