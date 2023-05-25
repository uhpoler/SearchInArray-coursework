#include "MyForm.h"
#include "Search.h"
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>

// �������� ����
using namespace System;
using namespace System::Windows::Forms; 
using namespace System::Runtime::InteropServices;



[STAThreadAttribute] //����� ����� ��� �����
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSOVANEW::MyForm form;
	Application::Run(% form);


}

Search search;
bool isButton1Clicked = false;

//������ ��������� ������
System::Void KURSOVANEW::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	isButton1Clicked = true;
	richTextBox1->Clear();

	generateRandomArray(search);
	insertionSort(search);

	//��������� ������ � richTextBox1
	for (int i = 0; i < search.arraySize; ++i) {
		richTextBox1->Text += System::Convert::ToString(search.array[i]);
		richTextBox1->Text += " ";
	}

	return System::Void();
}

//������ ������ �������, �� ��� ����������
System::Void KURSOVANEW::MyForm::buttonFind_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked){
		MessageBox::Show("�������: �������� ���������� �����!");
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


				richTextBox2->Text += "\n��������� ������ ����� " + input  + " ������ ��������: \n\n";

				richTextBox2->Text += "���������� �����: " + System::Convert::ToString(resultSequential) + "\n";
				richTextBox2->Text += "����� Գ�������: " + System::Convert::ToString(resultFibonacci) + "\n";
				richTextBox2->Text += "��������������� �����: " + System::Convert::ToString(resultInterpolation) + "\n";
				richTextBox2->Text += "����� ���-�������: " + System::Convert::ToString(resultHash) + "\n";


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

System::Void KURSOVANEW::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("\t�� �������� ������� ����� ������� �������� � ����� \n\t\t��� ����� ���������������� ������:\n\n -����������\n-Գ������\n -���������������\n -���-�������\n\n �������� �������� ����� ��-21", "���������� ��� ��������");


	return System::Void();
}






bool ValidateSearchValue(String^ input)
{
	// �������� �������� ����� � TextBox
	//System::String^ input = textBox->Text;

	// ����������, �� ����� �� �������

	if (input->Length == 0)
	{
		MessageBox::Show("������ �����", "�������");
		return false;
	}

	// ����������, �� ����� ���������� ���� � ����
	for each (wchar_t c in input)
	{
		if (!System::Char::IsDigit(c))
		{
			MessageBox::Show("�������� ���� �����, ������������ ���� �����", "�������");
			return false;
		}
	}

	// ������������ ����� � ���� �����
	int searchValue = System::Convert::ToInt32(input);

	// ����������, �� ����� ����������� � ����������� �������
	if (searchValue < 0 || searchValue > 100000)
	{
		MessageBox::Show("����� �� ���� �� 0 �� 10000", "�������");
		return false;
	}

	// �� �������� ��������, ����� � ������ �� �������
	return true;
}




int getValidatedSearchValue(Search& search, int searchValue) {

	bool validValue = false;

	do {

		// ��������, �� ������� �������� ����������� � �����
		for (int i = 0; i < search.arraySize; i++) {
			if (search.array[i] == searchValue) {
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


void writeToFile(const std::string& filename,  RichTextBox^ richTextBox1, RichTextBox^ richTextBox2) {
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) {
		// ��������� ������ � RichTextBox
		System::String^ textArray = richTextBox1->Text;
		System::String^ textResult = richTextBox2->Text;

		// ����������� � System::String^ � std::string
		std::string convertedTextArray = msclr::interop::marshal_as<std::string>(textArray);
		std::string convertedTextResult = msclr::interop::marshal_as<std::string>(textResult);


		// ����� ������ � ����
		file << "����� ��������: " << std::endl;
		file << convertedTextArray << std::endl;
		file << convertedTextResult << std::endl;
		file << std::endl;

		// �������� ������
		file.close();

	}
	else {
		MessageBox::Show("������� ��� ������� ����� results.txt", "�������");
	}


}


