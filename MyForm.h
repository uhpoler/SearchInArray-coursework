#pragma once

namespace KURSOVANEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		
		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonGenerate;
	protected:

	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ labelEnter;
	private: System::Windows::Forms::Button^ buttonWriteToFile;

	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ AboutProgramToolStripMenuItem;
	private: System::Windows::Forms::Button^ buttonSequential;
	private: System::Windows::Forms::Button^ buttonFibonacci;
	private: System::Windows::Forms::Button^ buttonInterpolation;
	private: System::Windows::Forms::Button^ buttonHash;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;

	private: System::Windows::Forms::Label^ labelTable;







	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->buttonGenerate = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->labelEnter = (gcnew System::Windows::Forms::Label());
			this->buttonWriteToFile = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->AboutProgramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonSequential = (gcnew System::Windows::Forms::Button());
			this->buttonFibonacci = (gcnew System::Windows::Forms::Button());
			this->buttonInterpolation = (gcnew System::Windows::Forms::Button());
			this->buttonHash = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->labelTable = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonGenerate
			// 
			this->buttonGenerate->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonGenerate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonGenerate->Location = System::Drawing::Point(102, 61);
			this->buttonGenerate->Name = L"buttonGenerate";
			this->buttonGenerate->Size = System::Drawing::Size(303, 97);
			this->buttonGenerate->TabIndex = 0;
			this->buttonGenerate->Text = L"����������� ����� ��������";
			this->buttonGenerate->UseVisualStyleBackColor = false;
			this->buttonGenerate->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerate_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::LightSkyBlue;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(27, 196);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(452, 345);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// labelEnter
			// 
			this->labelEnter->AutoSize = true;
			this->labelEnter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelEnter->Location = System::Drawing::Point(749, 152);
			this->labelEnter->Name = L"labelEnter";
			this->labelEnter->Size = System::Drawing::Size(292, 25);
			this->labelEnter->TabIndex = 17;
			this->labelEnter->Text = L"������ �������� ��� ������:";
			// 
			// buttonWriteToFile
			// 
			this->buttonWriteToFile->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonWriteToFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonWriteToFile->Location = System::Drawing::Point(782, 531);
			this->buttonWriteToFile->Name = L"buttonWriteToFile";
			this->buttonWriteToFile->Size = System::Drawing::Size(243, 50);
			this->buttonWriteToFile->TabIndex = 19;
			this->buttonWriteToFile->Text = L"�������� � ����";
			this->buttonWriteToFile->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->buttonWriteToFile->UseVisualStyleBackColor = false;
			this->buttonWriteToFile->Click += gcnew System::EventHandler(this, &MyForm::buttonWriteToFile_Click);
			// 
			// textBox
			// 
			this->textBox->BackColor = System::Drawing::Color::Azure;
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(782, 200);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(226, 27);
			this->textBox->TabIndex = 18;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::LightSkyBlue;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox2->Location = System::Drawing::Point(734, 250);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(331, 263);
			this->richTextBox2->TabIndex = 20;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->AboutProgramToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1595, 28);
			this->menuStrip1->TabIndex = 21;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AboutProgramToolStripMenuItem
			// 
			this->AboutProgramToolStripMenuItem->Name = L"AboutProgramToolStripMenuItem";
			this->AboutProgramToolStripMenuItem->Size = System::Drawing::Size(122, 24);
			this->AboutProgramToolStripMenuItem->Text = L"��� ��������";
			this->AboutProgramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::AboutProgramToolStripMenuItem_Click);
			// 
			// buttonSequential
			// 
			this->buttonSequential->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonSequential->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonSequential->Location = System::Drawing::Point(494, 250);
			this->buttonSequential->Name = L"buttonSequential";
			this->buttonSequential->Size = System::Drawing::Size(215, 47);
			this->buttonSequential->TabIndex = 22;
			this->buttonSequential->Text = L"����������";
			this->buttonSequential->UseVisualStyleBackColor = false;
			this->buttonSequential->Click += gcnew System::EventHandler(this, &MyForm::buttonSequential_Click);
			// 
			// buttonFibonacci
			// 
			this->buttonFibonacci->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonFibonacci->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFibonacci->Location = System::Drawing::Point(494, 320);
			this->buttonFibonacci->Name = L"buttonFibonacci";
			this->buttonFibonacci->Size = System::Drawing::Size(215, 47);
			this->buttonFibonacci->TabIndex = 23;
			this->buttonFibonacci->Text = L"Գ�������";
			this->buttonFibonacci->UseVisualStyleBackColor = false;
			this->buttonFibonacci->Click += gcnew System::EventHandler(this, &MyForm::buttonFibonacci_Click);
			// 
			// buttonInterpolation
			// 
			this->buttonInterpolation->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonInterpolation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonInterpolation->Location = System::Drawing::Point(494, 393);
			this->buttonInterpolation->Name = L"buttonInterpolation";
			this->buttonInterpolation->Size = System::Drawing::Size(215, 47);
			this->buttonInterpolation->TabIndex = 24;
			this->buttonInterpolation->Text = L"���������������";
			this->buttonInterpolation->UseVisualStyleBackColor = false;
			this->buttonInterpolation->Click += gcnew System::EventHandler(this, &MyForm::buttonInterpolation_Click);
			// 
			// buttonHash
			// 
			this->buttonHash->BackColor = System::Drawing::Color::DodgerBlue;
			this->buttonHash->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonHash->Location = System::Drawing::Point(494, 466);
			this->buttonHash->Name = L"buttonHash";
			this->buttonHash->Size = System::Drawing::Size(215, 47);
			this->buttonHash->TabIndex = 25;
			this->buttonHash->Text = L"���-�������";
			this->buttonHash->UseVisualStyleBackColor = false;
			this->buttonHash->Click += gcnew System::EventHandler(this, &MyForm::buttonHash_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::Color::LightSkyBlue;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox3->Location = System::Drawing::Point(1120, 200);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(452, 345);
			this->richTextBox3->TabIndex = 26;
			this->richTextBox3->Text = L"";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox3_TextChanged);
			// 
			// labelTable
			// 
			this->labelTable->AutoSize = true;
			this->labelTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTable->Location = System::Drawing::Point(1240, 152);
			this->labelTable->Name = L"labelTable";
			this->labelTable->Size = System::Drawing::Size(235, 25);
			this->labelTable->TabIndex = 27;
			this->labelTable->Text = L"��������� ��� �������";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1595, 666);
			this->Controls->Add(this->labelTable);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->buttonHash);
			this->Controls->Add(this->buttonInterpolation);
			this->Controls->Add(this->buttonFibonacci);
			this->Controls->Add(this->buttonSequential);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->buttonWriteToFile);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->labelEnter);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->buttonGenerate);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1613, 713);
			this->MinimumSize = System::Drawing::Size(1613, 713);
			this->Name = L"MyForm";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����� �������� �������� � �����";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonWriteToFile_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AboutProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonSequential_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonInterpolation_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonFibonacci_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonHash_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
};


}

