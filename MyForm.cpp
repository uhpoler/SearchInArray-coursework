#include "MyForm.h"
#include "Search.h"
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>

// простори імен
using namespace System;
using namespace System::Windows::Forms; 
using namespace System::Runtime::InteropServices;



[STAThreadAttribute] //точка входу для форми
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSOVANEW::MyForm form;
	Application::Run(% form);


}

Search search;
bool isButton1Clicked = false;

//кнопка генерації масиву
System::Void KURSOVANEW::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	isButton1Clicked = true;
	richTextBox1->Clear();

	generateRandomArray(search);
	insertionSort(search);

	//виведення масиву в richTextBox1
	for (int i = 0; i < search.arraySize; ++i) {
		richTextBox1->Text += System::Convert::ToString(search.array[i]);
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


	String^ input = textBox->Text;
	
		

		if (ValidateSearchValue(input)) {

			int searchValue = Convert::ToInt32(input);
			searchValue = getValidatedSearchValue(search, searchValue);


			if (searchValue == 0) {
				textBox->Clear();

			}
			else {

				int resultSequential = search.sequentialSearch(searchValue);
				int resultFibonacci = search.fibonacciSearch(searchValue);
				int resultInterpolation = search.interpolationSearch(searchValue);
				int resultHash = search.hashSearch(searchValue);


				richTextBox2->Text += "\nРезультат пошуку числа " + input  + " різними методами: \n\n";

				richTextBox2->Text += "Послідовний метод: " + System::Convert::ToString(resultSequential) + "\n";
				richTextBox2->Text += "Метод Фібоначчі: " + System::Convert::ToString(resultFibonacci) + "\n";
				richTextBox2->Text += "Інтерполяційний метод: " + System::Convert::ToString(resultInterpolation) + "\n";
				richTextBox2->Text += "Метод Хеш-функції: " + System::Convert::ToString(resultHash) + "\n";


			}


		}
			



		writeToFile("result.txt", richTextBox1, richTextBox2);




			//getValidatedSearchValue(search, searchValue);



			//String^ value = textBox->Text->ToString();

			//textBox->Clear();
			//textBox->Text == "";

			//String^ value = textBox->Text->ToString();
			//std::string input = ConvertString(value);

			////validateSearchValue(input);

			//String^ temp;
			//ConvertString(input, temp);

			//int searchValue = Convert::ToInt32(temp);

	
			//searchValue = Convert::ToInt32(textBox->Text);

			//validateSearchValue(searchValue);
			//labelEnter->Text = System::Convert::ToString(searchValue);


	return System::Void();
}

System::Void KURSOVANEW::MyForm::проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("\tЦя програма здійснює пошук заданих елементів у масиві \n\t\tДля цього використовуються методи:\n\n -послідовний\n-Фібоначі\n -інтерполяційний\n -Хеш-функцій\n\n Виконала Скрипець Ольга ІП-21", "Інформація про програму");


	return System::Void();
}






bool ValidateSearchValue(String^ input)
{
	// Отримуємо введений рядок з TextBox
	//System::String^ input = textBox->Text;

	// Перевіряємо, чи рядок не порожній

	if (input->Length == 0)
	{
		MessageBox::Show("Уведіть число", "Помилка");
		return false;
	}

	// Перевіряємо, чи рядок складається лише з цифр
	for each (wchar_t c in input)
	{
		if (!System::Char::IsDigit(c))
		{
			MessageBox::Show("Напишіть одне число, використавши лише цифри", "Помилка");
			return false;
		}
	}

	// Перетворюємо рядок в ціле число
	int searchValue = System::Convert::ToInt32(input);

	// Перевіряємо, чи число знаходиться в допустимому діапазоні
	if (searchValue < 0 || searchValue > 100000)
	{
		MessageBox::Show("Число має бути від 0 до 10000", "Помилка");
		return false;
	}

	// Всі перевірки пройдено, число є дійсним та валідним
	return true;
}




int getValidatedSearchValue(Search& search, int searchValue) {

	bool validValue = false;

	do {

		// Перевірка, чи введене значення знаходиться у масиві
		for (int i = 0; i < search.arraySize; i++) {
			if (search.array[i] == searchValue) {
				validValue = true;
				break;
			}

		}
		if (!validValue) {
			MessageBox::Show("Введене значення не знайдено в масиві. Будь ласка, спробуйте ще раз.", "Помилка");
			searchValue = 0;
			validValue = true;

		}
	} while (!validValue);
	
	return searchValue;
}


void writeToFile(const std::string& filename,  RichTextBox^ richTextBox1, RichTextBox^ richTextBox2) {
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) {
		// Отримання тексту з RichTextBox
		System::String^ textArray = richTextBox1->Text;
		System::String^ textResult = richTextBox2->Text;

		// Конвертація з System::String^ в std::string
		std::string convertedTextArray = msclr::interop::marshal_as<std::string>(textArray);
		std::string convertedTextResult = msclr::interop::marshal_as<std::string>(textResult);


		// Запис тексту у файл
		file << "Масив елементів: " << std::endl;
		file << convertedTextArray << std::endl;
		file << convertedTextResult << std::endl;
		file << std::endl;

		// Закриття потоку
		file.close();

	}
	else {
		MessageBox::Show("Помилка при відкритті файлу results.txt", "Помилка");
	}


}


