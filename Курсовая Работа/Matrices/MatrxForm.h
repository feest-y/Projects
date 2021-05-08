#pragma once
#include "Matrices.h"

Matrix A;

namespace Matrices {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MatrxForm
	/// </summary>
	public ref class MatrxForm : public System::Windows::Forms::Form
	{
	public:
		MatrxForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MatrxForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItemAbout;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItemExit;


	private: System::Windows::Forms::DataGridView^ dataGridViewSource;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCols;
	private: System::Windows::Forms::Button^ Creation;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownRows;
	private: System::Windows::Forms::GroupBox^ groupBoxSourceMatrix;
	private: System::Windows::Forms::GroupBox^ groupBoxTransformed;
	private: System::Windows::Forms::DataGridView^ dataGridViewTransformed;

	private: System::Windows::Forms::GroupBox^ groupBox_Transformations;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ CalculateAlg;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ CalculatePar;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ SDiag;

	private: System::Windows::Forms::Label^ SPer;

	private: System::Windows::Forms::Label^ Aver;
	private: System::Windows::Forms::CheckBox^ radioButtonrand;
	private: System::Windows::Forms::NumericUpDown^ number;









	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MatrxForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->exitToolStripMenuItemAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItemExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridViewSource = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDownCols = (gcnew System::Windows::Forms::NumericUpDown());
			this->Creation = (gcnew System::Windows::Forms::Button());
			this->numericUpDownRows = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBoxSourceMatrix = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonrand = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBoxTransformed = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewTransformed = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_Transformations = (gcnew System::Windows::Forms::GroupBox());
			this->CalculateAlg = (gcnew System::Windows::Forms::Button());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->CalculatePar = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->SDiag = (gcnew System::Windows::Forms::Label());
			this->SPer = (gcnew System::Windows::Forms::Label());
			this->Aver = (gcnew System::Windows::Forms::Label());
			this->number = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSource))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCols))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRows))->BeginInit();
			this->groupBoxSourceMatrix->SuspendLayout();
			this->groupBoxTransformed->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransformed))->BeginInit();
			this->groupBox_Transformations->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->exitToolStripMenuItemAbout,
					this->exitToolStripMenuItemExit
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1428, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exitToolStripMenuItemAbout
			// 
			this->exitToolStripMenuItemAbout->Name = L"exitToolStripMenuItemAbout";
			this->exitToolStripMenuItemAbout->Size = System::Drawing::Size(52, 20);
			this->exitToolStripMenuItemAbout->Text = L"About";
			this->exitToolStripMenuItemAbout->Click += gcnew System::EventHandler(this, &MatrxForm::exitToolStripMenuItemAbout_Click);
			// 
			// exitToolStripMenuItemExit
			// 
			this->exitToolStripMenuItemExit->Name = L"exitToolStripMenuItemExit";
			this->exitToolStripMenuItemExit->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItemExit->Text = L"Exit";
			this->exitToolStripMenuItemExit->Click += gcnew System::EventHandler(this, &MatrxForm::exitToolStripMenuItemExit_Click);
			// 
			// dataGridViewSource
			// 
			this->dataGridViewSource->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSource->Location = System::Drawing::Point(11, 50);
			this->dataGridViewSource->Name = L"dataGridViewSource";
			this->dataGridViewSource->Size = System::Drawing::Size(367, 303);
			this->dataGridViewSource->TabIndex = 2;
			// 
			// numericUpDownCols
			// 
			this->numericUpDownCols->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownCols->Location = System::Drawing::Point(96, 359);
			this->numericUpDownCols->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDownCols->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownCols->Name = L"numericUpDownCols";
			this->numericUpDownCols->Size = System::Drawing::Size(69, 31);
			this->numericUpDownCols->TabIndex = 4;
			this->numericUpDownCols->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// Creation
			// 
			this->Creation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Creation->Location = System::Drawing::Point(269, 359);
			this->Creation->Name = L"Creation";
			this->Creation->Size = System::Drawing::Size(109, 36);
			this->Creation->TabIndex = 5;
			this->Creation->Text = L"Create";
			this->Creation->UseVisualStyleBackColor = true;
			this->Creation->Click += gcnew System::EventHandler(this, &MatrxForm::Creation_Click);
			// 
			// numericUpDownRows
			// 
			this->numericUpDownRows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownRows->Location = System::Drawing::Point(16, 359);
			this->numericUpDownRows->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numericUpDownRows->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownRows->Name = L"numericUpDownRows";
			this->numericUpDownRows->Size = System::Drawing::Size(69, 31);
			this->numericUpDownRows->TabIndex = 6;
			this->numericUpDownRows->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// groupBoxSourceMatrix
			// 
			this->groupBoxSourceMatrix->Controls->Add(this->radioButtonrand);
			this->groupBoxSourceMatrix->Controls->Add(this->label1);
			this->groupBoxSourceMatrix->Controls->Add(this->dataGridViewSource);
			this->groupBoxSourceMatrix->Controls->Add(this->numericUpDownRows);
			this->groupBoxSourceMatrix->Controls->Add(this->Creation);
			this->groupBoxSourceMatrix->Controls->Add(this->numericUpDownCols);
			this->groupBoxSourceMatrix->Location = System::Drawing::Point(33, 63);
			this->groupBoxSourceMatrix->Name = L"groupBoxSourceMatrix";
			this->groupBoxSourceMatrix->Size = System::Drawing::Size(389, 410);
			this->groupBoxSourceMatrix->TabIndex = 7;
			this->groupBoxSourceMatrix->TabStop = false;
			// 
			// radioButtonrand
			// 
			this->radioButtonrand->AutoSize = true;
			this->radioButtonrand->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->radioButtonrand->Checked = true;
			this->radioButtonrand->CheckState = System::Windows::Forms::CheckState::Checked;
			this->radioButtonrand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButtonrand->Location = System::Drawing::Point(171, 364);
			this->radioButtonrand->Name = L"radioButtonrand";
			this->radioButtonrand->Size = System::Drawing::Size(89, 24);
			this->radioButtonrand->TabIndex = 12;
			this->radioButtonrand->Text = L"Random";
			this->radioButtonrand->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(122, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 28);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Source Matrix";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBoxTransformed
			// 
			this->groupBoxTransformed->Controls->Add(this->label2);
			this->groupBoxTransformed->Controls->Add(this->dataGridViewTransformed);
			this->groupBoxTransformed->Location = System::Drawing::Point(620, 63);
			this->groupBoxTransformed->Name = L"groupBoxTransformed";
			this->groupBoxTransformed->Size = System::Drawing::Size(389, 410);
			this->groupBoxTransformed->TabIndex = 8;
			this->groupBoxTransformed->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(110, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(184, 28);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Transformed Matrix";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dataGridViewTransformed
			// 
			this->dataGridViewTransformed->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTransformed->Location = System::Drawing::Point(11, 50);
			this->dataGridViewTransformed->Name = L"dataGridViewTransformed";
			this->dataGridViewTransformed->Size = System::Drawing::Size(367, 303);
			this->dataGridViewTransformed->TabIndex = 2;
			// 
			// groupBox_Transformations
			// 
			this->groupBox_Transformations->Controls->Add(this->number);
			this->groupBox_Transformations->Controls->Add(this->CalculateAlg);
			this->groupBox_Transformations->Controls->Add(this->radioButton3);
			this->groupBox_Transformations->Controls->Add(this->radioButton2);
			this->groupBox_Transformations->Controls->Add(this->radioButton1);
			this->groupBox_Transformations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBox_Transformations->Location = System::Drawing::Point(428, 63);
			this->groupBox_Transformations->Name = L"groupBox_Transformations";
			this->groupBox_Transformations->Size = System::Drawing::Size(186, 410);
			this->groupBox_Transformations->TabIndex = 9;
			this->groupBox_Transformations->TabStop = false;
			this->groupBox_Transformations->Text = L"     Algorithms";
			// 
			// CalculateAlg
			// 
			this->CalculateAlg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateAlg->Location = System::Drawing::Point(34, 359);
			this->CalculateAlg->Name = L"CalculateAlg";
			this->CalculateAlg->Size = System::Drawing::Size(114, 36);
			this->CalculateAlg->TabIndex = 7;
			this->CalculateAlg->Text = L"Calculate";
			this->CalculateAlg->UseVisualStyleBackColor = true;
			this->CalculateAlg->Click += gcnew System::EventHandler(this, &MatrxForm::CalculateAlg_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(18, 244);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(62, 29);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"X 2";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(18, 189);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(65, 29);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Flip";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(18, 134);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(170, 29);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"EvenToInteger";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->CalculatePar);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(1018, 63);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(186, 410);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"      Parametrs";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(18, 244);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(176, 29);
			this->checkBox3->TabIndex = 10;
			this->checkBox3->Text = L"SumOnDiag >>";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(18, 189);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(177, 29);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"Perimeter     >>";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(18, 134);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(177, 29);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Average       >>";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// CalculatePar
			// 
			this->CalculatePar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculatePar->Location = System::Drawing::Point(34, 359);
			this->CalculatePar->Name = L"CalculatePar";
			this->CalculatePar->Size = System::Drawing::Size(114, 36);
			this->CalculatePar->TabIndex = 7;
			this->CalculatePar->Text = L"Calculate";
			this->CalculatePar->UseVisualStyleBackColor = true;
			this->CalculatePar->Click += gcnew System::EventHandler(this, &MatrxForm::CalculatePar_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->SDiag);
			this->groupBox2->Controls->Add(this->SPer);
			this->groupBox2->Controls->Add(this->Aver);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(1210, 63);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(186, 410);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"        Results";
			// 
			// SDiag
			// 
			this->SDiag->AutoSize = true;
			this->SDiag->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SDiag->Location = System::Drawing::Point(6, 243);
			this->SDiag->Name = L"SDiag";
			this->SDiag->Size = System::Drawing::Size(0, 28);
			this->SDiag->TabIndex = 15;
			this->SDiag->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPer
			// 
			this->SPer->AutoSize = true;
			this->SPer->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SPer->Location = System::Drawing::Point(6, 188);
			this->SPer->Name = L"SPer";
			this->SPer->Size = System::Drawing::Size(0, 28);
			this->SPer->TabIndex = 14;
			this->SPer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Aver
			// 
			this->Aver->AutoSize = true;
			this->Aver->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Aver->Location = System::Drawing::Point(6, 133);
			this->Aver->Name = L"Aver";
			this->Aver->Size = System::Drawing::Size(0, 28);
			this->Aver->TabIndex = 13;
			this->Aver->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// number
			// 
			this->number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->number->Location = System::Drawing::Point(124, 169);
			this->number->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000000, 0, 0, 0 });
			this->number->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000000, 0, 0, System::Int32::MinValue });
			this->number->Name = L"number";
			this->number->Size = System::Drawing::Size(56, 24);
			this->number->TabIndex = 13;
			this->number->ThousandsSeparator = true;
			this->number->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 666, 0, 0, System::Int32::MinValue });
			// 
			// MatrxForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1428, 646);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox_Transformations);
			this->Controls->Add(this->groupBoxTransformed);
			this->Controls->Add(this->groupBoxSourceMatrix);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MatrxForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Matrices";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSource))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCols))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRows))->EndInit();
			this->groupBoxSourceMatrix->ResumeLayout(false);
			this->groupBoxSourceMatrix->PerformLayout();
			this->groupBoxTransformed->ResumeLayout(false);
			this->groupBoxTransformed->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransformed))->EndInit();
			this->groupBox_Transformations->ResumeLayout(false);
			this->groupBox_Transformations->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void exitToolStripMenuItemAbout_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Выполнил студент группы КН-320В\n\tСолтус Андрей", "");
	}
	private: System::Void exitToolStripMenuItemExit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void Creation_Click(System::Object^ sender, System::EventArgs^ e) {
		A.ChangeSize(Convert::ToInt32(numericUpDownRows->Value), Convert::ToInt32(numericUpDownCols->Value));
		if (radioButtonrand->Checked)
			A.Fill(true);

		//заполнение таблицы
		ToGrid(true);
	}

	private: System::Void CalculateAlg_Click(System::Object^ sender, System::EventArgs^ e) {
		Sync();
		if (radioButton1->Checked)
		{
			A.EvenToInteger(Convert::ToInt32(number->Value));
		}
		else if (radioButton2->Checked)
		{
			if (numericUpDownRows->Value == numericUpDownCols->Value)
			{
				A.Flip();
			}
			else {
				MessageBox::Show("Матрица не квадратная !", "Error !");
				return;
			}
		}
		else if (radioButton3->Checked)
		{
			A.x2();
		}
		else return;

		ToGrid(false);

	}
	private: System::Void ToGrid(bool isSource) {
		if (isSource)
		{
			dataGridViewSource->RowCount = A.rowsP;
			dataGridViewSource->ColumnCount = A.colsP;

			for (short i = 0; i < A.rowsP; i++)
			{
				for (short j = 0; j < A.colsP; j++)
				{
					dataGridViewSource->TopLeftHeaderCell->Value = "Source";
					dataGridViewSource->Columns[j]->HeaderCell->Value = Convert::ToString(j);
					dataGridViewSource->Rows[i]->HeaderCell->Value = Convert::ToString(i);
					dataGridViewSource->Rows[i]->Cells[j]->Value = A.Parent[i][j];
				}
			}
			dataGridViewSource->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			dataGridViewSource->AutoResizeColumns();
		}
		else {
			if (A.rowsP == 0 || A.colsP == 0 || A.Parent == nullptr)
			{
				MessageBox::Show("Матрица пустая !", "Error !");
				return;
			}
			dataGridViewTransformed->RowCount = A.rowsT;
			dataGridViewTransformed->ColumnCount = A.colsT;

			for (short i = 0; i < A.rowsT; i++)
			{
				for (short j = 0; j < A.colsT; j++)
				{
					dataGridViewTransformed->TopLeftHeaderCell->Value = "Transformed";
					dataGridViewTransformed->Columns[j]->HeaderCell->Value = Convert::ToString(j);
					dataGridViewTransformed->Rows[i]->HeaderCell->Value = Convert::ToString(i);
					dataGridViewTransformed->Rows[i]->Cells[j]->Value = A.Transformed[i][j];

				}
			}
			dataGridViewTransformed->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			dataGridViewTransformed->AutoResizeColumns();
		}
	}

	private: System::Void Sync() {

		//Source
		for (int i = 0; i < A.rowsP; i++)
		{
			for (int j = 0; j < A.colsP; j++)
			{
				A.Parent[i][j] = Convert::ToInt32(dataGridViewSource->Rows[i]->Cells[j]->Value);
			}
		}
		//Transformed

		for (int i = 0; i < A.rowsT; i++)
		{
			for (int j = 0; j < A.colsT; j++)
			{
				A.Transformed[i][j] = Convert::ToInt32(dataGridViewTransformed->Rows[i]->Cells[j]->Value);
			}
		}
	}

	private: System::Void CalculatePar_Click(System::Object^ sender, System::EventArgs^ e) {//Calculate 2
		if (A.rowsT == 0 || A.colsT == 0 || A.Transformed == nullptr)
		{
			MessageBox::Show("Матрица пустая !", "Error !");
			return;
		}

		Sync();
		Aver->Text = Convert::ToString("");
		SPer->Text = Convert::ToString("");
		SDiag->Text = Convert::ToString("");
		A.avg = A.sumP = A.sumD = 0;

		if (checkBox1->Checked) {
			A.CountAverage();
			Aver->Text = Convert::ToString(A.avg);
		}
		if (checkBox2->Checked) {
			A.CountSumP();
			SPer->Text = Convert::ToString(A.sumP);
		}
		if (checkBox3->Checked) {
			A.CountSumD();
			SDiag->Text = Convert::ToString(A.sumD);
		}
	}
	};

}