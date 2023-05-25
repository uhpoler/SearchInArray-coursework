#include "MyForm.h"
#include "Search.h"


// простори імен
using namespace System;
using namespace System::Windows::Forms; 




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
			int resultHash = search.hashSearch(searchValue);

			//вивід результатів
			richTextBox2->Text += "Результат пошуку числа " + input  + " різними методами: \n\n";
			richTextBox2->Text += "Послідовний метод: " + System::Convert::ToString(resultSequential) + "\n";
			richTextBox2->Text += "Метод Фібоначчі: " + System::Convert::ToString(resultFibonacci) + "\n";
			richTextBox2->Text += "Інтерполяційний метод: " + System::Convert::ToString(resultInterpolation) + "\n";
			richTextBox2->Text += "Метод Хеш-функції: " + System::Convert::ToString(resultHash) + "\n\n";
		}
	}
			
		//запис у файл
		writeToFile("result.txt", richTextBox1, richTextBox2);


	return System::Void();
}

//про програму
System::Void KURSOVANEW::MyForm::проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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















//функція валідації введеного значення
bool validateSearchValue(String^ input)
{

	//перевірка чи рядок не порожній
	if (input->Length == 0)
	{
		MessageBox::Show("Уведіть число", "Помилка");
		return false;
	}

	//перевірка чи рядок складається лише з цифр
	for each (wchar_t c in input)
	{
		if (!System::Char::IsDigit(c))
		{
			MessageBox::Show("Напишіть одне число, використавши лише цифри", "Помилка");
			return false;
		}
	}


	int searchValue = System::Convert::ToInt32(input);

	//перевірка чи число знаходиться в допустимому діапазоні
	if (searchValue < 0 || searchValue > 100000)
	{
		MessageBox::Show("Число має бути від 0 до 10000", "Помилка");
		return false;
	}

	return true;
}



//функція перевірки чи число знаходиться у масиві
int checkValueInArray(Search& search, int searchValue) {

	bool validValue = false;

	do {

		//перевірка, чи введене значення знаходиться у масиві
		int* arr = search.GetArray();
		for (int i = 0; i < search.GetArraySize(); i++) {
			if (arr[i] == searchValue) {
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


//функція запису результатів до файлу
void writeToFile(const std::string& filename,  RichTextBox^ richTextBox1, RichTextBox^ richTextBox2) {
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) {
	
		System::String^ textArray = richTextBox1->Text;
		System::String^ textResult = richTextBox2->Text;

		std::string convertedTextArray = msclr::interop::marshal_as<std::string>(textArray);
		std::string convertedTextResult = msclr::interop::marshal_as<std::string>(textResult);


		file << "Масив елементів: " << std::endl;
		file << convertedTextArray << std::endl;
		file << convertedTextResult << std::endl;
		file << std::endl;


		file.close();

	}
	else {
		MessageBox::Show("Помилка при відкритті файлу results.txt", "Помилка");
	}


}


