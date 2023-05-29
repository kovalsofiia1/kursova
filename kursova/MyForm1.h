#pragma once

namespace kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ f1l1;
	private: System::Windows::Forms::Label^ f1l2;
	private: System::Windows::Forms::TextBox^ f1t1;
	private: System::Windows::Forms::TextBox^ f1t2;
	protected:







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->f1l1 = (gcnew System::Windows::Forms::Label());
			this->f1l2 = (gcnew System::Windows::Forms::Label());
			this->f1t1 = (gcnew System::Windows::Forms::TextBox());
			this->f1t2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Number of elementary operations:\r\n";
			// 
			// f1l1
			// 
			this->f1l1->AutoSize = true;
			this->f1l1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->f1l1->Location = System::Drawing::Point(43, 83);
			this->f1l1->Name = L"f1l1";
			this->f1l1->Size = System::Drawing::Size(64, 25);
			this->f1l1->TabIndex = 1;
			this->f1l1->Text = L"label2";
			this->f1l1->Visible = false;
			// 
			// f1l2
			// 
			this->f1l2->AutoSize = true;
			this->f1l2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->f1l2->Location = System::Drawing::Point(43, 175);
			this->f1l2->Name = L"f1l2";
			this->f1l2->Size = System::Drawing::Size(64, 25);
			this->f1l2->TabIndex = 2;
			this->f1l2->Text = L"label3";
			this->f1l2->Visible = false;
			// 
			// f1t1
			// 
			this->f1t1->Location = System::Drawing::Point(47, 120);
			this->f1t1->Name = L"f1t1";
			this->f1t1->ReadOnly = true;
			this->f1t1->Size = System::Drawing::Size(100, 26);
			this->f1t1->TabIndex = 3;
			this->f1t1->Visible = false;
			// 
			// f1t2
			// 
			this->f1t2->Location = System::Drawing::Point(47, 220);
			this->f1t2->Name = L"f1t2";
			this->f1t2->ReadOnly = true;
			this->f1t2->Size = System::Drawing::Size(100, 26);
			this->f1t2->TabIndex = 4;
			this->f1t2->Visible = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(556, 317);
			this->Controls->Add(this->f1t2);
			this->Controls->Add(this->f1t1);
			this->Controls->Add(this->f1l2);
			this->Controls->Add(this->f1l1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->Text = L"Time characteristics";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		public:
			property TextBox^ f1t1Control
			{
				TextBox^ get() { return f1t1; }
			}
			property TextBox^ f1t2Control
			{
				TextBox^ get() { return f1t2; }
			}
			property Label^ f1l1Control
			{
				Label^ get() { return f1l1; }
			}
			property Label^ f1l2Control
			{
				Label^ get() { return f1l2; }
			}
#pragma endregion
	
	};
}
