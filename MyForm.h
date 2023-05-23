#pragma once

namespace KURSOVANEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ labelEnter;
	private: System::Windows::Forms::Button^ buttonFind;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->labelEnter = (gcnew System::Windows::Forms::Label());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(46, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(231, 108);
			this->button1->TabIndex = 0;
			this->button1->Text = L"«генерувати масив елемент≥в";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(18, 230);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(307, 230);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// labelEnter
			// 
			this->labelEnter->AutoSize = true;
			this->labelEnter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelEnter->Location = System::Drawing::Point(533, 75);
			this->labelEnter->Name = L"labelEnter";
			this->labelEnter->Size = System::Drawing::Size(292, 25);
			this->labelEnter->TabIndex = 17;
			this->labelEnter->Text = L"¬вед≥ть значенн€ дл€ пошуку:";
			// 
			// buttonFind
			// 
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFind->Location = System::Drawing::Point(616, 173);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(128, 34);
			this->buttonFind->TabIndex = 19;
			this->buttonFind->Text = L"знайти";
			this->buttonFind->UseVisualStyleBackColor = true;
			this->buttonFind->Click += gcnew System::EventHandler(this, &MyForm::buttonFind_Click);
			// 
			// textBox
			// 
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(616, 136);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(128, 27);
			this->textBox->TabIndex = 18;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(518, 230);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(307, 230);
			this->richTextBox2->TabIndex = 20;
			this->richTextBox2->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 536);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->labelEnter);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e);

};
}
