#include "AdditionalFunctions.h"


// Функція для генерації масиву випадкових чисел
void generateRandomArray(Search& search) {
	srand(static_cast<unsigned int>(time(nullptr)));
	int* arr = search.GetArray();
	bool* used = new bool[search.GetArraySize()] { false };

	for (int i = 0; i < search.GetArraySize(); i++) {
		int randomNumber;
		do {
			randomNumber = rand();
		} while (used[randomNumber % search.GetArraySize()]);

		arr[i] = randomNumber;
		used[randomNumber % search.GetArraySize()] = true;
	}

	delete[] used;
}

// Функція для сортування масиву за алгоритмом сортування вставкою
void insertionSort(Search& search) {
	int* arr = search.GetArray();
	for (int i = 1; i < search.GetArraySize(); i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
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


//функція для очищення підсвітки цифр
void clearHighlighting(System::Windows::Forms::RichTextBox^ richTextBox) {
	System::Drawing::Color lightBlueColor = System::Drawing::Color::FromArgb(135, 206, 250);

	richTextBox->SelectionStart = 0;
	richTextBox->SelectionLength = richTextBox->Text->Length;
	richTextBox->SelectionBackColor = lightBlueColor;
}