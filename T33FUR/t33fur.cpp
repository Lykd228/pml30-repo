#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include "fur.h"

void expert_system::LoadRec(fstream &f, node **T)
{
	char* Text = nullptr;
	node *yes = nullptr, *no = nullptr;
	try
	{
		int len;
		f.read(reinterpret_cast<char*>(&len), sizeof(size_t));
		Text = new char[len + 1];
		f.read(Text, len + 1);
		Text[len] = '\0';
		f.read(reinterpret_cast<char*>(&no), sizeof(size_t));
		f.read(reinterpret_cast<char*>(&yes), sizeof(size_t));
	}
	catch (...)
	{
		if (Text != nullptr)
			delete[] Text;
		return;
	}
	*T = new node(Text);
	delete[] Text;
	if (no != nullptr)
		LoadRec(f, &(*T)->No);
	if (yes != nullptr)
		LoadRec(f, &(*T)->Yes);
}

void expert_system::SaveRec(fstream &f, node *T)
{
	if (T == nullptr)
		return;

	int len = T->Text.length();
	char *Text = new char[len + 1];
	strncpy(Text, T->Text.c_str(), len);
	
	f.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
	f.write(Text, len + 1);
	f.write(reinterpret_cast<const char*>(&T->No), sizeof(size_t));
	f.write(reinterpret_cast<const char*>(&T->Yes), sizeof(size_t));
	delete[] Text;

	SaveRec(f, T->No);
	SaveRec(f, T->Yes);
}

void expert_system::Session(void)
{
	node **T = &Root;
	while (*T != nullptr)
	{
		cout << (*T)->Text << "?";
		uchar key = _getch();
		cout << (key == 'Y' || key == 'y' || key == (uchar)'Д' || key == (uchar)'д' ? " Yes" : " No") << endl;
		node **prev = T;
		T = (key == 'Y' || key == 'y' || key == (uchar)'Д' || key == (uchar)'д' ? &(*T)->Yes : &(*T)->No);
		if (*T == nullptr && (key == 'N' || key == 'n' || key == (uchar)'Н' || key == (uchar)'н'))
		{
			cout << "тогда введите новое опрееление: ";
			string Qst;
			getline(cin, Qst);
			cout << "введите правильный ответ для определения: ";
			string Ans;
			getline(cin, Ans);
			*prev = new node(Qst, *prev, new node(Ans));
			break;
		}
	}
}

int main(void)
{
	bool run = true;
	expert_system ExSys;
	system("chcp 1251");

	ExSys.Load("M.Orlov.DB");
	while (run)
	{
		string FileName;
		cout << endl;
		cout << "0. exit" << endl;
		cout << "1. session" << endl;
		cout << "2. draw tree" << endl;
		cout << "3. save tree" << endl;
		cout << "4. load tree" << endl;

		switch (_getch())
		{
		case '0':
			run = false;
			break;
		case '1':
			ExSys.Session();
			break;
		case '2':
			ExSys.Draw();
			break;
		case '3':
			cout << "Input file name:";
			getline(cin, FileName);
			if (ExSys.Save(FileName))
				cout << "Success" << endl;
			else
				cout << "Fail" << endl;
			break;
		case '4':
			cout << "Input file name:";
			getline(cin, FileName);
			if (ExSys.Load(FileName))
				cout << "Success" << endl;
			else
				cout << "Fail" << endl;
			break;
		default:
			cout << "Incorrect choice" << endl;
		}
	}
	ExSys.Save("M.Orlov.DB");
	return 0;
}
