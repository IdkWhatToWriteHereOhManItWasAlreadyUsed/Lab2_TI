#pragma once
#include "Key.h"
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include "Encryptor.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "Encryptor.h"
#include <windows.h>

namespace $safeprojectname$ 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				// 
				//
				encpyptor = new Encryptor();
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
		private: System::Windows::Forms::TextBox^ RegisterTextBox;
		protected:

		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ RegisterLengthLabel;
		private: System::Windows::Forms::Button^ EncryptButton;
		private: System::Windows::Forms::TextBox^ PlainTextBox;

		private: System::Windows::Forms::MenuStrip^ menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ îòêğûòüToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ ñîõğàíèòüToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ îĞàçğàáîò÷èêåToolStripMenuItem;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ KeyTextBox;
		private: System::Windows::Forms::TextBox^ CipheredTextBox;



		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
		private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

		protected:
		private: System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			void InitializeComponent(void)
			{
				this->RegisterTextBox = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->RegisterLengthLabel = (gcnew System::Windows::Forms::Label());
				this->EncryptButton = (gcnew System::Windows::Forms::Button());
				this->PlainTextBox = (gcnew System::Windows::Forms::TextBox());
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->ñîõğàíèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->îĞàçğàáîò÷èêåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->KeyTextBox = (gcnew System::Windows::Forms::TextBox());
				this->CipheredTextBox = (gcnew System::Windows::Forms::TextBox());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
				this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->menuStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// RegisterTextBox
				// 
				this->RegisterTextBox->Location = System::Drawing::Point(16, 50);
				this->RegisterTextBox->MaxLength = 38;
				this->RegisterTextBox->Name = L"RegisterTextBox";
				this->RegisterTextBox->Size = System::Drawing::Size(281, 20);
				this->RegisterTextBox->TabIndex = 0;
				this->RegisterTextBox->TabStop = false;
				this->RegisterTextBox->Text = L"111111111111111111111111111111";
				this->RegisterTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::KeyTextBox_TextChanged);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label1->Location = System::Drawing::Point(323, 48);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(150, 20);
				this->label1->TabIndex = 1;
				this->label1->Text = L"Äëèíà ğåãèñòğà:";
				// 
				// RegisterLengthLabel
				// 
				this->RegisterLengthLabel->AutoSize = true;
				this->RegisterLengthLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->RegisterLengthLabel->Location = System::Drawing::Point(479, 49);
				this->RegisterLengthLabel->Name = L"RegisterLengthLabel";
				this->RegisterLengthLabel->Size = System::Drawing::Size(29, 20);
				this->RegisterLengthLabel->TabIndex = 2;
				this->RegisterLengthLabel->Text = L"30";
				// 
				// EncryptButton
				// 
				this->EncryptButton->BackColor = System::Drawing::Color::OrangeRed;
				this->EncryptButton->Enabled = false;
				this->EncryptButton->ForeColor = System::Drawing::SystemColors::HighlightText;
				this->EncryptButton->Location = System::Drawing::Point(584, 46);
				this->EncryptButton->Name = L"EncryptButton";
				this->EncryptButton->Size = System::Drawing::Size(146, 29);
				this->EncryptButton->TabIndex = 3;
				this->EncryptButton->Text = L"Çàøèôğîâàòü";
				this->EncryptButton->UseVisualStyleBackColor = false;
				this->EncryptButton->Click += gcnew System::EventHandler(this, &MyForm::EncryptButton_Click);
				// 
				// PlainTextBox
				// 
				this->PlainTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->PlainTextBox->Location = System::Drawing::Point(12, 111);
				this->PlainTextBox->Multiline = true;
				this->PlainTextBox->Name = L"PlainTextBox";
				this->PlainTextBox->ReadOnly = true;
				this->PlainTextBox->Size = System::Drawing::Size(372, 466);
				this->PlainTextBox->TabIndex = 4;
				// 
				// menuStrip1
				// 
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->ôàéëToolStripMenuItem,
						this->îĞàçğàáîò÷èêåToolStripMenuItem
				});
				this->menuStrip1->Location = System::Drawing::Point(0, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->Size = System::Drawing::Size(1212, 24);
				this->menuStrip1->TabIndex = 5;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// ôàéëToolStripMenuItem
				// 
				this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->îòêğûòüToolStripMenuItem,
						this->ñîõğàíèòüToolStripMenuItem
				});
				this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
				this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
				this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
				// 
				// îòêğûòüToolStripMenuItem
				// 
				this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
				this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(133, 22);
				this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
				this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòêğûòüToolStripMenuItem_Click);
				// 
				// ñîõğàíèòüToolStripMenuItem
				// 
				this->ñîõğàíèòüToolStripMenuItem->Name = L"ñîõğàíèòüToolStripMenuItem";
				this->ñîõğàíèòüToolStripMenuItem->Size = System::Drawing::Size(133, 22);
				this->ñîõğàíèòüToolStripMenuItem->Text = L"Ñîõğàíèòü";
				this->ñîõğàíèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîõğàíèòüToolStripMenuItem_Click);
				// 
				// îĞàçğàáîò÷èêåToolStripMenuItem
				// 
				this->îĞàçğàáîò÷èêåToolStripMenuItem->Name = L"îĞàçğàáîò÷èêåToolStripMenuItem";
				this->îĞàçğàáîò÷èêåToolStripMenuItem->Size = System::Drawing::Size(107, 20);
				this->îĞàçğàáîò÷èêåToolStripMenuItem->Text = L"Î ğàçğàáîò÷èêå";
				this->îĞàçğàáîò÷èêåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îĞàçğàáîò÷èêåToolStripMenuItem_Click);
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label2->Location = System::Drawing::Point(514, 49);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(39, 20);
				this->label2->TabIndex = 6;
				this->label2->Text = L"/ 30";
				// 
				// KeyTextBox
				// 
				this->KeyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->KeyTextBox->Location = System::Drawing::Point(413, 111);
				this->KeyTextBox->Multiline = true;
				this->KeyTextBox->Name = L"KeyTextBox";
				this->KeyTextBox->ReadOnly = true;
				this->KeyTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->KeyTextBox->Size = System::Drawing::Size(388, 466);
				this->KeyTextBox->TabIndex = 7;
				// 
				// CipheredTextBox
				// 
				this->CipheredTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				this->CipheredTextBox->Location = System::Drawing::Point(828, 111);
				this->CipheredTextBox->Multiline = true;
				this->CipheredTextBox->Name = L"CipheredTextBox";
				this->CipheredTextBox->ReadOnly = true;
				this->CipheredTextBox->Size = System::Drawing::Size(372, 466);
				this->CipheredTextBox->TabIndex = 8;
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label3->Location = System::Drawing::Point(851, 88);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(210, 20);
				this->label3->TabIndex = 9;
				this->label3->Text = L"Çàøèôğîâàííûå áàéòû";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label4->Location = System::Drawing::Point(435, 88);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(121, 20);
				this->label4->TabIndex = 10;
				this->label4->Text = L"Áàéòû êëş÷à";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label5->Location = System::Drawing::Point(12, 88);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(149, 20);
				this->label5->TabIndex = 11;
				this->label5->Text = L"Èñõîäíûå áàéòû";
				// 
				// saveFileDialog1
				// 
				this->saveFileDialog1->RestoreDirectory = true;
				// 
				// openFileDialog1
				// 
				this->openFileDialog1->RestoreDirectory = true;
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label6->Location = System::Drawing::Point(12, 27);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(182, 20);
				this->label6->TabIndex = 12;
				this->label6->Text = L"Cîñòîÿíèå ğåãèñòğà";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(13, 73);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(135, 13);
				this->label7->TabIndex = 13;
				this->label7->Text = L"x^30 + x^16 + x^15 + x + 1\t";
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1212, 596);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->CipheredTextBox);
				this->Controls->Add(this->KeyTextBox);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->PlainTextBox);
				this->Controls->Add(this->EncryptButton);
				this->Controls->Add(this->RegisterLengthLabel);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->RegisterTextBox);
				this->Controls->Add(this->menuStrip1);
				this->MainMenuStrip = this->menuStrip1;
				this->Name = L"MyForm";
				this->Text = L"Lazuta 351004 Variant 8";
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

		private: Encryptor* encpyptor;

		private: System::Void KeyTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			int length = 0;
			for (int i = 0; i < RegisterTextBox->Text->Length; i++)
			{
				if (RegisterTextBox->Text[i] == '0' || RegisterTextBox->Text[i] == '1') {
					length++;
				}
			}
			RegisterLengthLabel->Text = length.ToString();

			EncryptButton->Enabled = canEncrypt();
		}

		bool canEncrypt()
		{
			return RegisterLengthLabel->Text == polynomial[0].ToString() && PlainTextBox->Text->Length > 0;
		}

		std::string formatBitssInfo(const std::vector<uint8_t>& bitArray)
		{
			std::ostringstream result;
			const size_t bitsPerByte = 8;
			if (bitArray.size() % bitsPerByte != 0) {
				return "Îøèáêà: ğàçìåğ ìàññèâà áèòîâ äîëæåí áûòü êğàòåí 8";
			}
			const size_t totalBytes = bitArray.size() / bitsPerByte;
			size_t n;
			if (totalBytes < 16) {
				n = totalBytes;
			}
			else {
				n = 16;
			}
			std::vector<uint8_t> byteArray(totalBytes);
			for (size_t byteIdx = 0; byteIdx < totalBytes; ++byteIdx) {
				uint8_t byte = 0;
				for (size_t bitIdx = 0; bitIdx < bitsPerByte; ++bitIdx) {
					size_t pos = byteIdx * bitsPerByte + bitIdx;
					byte |= (bitArray[pos] & 0x1) << bitIdx;
				}
				byteArray[byteIdx] = byte;
			}

			result << "Ïåğâûå " << n << " áàéòîâ: ";
			for (size_t i = 0; i < n && i < byteArray.size(); ++i) {
				result << std::uppercase << std::hex << std::setw(2) << std::setfill('0')
					<< static_cast<int>(byteArray[i]) << " ";
			}

			result << "               Ïîñëåäíèå " << std::dec << n << " áàéòîâ: ";
			size_t start = byteArray.size() > n ? byteArray.size() - n : 0;
			for (size_t i = start; i < byteArray.size(); ++i) {
				result << std::uppercase << std::hex << std::setw(2) << std::setfill('0')
					<< static_cast<int>(byteArray[i]) << " ";
			}

			return result.str();
		}

		std::string formatBitsInfo(const std::vector<uint8_t>& bitArray) {
			std::ostringstream result;
			const size_t bitsPerByte = 8;
			if (bitArray.size() % bitsPerByte != 0) {
				return "Îøèáêà: ğàçìåğ ìàññèâà áèòîâ äîëæåí áûòü êğàòåí 8";
			}
			const size_t totalBytes = bitArray.size() / bitsPerByte;
			size_t n;
			if (totalBytes < 16) {
				n = totalBytes;
			}
			else {
				n = 16;
			}
			std::vector<uint8_t> byteArray(totalBytes);
			for (size_t byteIdx = 0; byteIdx < totalBytes; ++byteIdx) {
				uint8_t byte = 0;
				for (size_t bitIdx = 0; bitIdx < bitsPerByte; ++bitIdx) {
					size_t pos = byteIdx * bitsPerByte + bitIdx;
					byte |= (bitArray[pos] & 0x1) << bitIdx;
				}
				byteArray[byteIdx] = byte;
			}

			result << "Ïåğâûå " << n << " áàéòîâ: ";
			for (size_t i = 0; i < n && i < byteArray.size(); ++i) {
				// Ôîğìàòèğóåì áàéò â áèíàğíîì âèäå
				for (int bit = bitsPerByte - 1; bit >= 0; --bit) {
					result << ((byteArray[i] >> bit) & 0x1);
				}
				result << " ";
			}

			result << "                                        Ïîñëåäíèå " << n << " áàéòîâ: ";
			size_t start = byteArray.size() > n ? byteArray.size() - n : 0;
			for (size_t i = start; i < byteArray.size(); ++i) {
				// Ôîğìàòèğóåì áàéò â áèíàğíîì âèäå
				for (int bit = bitsPerByte - 1; bit >= 0; --bit) {
					result << ((byteArray[i] >> bit) & 0x1);
				}
				result << " ";
			}

			return result.str();
		}

