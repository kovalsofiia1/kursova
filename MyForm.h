#pragma once
#include<vector>
#include"Header.h"
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

namespace kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Addbutton;
	protected:

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ x_input;
	private: System::Windows::Forms::CheckBox^ ch_b_linear;
	private: System::Windows::Forms::CheckBox^ ch_b_cubic;





	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ y_input;


	private: System::Windows::Forms::Label^ warning;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ num_of_interp_points;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ value_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridView^ linear_inter_points;

	private: System::Windows::Forms::DataGridView^ cubic_inter_points;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ xp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ yp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ xp_c;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ yp_c;
	private: System::Windows::Forms::Label^ L_interp_label;
	private: System::Windows::Forms::Label^ C_interp_label;
	private: System::Windows::Forms::ListBox^ listBox1;









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->Addbutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->x_input = (gcnew System::Windows::Forms::TextBox());
			this->ch_b_linear = (gcnew System::Windows::Forms::CheckBox());
			this->ch_b_cubic = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->y_input = (gcnew System::Windows::Forms::TextBox());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->num_of_interp_points = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->value_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->linear_inter_points = (gcnew System::Windows::Forms::DataGridView());
			this->xp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->yp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cubic_inter_points = (gcnew System::Windows::Forms::DataGridView());
			this->xp_c = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->yp_c = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->L_interp_label = (gcnew System::Windows::Forms::Label());
			this->C_interp_label = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->value_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->linear_inter_points))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cubic_inter_points))->BeginInit();
			this->SuspendLayout();
			// 
			// Addbutton
			// 
			this->Addbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Addbutton->Location = System::Drawing::Point(386, 266);
			this->Addbutton->Name = L"Addbutton";
			this->Addbutton->Size = System::Drawing::Size(146, 40);
			this->Addbutton->TabIndex = 0;
			this->Addbutton->Text = L"Додати точку";
			this->Addbutton->UseVisualStyleBackColor = true;
			this->Addbutton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(350, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(473, 44);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Розв\'язання задач інтерполяції";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// x_input
			// 
			this->x_input->Location = System::Drawing::Point(72, 272);
			this->x_input->Name = L"x_input";
			this->x_input->Size = System::Drawing::Size(100, 26);
			this->x_input->TabIndex = 4;
			this->x_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::x_input_KeyPress);
			// 
			// ch_b_linear
			// 
			this->ch_b_linear->AutoSize = true;
			this->ch_b_linear->Location = System::Drawing::Point(32, 130);
			this->ch_b_linear->Name = L"ch_b_linear";
			this->ch_b_linear->Size = System::Drawing::Size(190, 24);
			this->ch_b_linear->TabIndex = 5;
			this->ch_b_linear->Text = L"Лінійна інтерполяція";
			this->ch_b_linear->UseVisualStyleBackColor = true;
			// 
			// ch_b_cubic
			// 
			this->ch_b_cubic->AutoSize = true;
			this->ch_b_cubic->Location = System::Drawing::Point(32, 160);
			this->ch_b_cubic->Name = L"ch_b_cubic";
			this->ch_b_cubic->Size = System::Drawing::Size(299, 24);
			this->ch_b_cubic->TabIndex = 6;
			this->ch_b_cubic->Text = L"Інтерполяція кубічними сплайнами";
			this->ch_b_cubic->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(23, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(308, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Оберіть метод інтерполяції:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(37, 225);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(264, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Введіть координати точки:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(28, 272);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 26);
			this->label4->TabIndex = 9;
			this->label4->Text = L"x:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(205, 272);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 25);
			this->label5->TabIndex = 10;
			this->label5->Text = L"y:";
			// 
			// y_input
			// 
			this->y_input->Location = System::Drawing::Point(251, 271);
			this->y_input->Name = L"y_input";
			this->y_input->Size = System::Drawing::Size(100, 26);
			this->y_input->TabIndex = 11;
			this->y_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::y_input_KeyPress);
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->ForeColor = System::Drawing::Color::Red;
			this->warning->Location = System::Drawing::Point(29, 311);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(0, 20);
			this->warning->TabIndex = 13;
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(606, 91);
			this->chart->Margin = System::Windows::Forms::Padding(1);
			this->chart->Name = L"chart";
			this->chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->Legend = L"Legend1";
			series1->Name = L"Інтерполяція кубічними сплайнами";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(510, 307);
			this->chart->TabIndex = 10;
			this->chart->Text = L"chart1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(29, 564);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(183, 40);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Кількість\r\n інтерполяційних точок";
			// 
			// num_of_interp_points
			// 
			this->num_of_interp_points->Location = System::Drawing::Point(231, 578);
			this->num_of_interp_points->Name = L"num_of_interp_points";
			this->num_of_interp_points->Size = System::Drawing::Size(100, 26);
			this->num_of_interp_points->TabIndex = 16;
			this->num_of_interp_points->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(358, 564);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(158, 40);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Інтерполювати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// value_table
			// 
			this->value_table->AllowUserToAddRows = false;
			this->value_table->AllowUserToDeleteRows = false;
			this->value_table->AllowUserToResizeColumns = false;
			this->value_table->AllowUserToResizeRows = false;
			this->value_table->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->value_table->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->value_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->value_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->value_table->Location = System::Drawing::Point(55, 328);
			this->value_table->Name = L"value_table";
			this->value_table->ReadOnly = true;
			this->value_table->RowHeadersWidth = 10;
			this->value_table->RowTemplate->Height = 28;
			this->value_table->Size = System::Drawing::Size(197, 205);
			this->value_table->TabIndex = 18;
			this->value_table->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::value_table_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->FillWeight = 50;
			this->Column1->HeaderText = L"x";
			this->Column1->MinimumWidth = 8;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"y";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->Width = 50;
			// 
			// linear_inter_points
			// 
			this->linear_inter_points->AllowUserToAddRows = false;
			this->linear_inter_points->AllowUserToDeleteRows = false;
			this->linear_inter_points->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->linear_inter_points->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->linear_inter_points->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->linear_inter_points->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->xp,
					this->yp
			});
			this->linear_inter_points->Location = System::Drawing::Point(629, 461);
			this->linear_inter_points->Name = L"linear_inter_points";
			this->linear_inter_points->ReadOnly = true;
			this->linear_inter_points->RowHeadersWidth = 10;
			this->linear_inter_points->RowTemplate->Height = 28;
			this->linear_inter_points->Size = System::Drawing::Size(200, 286);
			this->linear_inter_points->TabIndex = 19;
			this->linear_inter_points->Visible = false;
			// 
			// xp
			// 
			this->xp->HeaderText = L"x";
			this->xp->MinimumWidth = 8;
			this->xp->Name = L"xp";
			this->xp->ReadOnly = true;
			this->xp->Width = 50;
			// 
			// yp
			// 
			this->yp->HeaderText = L"y";
			this->yp->MinimumWidth = 8;
			this->yp->Name = L"yp";
			this->yp->ReadOnly = true;
			this->yp->Width = 50;
			// 
			// cubic_inter_points
			// 
			this->cubic_inter_points->AllowUserToAddRows = false;
			this->cubic_inter_points->AllowUserToDeleteRows = false;
			this->cubic_inter_points->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->cubic_inter_points->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cubic_inter_points->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->cubic_inter_points->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->xp_c,
					this->yp_c
			});
			this->cubic_inter_points->Location = System::Drawing::Point(918, 461);
			this->cubic_inter_points->Name = L"cubic_inter_points";
			this->cubic_inter_points->ReadOnly = true;
			this->cubic_inter_points->RowHeadersWidth = 10;
			this->cubic_inter_points->RowTemplate->Height = 28;
			this->cubic_inter_points->Size = System::Drawing::Size(198, 286);
			this->cubic_inter_points->TabIndex = 20;
			this->cubic_inter_points->Visible = false;
			// 
			// xp_c
			// 
			this->xp_c->HeaderText = L"x";
			this->xp_c->MinimumWidth = 8;
			this->xp_c->Name = L"xp_c";
			this->xp_c->ReadOnly = true;
			this->xp_c->Width = 50;
			// 
			// yp_c
			// 
			this->yp_c->HeaderText = L"y";
			this->yp_c->MinimumWidth = 8;
			this->yp_c->Name = L"yp_c";
			this->yp_c->ReadOnly = true;
			this->yp_c->Width = 50;
			// 
			// L_interp_label
			// 
			this->L_interp_label->AutoSize = true;
			this->L_interp_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L_interp_label->Location = System::Drawing::Point(602, 424);
			this->L_interp_label->Name = L"L_interp_label";
			this->L_interp_label->Size = System::Drawing::Size(203, 22);
			this->L_interp_label->TabIndex = 21;
			this->L_interp_label->Text = L"Лінійна інтерполяція";
			this->L_interp_label->Visible = false;
			// 
			// C_interp_label
			// 
			this->C_interp_label->AutoSize = true;
			this->C_interp_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C_interp_label->Location = System::Drawing::Point(881, 413);
			this->C_interp_label->Name = L"C_interp_label";
			this->C_interp_label->Size = System::Drawing::Size(235, 44);
			this->C_interp_label->TabIndex = 22;
			this->C_interp_label->Text = L"Інтерполяція кубічними \r\nсплайнами";
			this->C_interp_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C_interp_label->Visible = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(33, 619);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(542, 224);
			this->listBox1->TabIndex = 23;
			this->listBox1->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1178, 854);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->C_interp_label);
			this->Controls->Add(this->L_interp_label);
			this->Controls->Add(this->cubic_inter_points);
			this->Controls->Add(this->linear_inter_points);
			this->Controls->Add(this->value_table);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->num_of_interp_points);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->y_input);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ch_b_cubic);
			this->Controls->Add(this->ch_b_linear);
			this->Controls->Add(this->x_input);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Addbutton);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->value_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->linear_inter_points))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cubic_inter_points))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		List < double >^ x = gcnew List<double>();
		List<double>^ y = gcnew List<double>();

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ x1 = x_input->Text;
		String^ y1 = y_input->Text;

		string x_inp = marshal_as<string>(x1);
		string y_inp = marshal_as<string>(y1);
		double xx, yy;
		warning->Text = "";
		x_input->ForeColor = Color::Black;
		y_input->ForeColor = Color::Black;
		xx = Convert::ToDouble(x1);
		yy = Convert::ToDouble(y1);

		for (int i = 0; i < x->Count; i++) {
			std::cout << x[i] << " ";
		}
		std::cout << endl;
		if (x_inp == "" || y_inp == "") {
			MessageBox::Show("Please input coordinates!");
		}
		else {
			int same = 0;
			for (int i = 0; i < x->Count; i++) {
				if (xx == x[i]) {
					same = 1;
					MessageBox::Show("You can't have two points with the same x coordinate!");
				}
			}
			if (same == 0) {
				x_input->Text = "";
				y_input->Text = "";
				x->Add(xx);
				y->Add(yy);
				value_table->Rows->Add(x1, y1);
			}
		}

		dotEnteredx = false;
		dotEnteredy = false;
	}
	private:bool dotEnteredx = false;
	private:bool dotEnteredy = false;
	private: System::Void x_input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
			MessageBox::Show("Please enter only numbers.");
			e->Handled = true;
		}
		else if (e->KeyChar == ',' && dotEnteredx) {
			MessageBox::Show("You have already entered a decimal point.");
			e->Handled = true;
		}
		else {
			dotEnteredx = (e->KeyChar == ',') ? true : dotEnteredx;
		}

	}
	private: System::Void y_input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
			MessageBox::Show("Please enter only numbers.");
			e->Handled = true;
		}
		else if (e->KeyChar == ',' && dotEnteredy) {
			MessageBox::Show("You have already entered a decimal point.");
			e->Handled = true;
		}
		else {
			dotEnteredy = (e->KeyChar == ',') ? true : dotEnteredy;
		}
	}


	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
			MessageBox::Show("Only integer values allowed.");
			e->Handled = true;
		}

	}
	private: System::Void value_table_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0)
		{
			// Retrieve the index of the selected row
			int rowIndex = e->RowIndex;

			// Remove the row from the DataGridView
			value_table->Rows->RemoveAt(rowIndex);

			x->RemoveAt(rowIndex);
			y->RemoveAt(rowIndex);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		linear_inter_points->Visible = FALSE;
		cubic_inter_points->Visible = FALSE;
		L_interp_label->Visible = FALSE;
		C_interp_label->Visible = FALSE;
		listBox1->Items->Clear();
		listBox1->Visible=FALSE;
		cubic_inter_points->Rows->Clear();
		linear_inter_points->Rows->Clear();
		chart->Series[0]->Points->Clear();
		chart->Series[1]->Points->Clear();
		Points p;
		p.Fill_Points(x, y);
		listBox1->Height = p.GetSize() * 20;
		p.Print_Points();
		if (p.GetSize() <= 1) {
			MessageBox::Show("You have entered only 1 point. You need minimum 2");
		}
		else if (num_of_interp_points->Text == "") {
			MessageBox::Show("You haven't entered the number of interpolated points!");
		}
		else{
			int num = Convert::ToInt32(num_of_interp_points->Text);
			if (ch_b_cubic->Checked && ch_b_linear->Checked) {
				LinearInterpolation inter(num);
				inter.linear(p, inter.GetNumOfP());
				std::cout << "\nCubic Spline Interpolation" << endl;
				CubicSplineInterpolation cubic(num);
				cubic.build_splines(p);
				cubic.interpolate(p); 
				show_cubic_points(cubic);
				show_linear_points(inter);
				listBox1->Visible = TRUE;
				print_splines(cubic, p);
				build_graphic(cubic, p);
				build_line_graphic(inter, p);
				
			}
			else if (ch_b_cubic->Checked) {
				CubicSplineInterpolation cubic(num);
				cubic.build_splines(p);
				cubic.interpolate(p);
				show_cubic_points(cubic);
				listBox1->Visible = TRUE;
				print_splines(cubic,p);
				build_graphic(cubic, p);
			}
			else if (ch_b_linear->Checked) {
				LinearInterpolation inter(num);
				inter.linear(p, inter.GetNumOfP());
				show_linear_points(inter);
				build_line_graphic(inter, p);
			}
			else {
				MessageBox::Show("You haven't chosen any method!");
			}
		}
		

	}
	void show_linear_points(LinearInterpolation inter) {
			  
		for (int i = 0; i < inter.GetNumOfP(); i++) {
			linear_inter_points->Rows->Add(inter.get_int_x_at(i),inter.get_int_y_at(i));
		}
		linear_inter_points->Visible = TRUE;
		L_interp_label->Visible = TRUE;
		}
	void show_cubic_points(CubicSplineInterpolation inter) {
		for (int i = 0; i < inter.GetNumOfP(); i++) {
			cubic_inter_points->Rows->Add(inter.get_int_x_at(i), inter.get_int_y_at(i));
		}
		cubic_inter_points->Visible = TRUE;
		C_interp_label->Visible = TRUE;
	}
	void print_splines(CubicSplineInterpolation inter,Points p) {
		listBox1->Items->Add("Cubic splines: ");
		int n = 10000;
		for (int i = 1; i < p.GetSize(); i++) {
			double d = round((inter.get_d_at(i)/6)*n)/n;
			double c = round((inter.get_c_at(i)/2)*n)/n;
			double b = round(inter.get_b_at(i)*n)/n;
			double a = round(inter.get_a_at(i)*n)/n;
			double x = p[i].GetX();
			listBox1->Items->Add("S"+i+"(x) = "+d+" *(x - "+ x+")^3 + "+c+" *(x - "+x+")^2 + "+b+" *(x - "+x+") + "+a);
		}
	}
	void build_graphic(CubicSplineInterpolation inter, Points p) {
		double yMin, yMax;
		find_Y_M (yMin, yMax, p);
		chart->ChartAreas[0]->AxisX->Minimum = p[0].GetX()-1;
		chart->ChartAreas[0]->AxisX->Maximum = p[p.GetSize()-1].GetX()+1;

		chart->ChartAreas[0]->AxisY->Minimum = yMin-1;
		chart->ChartAreas[0]->AxisY->Maximum = yMax+1;

		double a = p[0].GetX(), b = p[p.GetSize() - 1].GetX(), h = 0.1, x, y;
		chart->Series[0]->Points->Clear();
		x = a;
		int i = 1;
		while (x <= b) {
			if (x > p[i].GetX()) {
				i++;
			}
			double d = inter.get_d_at(i) / 6;
			double c = inter.get_c_at(i) / 2;
			double b = inter.get_b_at(i) ;
			double a = inter.get_a_at(i) ;
			double dx = x - p[i].GetX();
			y = a + b * dx + c * dx * dx + d * dx * dx * dx;

			chart->Series[0]->Points->AddXY(x, y);
			x += h;
		}
	}
	void build_line_graphic(LinearInterpolation inter, Points p) {
		double yMin, yMax;
		find_Y_M(yMin, yMax, p);
		chart->ChartAreas[0]->AxisX->Minimum = p[0].GetX()-1;
		chart->ChartAreas[0]->AxisX->Maximum = p[p.GetSize() - 1].GetX()+1;

		chart->ChartAreas[0]->AxisY->Minimum = yMin-1;
		chart->ChartAreas[0]->AxisY->Maximum = yMax+1;

		double a = p[0].GetX(), b = p[p.GetSize() - 1].GetX(), h = 0.1, x, y;
		chart->Series[1]->Points->Clear();
		x = a;
		int i = 0;
		while (x < b) {
			
			y = p[i].GetY() +
				((p[i + 1].GetY() - p[i].GetY()) / (p[i + 1].GetX() - p[i].GetX())) *
				(x - p[i].GetX());
			chart->Series[1]->Points->AddXY(x, y);
			x += h;
			if (x > p[i+1].GetX()) {
				i++;
			}
		}
	}
	
	
};
	
}


