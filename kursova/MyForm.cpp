#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;
using namespace System::Threading;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	kursova::MyForm form;
	setlocale(LC_ALL, "uk-UA");;
	//Thread.CurrentThread.CurrentCulture = new CultureInfo("uk-UA");
	//Thread->CurrentThread.CurrentUICulture = new CultureInfo("UA");
	Application::Run(% form);
}

System::Void kursova::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ x1 = x_input->Text;
		String^ y1 = y_input->Text;

		string x_inp = marshal_as<string>(x1);
		string y_inp = marshal_as<string>(y1);
		double xx, yy;
		xx = Convert::ToDouble(x1);
		yy = Convert::ToDouble(y1);
		if (x_inp == "" || y_inp == "") {
			MessageBox::Show("Please input coordinates!");
		}
		else if (p->GetSize() > 20) {
			MessageBox::Show("Maximum 20 points!");
		}
		else if (xx > 1000 || xx < -1000) {
			MessageBox::Show("Maximum x value is 1000 and minimum is -1000!");
		}
		else if (yy > 1000 || yy < -1000) {
			MessageBox::Show("Maximum y value is 1000 and minimum is -1000!");
		}
		else {
			p->check_if_present(xx);
			if (p->check_if_present(xx) == false) {
				x_input->Text = "";
				y_input->Text = "";
				p->AddPoint(xx, yy);
				value_table->Rows->Add(x1, y1);
			}
			else {
				MessageBox::Show("You can't have two points with the same x coordinate!");
			}

		}

		dotEnteredx = false;
		dotEnteredy = false;
		minusEnteredx = false;
		minusEnteredy = false;
	}

System::Void kursova::MyForm::x_input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
			MessageBox::Show("Please enter only numbers.");
			e->Handled = true;
		}
		else if (e->KeyChar == ',' && dotEnteredx || e->KeyChar == '-' && minusEnteredx) {
			if (e->KeyChar == ',') {
				MessageBox::Show("You have already entered a decimal point.");
			}
			if (e->KeyChar == '-') {
				MessageBox::Show("You have already entered  minus.");
			}
			e->Handled = true;
		}
		else {
			if (e->KeyChar == ',') {
				dotEnteredx = (e->KeyChar == ',') ? true : dotEnteredx;
			}
			if (e->KeyChar == '-') {
				minusEnteredx = (e->KeyChar == '-') ? true : minusEnteredx;
			}


		}

	}
System::Void kursova::MyForm::y_input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
			MessageBox::Show("Please enter only numbers.");
			e->Handled = true;
		}
		else if (e->KeyChar == ',' && dotEnteredy || e->KeyChar == '-' && minusEnteredy) {
			if (e->KeyChar == ',') {
				MessageBox::Show("You have already entered a decimal point.");
			}
			if (e->KeyChar == '-') {
				MessageBox::Show("You have already entered  minus.");
			}
			e->Handled = true;
		}
		else {
			if (e->KeyChar == ',') {
				dotEnteredy = (e->KeyChar == ',') ? true : dotEnteredy;
			}
			if (e->KeyChar == '-') {
				minusEnteredy = (e->KeyChar == '-') ? true : minusEnteredy;
			}


		}
	}

System::Void kursova::MyForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
			MessageBox::Show("Only integer values allowed.");
			e->Handled = true;
		}

	}
System::Void kursova::MyForm::value_table_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0)
		{
			int rowIndex = e->RowIndex;
			value_table->Rows->RemoveAt(rowIndex);

			p->RemovePoint(rowIndex);

		}
	}
System::Void kursova::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		linear_inter_points->Visible = FALSE;
		cubic_inter_points->Visible = FALSE;
		L_interp_label->Visible = FALSE;
		C_interp_label->Visible = FALSE;
		cubic_splines->Items->Clear();
		cubic_splines->Visible = FALSE;
		cubic_inter_points->Rows->Clear();
		linear_inter_points->Rows->Clear();
		chart->Series[0]->Points->Clear();
		chart->Series[1]->Points->Clear();

		p->Print_Points();
		cubic_splines->Height = p->GetSize() * 20;


		if (p->GetSize() <= 1) {
			MessageBox::Show("You have entered only 1 point. You need minimum 2");
		}
		else if (num_of_interp_points->Text == "") {
			MessageBox::Show("You haven't entered the number of interpolated points!");
		}
		else {
			int num = Convert::ToInt32(num_of_interp_points->Text);
			if (ch_b_cubic->Checked && ch_b_linear->Checked) {
				inter->SetNum(num);
				inter->linear(p);
				//std::cout << "\nCubic Spline Interpolation" << endl;
				cubic->SetNum(num);
				cubic->build_splines(p);
				cubic->interpolate(p);
				show_cubic_points(cubic);
				show_linear_points(inter);
				cubic_splines->Visible = TRUE;
				print_splines(cubic);
				build_graphic(cubic);
				build_line_graphic(inter);

			}
			else if (ch_b_cubic->Checked) {
				cubic->SetNum(num);
				cubic->build_splines(p);
				cubic->interpolate(p);
				show_cubic_points(cubic);
				cubic_splines->Visible = TRUE;
				print_splines(cubic);
				build_graphic(cubic);
			}
			else if (ch_b_linear->Checked) {
				inter->SetNum(num);
				inter->linear(p);
				show_linear_points(inter);
				build_line_graphic(inter);
			}
			else {
				MessageBox::Show("You haven't chosen any method!");
			}
		}
		value_table->Rows->Clear();
		for (int i = 0; i < p->GetSize(); i++) {
			value_table->Rows->Add(p->GetX(i), p->GetY(i));
		}



	}
