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
	private: System::Windows::Forms::Label^ Header;



	private: System::Windows::Forms::TextBox^ x_input;
	private: System::Windows::Forms::CheckBox^ ch_b_linear;
	private: System::Windows::Forms::CheckBox^ ch_b_cubic;
	private: System::Windows::Forms::Label^ Choosemethod_l;






	private: System::Windows::Forms::Label^ AddPoints_l;
	private: System::Windows::Forms::Label^ x_l;
	private: System::Windows::Forms::Label^ y_l;



	private: System::Windows::Forms::TextBox^ y_input;


	private: System::Windows::Forms::Label^ warning;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::Label^ Num_of_p_l;


	private: System::Windows::Forms::TextBox^ num_of_interp_points;
	private: System::Windows::Forms::Button^ Interpolate;


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
	private: System::Windows::Forms::ListBox^ cubic_splines;
	private: System::Windows::Forms::Button^ Clear_all_button;
	private: System::Windows::Forms::Button^ SaveToFile;
	private: System::Windows::Forms::TextBox^ file_name;
	private: System::Windows::Forms::Label^ input_name;










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
			this->Header = (gcnew System::Windows::Forms::Label());
			this->x_input = (gcnew System::Windows::Forms::TextBox());
			this->ch_b_linear = (gcnew System::Windows::Forms::CheckBox());
			this->ch_b_cubic = (gcnew System::Windows::Forms::CheckBox());
			this->Choosemethod_l = (gcnew System::Windows::Forms::Label());
			this->AddPoints_l = (gcnew System::Windows::Forms::Label());
			this->x_l = (gcnew System::Windows::Forms::Label());
			this->y_l = (gcnew System::Windows::Forms::Label());
			this->y_input = (gcnew System::Windows::Forms::TextBox());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->Num_of_p_l = (gcnew System::Windows::Forms::Label());
			this->num_of_interp_points = (gcnew System::Windows::Forms::TextBox());
			this->Interpolate = (gcnew System::Windows::Forms::Button());
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
			this->cubic_splines = (gcnew System::Windows::Forms::ListBox());
			this->Clear_all_button = (gcnew System::Windows::Forms::Button());
			this->SaveToFile = (gcnew System::Windows::Forms::Button());
			this->file_name = (gcnew System::Windows::Forms::TextBox());
			this->input_name = (gcnew System::Windows::Forms::Label());
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
			this->Addbutton->ForeColor = System::Drawing::Color::Navy;
			this->Addbutton->Location = System::Drawing::Point(385, 266);
			this->Addbutton->Name = L"Addbutton";
			this->Addbutton->Size = System::Drawing::Size(146, 40);
			this->Addbutton->TabIndex = 0;
			this->Addbutton->Text = L"Додати точку";
			this->Addbutton->UseVisualStyleBackColor = true;
			this->Addbutton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Header
			// 
			this->Header->AutoSize = true;
			this->Header->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Header->ForeColor = System::Drawing::Color::Navy;
			this->Header->Location = System::Drawing::Point(349, 9);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(473, 44);
			this->Header->TabIndex = 1;
			this->Header->Text = L"Розв\'язання задач інтерполяції";
			this->Header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// x_input
			// 
			this->x_input->Location = System::Drawing::Point(72, 273);
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
			// Choosemethod_l
			// 
			this->Choosemethod_l->AutoSize = true;
			this->Choosemethod_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Choosemethod_l->ForeColor = System::Drawing::Color::Navy;
			this->Choosemethod_l->Location = System::Drawing::Point(27, 91);
			this->Choosemethod_l->Name = L"Choosemethod_l";
			this->Choosemethod_l->Size = System::Drawing::Size(308, 25);
			this->Choosemethod_l->TabIndex = 7;
			this->Choosemethod_l->Text = L"Оберіть метод інтерполяції:";
			// 
			// AddPoints_l
			// 
			this->AddPoints_l->AutoSize = true;
			this->AddPoints_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddPoints_l->ForeColor = System::Drawing::Color::Navy;
			this->AddPoints_l->Location = System::Drawing::Point(38, 225);
			this->AddPoints_l->Name = L"AddPoints_l";
			this->AddPoints_l->Size = System::Drawing::Size(289, 25);
			this->AddPoints_l->TabIndex = 8;
			this->AddPoints_l->Text = L"Введіть координати точки:";
			// 
			// x_l
			// 
			this->x_l->AutoSize = true;
			this->x_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x_l->Location = System::Drawing::Point(29, 273);
			this->x_l->Name = L"x_l";
			this->x_l->Size = System::Drawing::Size(31, 26);
			this->x_l->TabIndex = 9;
			this->x_l->Text = L"x:";
			// 
			// y_l
			// 
			this->y_l->AutoSize = true;
			this->y_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->y_l->Location = System::Drawing::Point(205, 273);
			this->y_l->Name = L"y_l";
			this->y_l->Size = System::Drawing::Size(30, 25);
			this->y_l->TabIndex = 10;
			this->y_l->Text = L"y:";
			// 
			// y_input
			// 
			this->y_input->Location = System::Drawing::Point(250, 271);
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
			this->chart->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->chart->Name = L"chart";
			this->chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->Legend = L"Legend1";
			series1->MarkerSize = 8;
			series1->Name = L"Інтерполяція кубічними сплайнами";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->MarkerSize = 8;
			series2->Name = L"Series2";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(510, 307);
			this->chart->TabIndex = 10;
			this->chart->Text = L"chart1";
			// 
			// Num_of_p_l
			// 
			this->Num_of_p_l->AutoSize = true;
			this->Num_of_p_l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Num_of_p_l->ForeColor = System::Drawing::Color::Navy;
			this->Num_of_p_l->Location = System::Drawing::Point(20, 564);
			this->Num_of_p_l->Name = L"Num_of_p_l";
			this->Num_of_p_l->Size = System::Drawing::Size(200, 40);
			this->Num_of_p_l->TabIndex = 15;
			this->Num_of_p_l->Text = L"Кількість\r\nінтерполяційних точок";
			// 
			// num_of_interp_points
			// 
			this->num_of_interp_points->Location = System::Drawing::Point(231, 577);
			this->num_of_interp_points->Name = L"num_of_interp_points";
			this->num_of_interp_points->Size = System::Drawing::Size(100, 26);
			this->num_of_interp_points->TabIndex = 16;
			this->num_of_interp_points->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// Interpolate
			// 
			this->Interpolate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Interpolate->ForeColor = System::Drawing::Color::Navy;
			this->Interpolate->Location = System::Drawing::Point(358, 564);
			this->Interpolate->Name = L"Interpolate";
			this->Interpolate->Size = System::Drawing::Size(158, 40);
			this->Interpolate->TabIndex = 17;
			this->Interpolate->Text = L"Інтерполювати";
			this->Interpolate->UseVisualStyleBackColor = true;
			this->Interpolate->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// value_table
			// 
			this->value_table->AllowUserToAddRows = false;
			this->value_table->AllowUserToDeleteRows = false;
			this->value_table->AllowUserToResizeColumns = false;
			this->value_table->AllowUserToResizeRows = false;
			this->value_table->BackgroundColor = System::Drawing::Color::LightCyan;
			this->value_table->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->value_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->value_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->value_table->Location = System::Drawing::Point(56, 327);
			this->value_table->Name = L"value_table";
			this->value_table->ReadOnly = true;
			this->value_table->RowHeadersWidth = 10;
			this->value_table->RowTemplate->Height = 28;
			this->value_table->Size = System::Drawing::Size(196, 205);
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
			this->linear_inter_points->BackgroundColor = System::Drawing::Color::LightCyan;
			this->linear_inter_points->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->linear_inter_points->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->linear_inter_points->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->xp,
					this->yp
			});
			this->linear_inter_points->Location = System::Drawing::Point(628, 461);
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
			this->cubic_inter_points->BackgroundColor = System::Drawing::Color::LightCyan;
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
			this->L_interp_label->ForeColor = System::Drawing::Color::Navy;
			this->L_interp_label->Location = System::Drawing::Point(601, 424);
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
			this->C_interp_label->ForeColor = System::Drawing::Color::Navy;
			this->C_interp_label->Location = System::Drawing::Point(880, 413);
			this->C_interp_label->Name = L"C_interp_label";
			this->C_interp_label->Size = System::Drawing::Size(235, 44);
			this->C_interp_label->TabIndex = 22;
			this->C_interp_label->Text = L"Інтерполяція кубічними \r\nсплайнами";
			this->C_interp_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C_interp_label->Visible = false;
			// 
			// cubic_splines
			// 
			this->cubic_splines->BackColor = System::Drawing::Color::SkyBlue;
			this->cubic_splines->FormattingEnabled = true;
			this->cubic_splines->ItemHeight = 20;
			this->cubic_splines->Location = System::Drawing::Point(33, 619);
			this->cubic_splines->Name = L"cubic_splines";
			this->cubic_splines->Size = System::Drawing::Size(542, 164);
			this->cubic_splines->TabIndex = 23;
			this->cubic_splines->Visible = false;
			// 
			// Clear_all_button
			// 
			this->Clear_all_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clear_all_button->ForeColor = System::Drawing::Color::Navy;
			this->Clear_all_button->Location = System::Drawing::Point(628, 753);
			this->Clear_all_button->Name = L"Clear_all_button";
			this->Clear_all_button->Size = System::Drawing::Size(120, 55);
			this->Clear_all_button->TabIndex = 24;
			this->Clear_all_button->Text = L"Очистити всі поля";
			this->Clear_all_button->UseVisualStyleBackColor = true;
			this->Clear_all_button->Click += gcnew System::EventHandler(this, &MyForm::Clear_all_button_Click);
			// 
			// SaveToFile
			// 
			this->SaveToFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SaveToFile->ForeColor = System::Drawing::Color::Navy;
			this->SaveToFile->Location = System::Drawing::Point(771, 753);
			this->SaveToFile->Name = L"SaveToFile";
			this->SaveToFile->Size = System::Drawing::Size(122, 55);
			this->SaveToFile->TabIndex = 25;
			this->SaveToFile->Text = L"Зберегти результати ";
			this->SaveToFile->UseVisualStyleBackColor = true;
			this->SaveToFile->Click += gcnew System::EventHandler(this, &MyForm::SaveToFile_Click);
			// 
			// file_name
			// 
			this->file_name->Location = System::Drawing::Point(913, 794);
			this->file_name->Name = L"file_name";
			this->file_name->Size = System::Drawing::Size(171, 26);
			this->file_name->TabIndex = 26;
			// 
			// input_name
			// 
			this->input_name->AutoSize = true;
			this->input_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_name->ForeColor = System::Drawing::Color::Navy;
			this->input_name->Location = System::Drawing::Point(914, 753);
			this->input_name->Name = L"input_name";
			this->input_name->Size = System::Drawing::Size(204, 22);
			this->input_name->TabIndex = 27;
			this->input_name->Text = L"Введіть назву файлу";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->ClientSize = System::Drawing::Size(1177, 807);
			this->Controls->Add(this->input_name);
			this->Controls->Add(this->file_name);
			this->Controls->Add(this->SaveToFile);
			this->Controls->Add(this->Clear_all_button);
			this->Controls->Add(this->cubic_splines);
			this->Controls->Add(this->C_interp_label);
			this->Controls->Add(this->L_interp_label);
			this->Controls->Add(this->cubic_inter_points);
			this->Controls->Add(this->linear_inter_points);
			this->Controls->Add(this->value_table);
			this->Controls->Add(this->Interpolate);
			this->Controls->Add(this->num_of_interp_points);
			this->Controls->Add(this->Num_of_p_l);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->y_input);
			this->Controls->Add(this->y_l);
			this->Controls->Add(this->x_l);
			this->Controls->Add(this->AddPoints_l);
			this->Controls->Add(this->Choosemethod_l);
			this->Controls->Add(this->ch_b_cubic);
			this->Controls->Add(this->ch_b_linear);
			this->Controls->Add(this->x_input);
			this->Controls->Add(this->Header);
			this->Controls->Add(this->Addbutton);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Задачі інтерполяції";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->value_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->linear_inter_points))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cubic_inter_points))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
	
		Points *p = new Points();
		CubicSplineInterpolation* cubic =new CubicSplineInterpolation();
		LinearInterpolation* inter = new LinearInterpolation();
		bool dotEnteredx = false;
		bool dotEnteredy = false;
		bool minusEnteredx = false;
		bool minusEnteredy = false;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void x_input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void y_input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);


	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void value_table_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		   void show_linear_points(LinearInterpolation* inter);
		   void show_cubic_points(CubicSplineInterpolation* inter);
		   void print_splines(CubicSplineInterpolation* inter);
		   void build_graphic(CubicSplineInterpolation* inter);
		   void build_line_graphic(LinearInterpolation* inter);
		   void print_linear(LinearInterpolation* inter);
	
private: System::Void Clear_all_button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SaveToFile_Click(System::Object^ sender, System::EventArgs^ e);

};
	
}


