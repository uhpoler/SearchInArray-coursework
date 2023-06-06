#include "AdditionalFunctions.h"


// ������� ��� ��������� ������ ���������� �����
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

// ������� ��� ���������� ������ �� ���������� ���������� ��������
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


//������� �������� ��������� ��������
bool validateSearchValue(String^ input)
{

	//�������� �� ����� �� �������
	if (input->Length == 0)
	{
		MessageBox::Show("������ �����", "�������");
		return false;
	}

	//�������� �� ����� ���������� ���� � ����
	for each (wchar_t c in input)
	{
		if (!System::Char::IsDigit(c))
		{
			MessageBox::Show("�������� ���� �����, ������������ ���� �����", "�������");
			return false;
		}
	}


	int searchValue = System::Convert::ToInt32(input);

	//�������� �� ����� ����������� � ����������� �������
	if (searchValue < 0 || searchValue > 100000)
	{
		MessageBox::Show("����� �� ���� �� 0 �� 10000", "�������");
		return false;
	}

	return true;
}



//������� �������� �� ����� ����������� � �����
int checkValueInArray(Search& search, int searchValue) {

	bool validValue = false;

	do {

		//��������, �� ������� �������� ����������� � �����
		int* arr = search.GetArray();
		for (int i = 0; i < search.GetArraySize(); i++) {
			if (arr[i] == searchValue) {
				validValue = true;
				break;
			}

		}
		if (!validValue) {
			MessageBox::Show("������� �������� �� �������� � �����. ���� �����, ��������� �� ���.", "�������");
			searchValue = 0;
			validValue = true;

		}
	} while (!validValue);

	return searchValue;
}


//������� ��� �������� ������� ����
void clearHighlighting(System::Windows::Forms::RichTextBox^ richTextBox) {
	System::Drawing::Color lightBlueColor = System::Drawing::Color::FromArgb(135, 206, 250);

	richTextBox->SelectionStart = 0;
	richTextBox->SelectionLength = richTextBox->Text->Length;
	richTextBox->SelectionBackColor = lightBlueColor;
}