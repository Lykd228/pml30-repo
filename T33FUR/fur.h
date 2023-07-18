#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;
typedef unsigned char uchar;

struct expert_system
{
	struct node
	{
		string Text;
		node *No, *Yes;
		node(const string &NewT, node *NewN = nullptr, node *NewY = nullptr) : Text(NewT), No(NewN), Yes(NewY)
		{
		}
	} *Root;

	expert_system(const string& Text = "свинья") : Root(new node(Text))
	{
	}

	~expert_system(void)
	{
		Clear(&Root);
	}

	void Session(void);

	void Clear(node **T = nullptr)
	{
		if (T == nullptr)
			T = &Root;
		if (*T == nullptr)
			return;
		Clear(&(*T)->No);
		Clear(&(*T)->Yes);
		delete* T;
		*T = nullptr;
	}

	void Draw(node *T = nullptr, int Level = 0)
	{
		if (Level == 0)
			T = Root;
		if (T == nullptr)
			;
		else
		{
			Draw(T->Yes, Level + 2);
			for (int i = 0; i < Level * 10; i++)
				cout << " ";
			cout << T->Text << endl;
			Draw(T->No, Level + 2);
		}
	}

	void LoadRec(fstream &f, node **T);

	bool Load(const string &FileName)
	{
		fstream f(FileName, fstream::in | fstream::binary);
		if (!f)
			return false;
		Clear();
		LoadRec(f, &Root);
		return true;
	}

	void SaveRec(fstream &f, node *T);

	bool Save(const string &FileName)
	{
		fstream f(FileName, fstream::out | fstream::binary);
		if (!f)
			return false;
		SaveRec(f, Root);
		f.close();
		return true;
	}
};