#undef min

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		private: System::Void EncryptButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			size_t keyLength = polynomial[0];
			std::vector<uint8_t> keyBytes(keyLength);
			std::string filteredKey;
			size_t i = 0;

			

			for (char c : msclr::interop::marshal_as<std::string>(RegisterTextBox->Text)) {
				if (c == '0' || c == '1') {
					if (i < keyLength) {
						keyBytes[i++] = static_cast<uint8_t>(c - '0');
						filteredKey.push_back(c);
					}
				}
			}

			int a = GetTickCount();
			//
			std::vector<uint8_t> generatedKey = generateKey(keyBytes, encpyptor->plainText.size());
			encpyptor->cipherText.resize(encpyptor->plainText.size());
			for (size_t j = 0; j < encpyptor->plainText.size(); ++j) {
				encpyptor->cipherText[j] = generatedKey[j] ^ encpyptor->plainText[j];
			}
			//
			MessageBox::Show(msclr::interop::marshal_as<System::String^>(std::to_string(GetTickCount() - a) + " ms"));

			RegisterTextBox->Text = msclr::interop::marshal_as<System::String^>(filteredKey);

			KeyTextBox->Text = msclr::interop::marshal_as<System::String^>(formatBitsInfo(generatedKey));
			

		//	

			CipheredTextBox->Text = msclr::interop::marshal_as<System::String^>(formatBitsInfo(encpyptor->cipherText));
			
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		std::vector<uint8_t> readFileBytes(const std::string& filename) 
		{
			std::ifstream fin(filename, std::ios::binary);
			std::vector<uint8_t> result;
			while (!fin.eof()) {
				result.push_back(fin.get());
			}
			return result;
		}

		std::vector<uint8_t> ConvertBytesToBits(const std::vector<uint8_t>& bytes) 
		{
			std::vector<uint8_t> plainText(bytes.size() * 8);
			for (size_t i = 0; i < bytes.size(); i++) {
				for (int j = 0; j < 8; j++) {
					plainText[i * 8 + j] = (bytes[i] >> j) & 0x1;
				}
			}
			return plainText;
		}

		private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) 
			{
				std::ifstream file(msclr::interop::marshal_as<std::string>(openFileDialog1->FileName), std::ifstream::ate | std::ifstream::binary);
				if (file) {
					std::streampos size = file.tellg();
					if (size > 130000000)
					{
						MessageBox::Show("Ñëèøêîì áîëüøîé ôàéë (âûáèğàéòå íå áîëåå 100 ìåãàáàéò)");
						return;
					}				
				}
				else {
					MessageBox::Show("Íå óäàëîñü îòêğûòü ôàéë");
					return;
				}	

				array<Byte>^ fileBytes = File::ReadAllBytes(openFileDialog1->FileName);
				std::vector<uint8_t> bytes(fileBytes->Length);
				pin_ptr<Byte> pinnedArray = &fileBytes[0];
				memcpy(bytes.data(), pinnedArray, fileBytes->Length);

				std::vector<uint8_t> plainText = ConvertBytesToBits(bytes);

				encpyptor->plainText = plainText;

				PlainTextBox->Text = msclr::interop::marshal_as<System::String^>(formatBitsInfo(plainText));

				KeyTextBox->Clear();
				CipheredTextBox->Clear();
				EncryptButton->Enabled = canEncrypt();
			}
		}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void îĞàçğàáîò÷èêåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Ëàçóòà Äìèòğèé. Ãğóïïà 351004");
}
	   void saveBitsToFile(const std::vector<uint8_t>& bitArray, const std::string& filename) 
	   {
		   std::ofstream outFile(filename, std::ios::binary);
		   if (!outFile) {
			   throw std::runtime_error("Îøèáêà îòêğûòèÿ: " + filename);
		   }

		   for (size_t i = 0; i < bitArray.size(); i += 8) {
			   uint8_t byte = 0;
			   for (size_t j = 0; j < 8; ++j) {
				   size_t bitPos = i + j;
				   if (bitArray[bitPos] > 1) {
					   throw std::invalid_argument(".....");
				   }
				   byte |= (bitArray[bitPos] << j);
			   }
			   outFile.put(byte);
		   }

		   if (!outFile.good()) {
			   throw std::runtime_error("Îøèáêà çàïèñè " + filename);
		   }
	   }

private: System::Void ñîõğàíèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		saveBitsToFile(encpyptor->cipherText, (msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName)));
	}
}
};
}
