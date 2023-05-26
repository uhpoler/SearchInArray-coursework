#include "AdditionalFunctions.h"


// ������� ��� ��������� ������ ���������� �����
void generateRandomArray(Search& search) {
	srand(static_cast<unsigned int>(time(nullptr)));
	int* arr = search.GetArray();
	for (int i = 0; i < search.GetArraySize(); i++) {
		arr[i] = rand();
	}
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


////������� ������ ���������� �� �����
//void writeToFile(const std::string& filename, RichTextBox^ richTextBox1, RichTextBox^ richTextBox2) {
//	std::ofstream file(filename, std::ios::app);
//
//	if (file.is_open()) {
//
//		System::String^ textArray = richTextBox1->Text;
//		System::String^ textResult = richTextBox2->Text;
//
//		std::string convertedTextArray = msclr::interop::marshal_as<std::string>(textArray);
//		std::string convertedTextResult = msclr::interop::marshal_as<std::string>(textResult);
//
//
//		file << "����� ��������: " << std::endl;
//		file << convertedTextArray << std::endl;
//		file << convertedTextResult << std::endl;
//		file << std::endl;
//
//
//		file.close();
//
//	}
//	else {
//		MessageBox::Show("������� ��� ������� ����� results.txt", "�������");
//	}
//
//
//}

