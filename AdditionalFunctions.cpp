#include "AdditionalFunctions.h"




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
void writeToFile(const std::string& filename, RichTextBox^ richTextBox1, RichTextBox^ richTextBox2) {
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

