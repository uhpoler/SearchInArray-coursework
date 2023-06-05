#include "MyForm.h"
#include "Search.h"
#include "AdditionalFunctions.h"


// простори імен
using namespace System;
using namespace System::Windows::Forms; 
using namespace System::Drawing;



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

//кнопка запису результатів у файл
System::Void KURSOVANEW::MyForm::buttonWriteToFile_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!isButton1Clicked){
		MessageBox::Show("Помилка: Спочатку згенеруйте масив!");
		return;
	}

	System::IO::File::AppendAllText("results.txt", "\n"+ richTextBox1->Text + "\n" + richTextBox2->Text);
	MessageBox::Show("Результати збережено у файлі results.txt");

	richTextBox2->Clear();
	
	return System::Void();
}





//Послідовний метод
System::Void KURSOVANEW::MyForm::buttonSequential_Click(System::Object^ sender, System::EventArgs^ e)
{



	if (!isButton1Clicked) {
		MessageBox::Show("Помилка: Спочатку згенеруйте масив!");
		return;
	}

	clearHighlighting(richTextBox1);
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
			int resultSequential = search.sequentialSearch(searchValue, richTextBox1);

			//вивід результатів
			richTextBox2->Text += "Результат пошуку числа " + input + " \n\n";
			richTextBox2->Text += "Послідовний метод: " + System::Convert::ToString(resultSequential) + "\n";

		

		}
	}


	return System::Void();
}

//Метод інтерполяційного пошуку
System::Void KURSOVANEW::MyForm::buttonInterpolation_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked) {
		MessageBox::Show("Помилка: Спочатку згенеруйте масив!");
		return;
	}

	clearHighlighting(richTextBox1);
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
			int resultInterpolation = search.interpolationSearch(searchValue, richTextBox1);


			//вивід результатів
			richTextBox2->Text += "Результат пошуку числа " + input + " \n\n";
			richTextBox2->Text += "Інтерполяційний метод: " + System::Convert::ToString(resultInterpolation) + "\n";


		}
	}
	return System::Void();
}

//Пошук методом Фібоначчі
System::Void KURSOVANEW::MyForm::buttonFibonacci_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked) {
		MessageBox::Show("Помилка: Спочатку згенеруйте масив!");
		return;
	}


	clearHighlighting(richTextBox1);
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
			int resultFibonacci = search.fibonacciSearch(searchValue, richTextBox1);

			//вивід результатів
			richTextBox2->Text += "Результат пошуку числа " + input + " \n\n";
			richTextBox2->Text += "Метод Фібоначчі: " + System::Convert::ToString(resultFibonacci) + "\n";


		}
	}
	return System::Void();
}

//Пошук методом Хеш-функції
System::Void KURSOVANEW::MyForm::buttonHash_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked) {
		MessageBox::Show("Помилка: Спочатку згенеруйте масив!");
		return;
	}

	clearHighlighting(richTextBox1);
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
			int resultHash = search.hashSearch(searchValue, search.GetArray(), richTextBox1);

			//вивід результатів
			richTextBox2->Text += "Результат пошуку числа " + input + " \n\n";
			richTextBox2->Text += "Метод Хеш-функції: " + System::Convert::ToString(resultHash) + "\n\n";


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

//очищення вводу
System::Void KURSOVANEW::MyForm::textBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

	richTextBox2->Clear();
	return System::Void();
}




