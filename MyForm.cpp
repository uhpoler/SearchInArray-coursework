#include "MyForm.h"
#include "Search.h"
#include "AdditionalFunctions.h"


// �������� ����
using namespace System;
using namespace System::Windows::Forms; 



//����� ����� ��� �����
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	KURSOVANEW::MyForm form;
	Application::Run(% form);


}

Search search;
bool isButton1Clicked = false;

//������ ��������� ������
System::Void KURSOVANEW::MyForm::buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void KURSOVANEW::MyForm::buttonWriteToFile_Click(System::Object^ sender, System::EventArgs^ e)
{


	if (!isButton1Clicked){
		MessageBox::Show("�������: �������� ���������� �����!");
		return;
	}


	String^ input = textBox->Text;
	int searchValue = Convert::ToInt32(input);

	//����� � ����
	search.writeToFile("result.txt", searchValue);

	//richTextBox2->Clear();
	


	return System::Void();
}

//��� ��������
System::Void KURSOVANEW::MyForm::AboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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








System::Void KURSOVANEW::MyForm::buttonSequential_Click(System::Object^ sender, System::EventArgs^ e)
{



	if (!isButton1Clicked) {
		MessageBox::Show("�������: �������� ���������� �����!");
		return;
	}

	//richTextBox2->Clear();
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


			//���� ����������
			richTextBox2->Text += "��������� ������ ����� " + input + " ������ ��������: \n\n";
			richTextBox2->Text += "���������� �����: " + System::Convert::ToString(resultSequential) + "\n";

		}
	}


	return System::Void();
}

System::Void KURSOVANEW::MyForm::buttonInterpolation_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked) {
		MessageBox::Show("�������: �������� ���������� �����!");
		return;
	}

	//richTextBox2->Clear();
	String^ input = textBox->Text;


	if (validateSearchValue(input)) {

		int searchValue = Convert::ToInt32(input);
		searchValue = checkValueInArray(search, searchValue);


		if (searchValue == 0) {
			textBox->Clear();

		}
		else {

			//����� ����� � �����
			int resultInterpolation = search.interpolationSearch(searchValue);


			//���� ����������
			richTextBox2->Text += "��������� ������ ����� " + input + " ������ ��������: \n\n";
			richTextBox2->Text += "��������������� �����: " + System::Convert::ToString(resultInterpolation) + "\n";


		}
	}
	return System::Void();
}

System::Void KURSOVANEW::MyForm::buttonFibonacci_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked) {
		MessageBox::Show("�������: �������� ���������� �����!");
		return;
	}

	//richTextBox2->Clear();
	String^ input = textBox->Text;


	if (validateSearchValue(input)) {

		int searchValue = Convert::ToInt32(input);
		searchValue = checkValueInArray(search, searchValue);


		if (searchValue == 0) {
			textBox->Clear();

		}
		else {

			//����� ����� � �����
			int resultFibonacci = search.fibonacciSearch(searchValue);

			//���� ����������
			richTextBox2->Text += "��������� ������ ����� " + input + " ������ ��������: \n\n";
			richTextBox2->Text += "����� Գ�������: " + System::Convert::ToString(resultFibonacci) + "\n";


		}
	}
	return System::Void();
}

System::Void KURSOVANEW::MyForm::buttonHash_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (!isButton1Clicked) {
		MessageBox::Show("�������: �������� ���������� �����!");
		return;
	}

	//richTextBox2->Clear();
	String^ input = textBox->Text;


	if (validateSearchValue(input)) {

		int searchValue = Convert::ToInt32(input);
		searchValue = checkValueInArray(search, searchValue);


		if (searchValue == 0) {
			textBox->Clear();

		}
		else {

			//����� ����� � �����
			int resultHash = search.hashSearch(searchValue, search.GetArray());

			//���� ����������
			richTextBox2->Text += "��������� ������ ����� " + input + " ������ ��������: \n\n";
			richTextBox2->Text += "����� ���-�������: " + System::Convert::ToString(resultHash) + "\n\n";


		}
	}
	return System::Void();
}

System::Void KURSOVANEW::MyForm::textBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

	richTextBox2->Clear();
	return System::Void();
}