void kursova::MyForm::show_linear_points(LinearInterpolation* inter) {

			   for (int i = 0; i < inter->GetNumOfP(); i++) {
				   linear_inter_points->Rows->Add(inter->get_int_x_at(i), inter->get_int_y_at(i));
			   }
			   linear_inter_points->Visible = TRUE;
			   L_interp_label->Visible = TRUE;
		   }
void kursova::MyForm::show_cubic_points(CubicSplineInterpolation* inter) {
			   for (int i = 0; i < inter->GetNumOfP(); i++) {
				   cubic_inter_points->Rows->Add(inter->get_int_x_at(i), inter->get_int_y_at(i));
			   }
			   cubic_inter_points->Visible = TRUE;
			   C_interp_label->Visible = TRUE;
		   }
void kursova::MyForm::print_splines(CubicSplineInterpolation* inter) {
			   cubic_splines->Items->Add("Cubic splines: ");
			   int n = 10000;
			   for (int i = 1; i < p->GetSize(); i++) {
				   double d = round((inter->get_d_at(i) / 6) * n) / n;
				   double c = round((inter->get_c_at(i) / 2) * n) / n;
				   double b = round(inter->get_b_at(i) * n) / n;
				   double a = round(inter->get_a_at(i) * n) / n;
				   double x = p->GetX(i);
				   cubic_splines->Items->Add("S" + i + "(x) = " + d + " *(x - " + x + ")^3 + " + c + " *(x - " + x + ")^2 + " + b + " *(x - " + x + ") + " + a);
			   }
		   }
void kursova::MyForm::build_graphic(CubicSplineInterpolation* inter) {
			   double yMin, yMax;
			   find_Y_M(yMin, yMax, p);
			   chart->ChartAreas[0]->AxisX->Minimum = p->GetX(0) - 1;
			   chart->ChartAreas[0]->AxisX->Maximum = p->GetX(p->GetSize() - 1) + 1;

			   chart->ChartAreas[0]->AxisY->Minimum = yMin - 1;
			   chart->ChartAreas[0]->AxisY->Maximum = yMax + 1;

			   double a = p->GetX(0), b = p->GetX(p->GetSize() - 1), h = 0.1, x, y;
			   chart->Series[0]->Points->Clear();
			   x = a;
			   int i = 1;
			   while (x <= b) {
				   if (x > p->GetX(i)) {
					   i++;
				   }
				   double d = inter->get_d_at(i) / 6;
				   double c = inter->get_c_at(i) / 2;
				   double b = inter->get_b_at(i);
				   double a = inter->get_a_at(i);
				   double dx = x - p->GetX(i);
				   y = a + b * dx + c * dx * dx + d * dx * dx * dx;

				   chart->Series[0]->Points->AddXY(x, y);
				   x += h;
			   }
		   }
void kursova::MyForm::build_line_graphic(LinearInterpolation* inter) {
			   double yMin, yMax;
			   find_Y_M(yMin, yMax, p);
			   chart->ChartAreas[0]->AxisX->Minimum = p->GetX(0) - 1;
			   chart->ChartAreas[0]->AxisX->Maximum = p->GetX(p->GetSize() - 1) + 1;

			   chart->ChartAreas[0]->AxisY->Minimum = yMin - 1;
			   chart->ChartAreas[0]->AxisY->Maximum = yMax + 1;

			   double a = p->GetX(0), b = p->GetX(p->GetSize() - 1), h = 0.1, x, y;
			   chart->Series[1]->Points->Clear();
			   x = a;
			   int i = 0;
			   while (x < b) {

				   y = p->GetY(i) +
					   ((p->GetY(i + 1) - p->GetY(i)) / (p->GetX(i + 1) - p->GetX(i))) *
					   (x - p->GetX(i));
				   chart->Series[1]->Points->AddXY(x, y);
				   x += h;
				   if (x > p->GetX(i + 1)) {
					   i++;
				   }
			   }
		   }

System::Void kursova::MyForm::Clear_all_button_Click(System::Object^ sender, System::EventArgs^ e) {
	chart->Series[0]->Points->Clear();
	chart->Series[1]->Points->Clear();
	cubic_splines->Items->Clear();
	cubic_splines->Visible = FALSE;

	num_of_interp_points->Text = "";
	p->Clear_Points();
	p->Print_Points();

	cubic_inter_points->Rows->Clear();
	linear_inter_points->Rows->Clear();
	cubic_inter_points->Visible = FALSE;
	C_interp_label->Visible = FALSE;
	linear_inter_points->Visible = FALSE;
	L_interp_label->Visible = FALSE;
	ch_b_cubic->Checked = FALSE;
	ch_b_linear->Checked = FALSE;
	value_table->Rows->Clear();
	Points* newp = new Points();
	delete p;
	p = newp;



}

System::Void kursova::MyForm::SaveToFile_Click(System::Object^ sender, System::EventArgs^ e) {
	if (cubic_inter_points->Rows->Count == 0 && linear_inter_points->Rows->Count == 0) {
		MessageBox::Show("You can`t save results without interpolating!");
	}
	else {
		if (file_name->Visible == FALSE) {
			file_name->Visible = TRUE;
			input_name->Visible = TRUE;
		}
		else {
			if (ch_b_cubic->Checked && ch_b_linear->Checked) {
				inter->write_to_file(p, marshal_as<string>(file_name->Text));
				cubic->write_to_file(p, marshal_as<string>(file_name->Text));

			}
			else if (ch_b_cubic->Checked) {
				cubic->write_to_file(p, marshal_as<string>(file_name->Text));
			}
			else if (ch_b_linear->Checked) {
				inter->write_to_file(p, marshal_as<string>(file_name->Text));

			}
		}
	}
}