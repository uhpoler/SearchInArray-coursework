#include "MyForm.h"
#include "Search.h"


// �������� ����
using namespace System;
using namespace System::Windows::Forms; 




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
	int* arr = search.GetArray();
	for (int i = 0; i < search.GetArraySize(); ++i) {
		richTextBox1->Text += System::Convert::ToString(arr[i]);
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
		

	if (validateSearchValue(input)) {

		int searchValue = Convert::ToInt32(input);
		searchValue = checkValueInArray(search, searchValue);


		if (searchValue == 0) {
			textBox->Clear();

		}
		else {

			//����� ����� � �����
			int resultSequential = search.sequentialSearch(searchValue);
			int resultFibonacci = search.fibonacciSearch(searchValue);
			int resultInterpolation = search.interpolationSearch(searchValue);
			int resultHash = search.hashSearch(searchValue);

			//���� ����������
			richTextBox2->Text += "��������� ������ ����� " + input  + " ������ ��������: \n\n";
			richTextBox2->Text += "���������� �����: " + System::Convert::ToString(resultSequential) + "\n";
			richTextBox2->Text += "����� Գ�������: " + System::Convert::ToString(resultFibonacci) + "\n";
			richTextBox2->Text += "��������������� �����: " + System::Convert::ToString(resultInterpolation) + "\n";
			richTextBox2->Text += "����� ���-�������: " + System::Convert::ToString(resultHash) + "\n\n";
		}
	}
			
		//����� � ����
		writeToFile("result.txt", richTextBox1, richTextBox2);


	return System::Void();
}

//��� ��������
System::Void KURSOVANEW::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("\t�� �������� ������� ����� ������� �������� � ����� \n\t\t��� ����� ���������������� ������:\n\n -����������\n-Գ������\n -���������������\n -���-�������\n\n �������� �������� ����� ��-21", "���������� ��� ��������");
	return System::Void();
}

//��������� ��������� �������� ������ � richTextBox1
System::Void KURSOVANEW::MyForm::richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox1->ReadOnly = true;
	return System::Void();
}

//��������� ��������� �������� ������ � richTextBox2
System::Void KURSOVANEW::MyForm::richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox2->ReadOnly = true;
	return System::Void();
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


//������� ������ ���������� �� �����
void writeToFile(const std::string& filename,  RichTextBox^ richTextBox1, RichTextBox^ richTextBox2) {
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) {
	
		System::String^ textArray = richTextBox1->Text;
		System::String^ textResult = richTextBox2->Text;

		std::string convertedTextArray = msclr::interop::marshal_as<std::string>(textArray);
		std::string convertedTextResult = msclr::interop::marshal_as<std::string>(textResult);


		file << "����� ��������: " << std::endl;
		file << convertedTextArray << std::endl;
		file << convertedTextResult << std::endl;
		file << std::endl;


		file.close();

	}
	else {
		MessageBox::Show("������� ��� ������� ����� results.txt", "�������");
	}


}


