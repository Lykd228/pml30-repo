#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

typedef unsigned char uchar;
struct fur
{
  struct treenode
  {
    std::string Text;
    treenode *No, *Yes;
    treenode( const std::string &NewT, treenode *NewN = nullptr, treenode *NewY = nullptr ) : Text(NewT), No(NewN), Yes(NewY)
    {
    }
  } *Root;

  fur( void ) : Root(nullptr)
  {
  }

  ~fur( void )
  {
    Clear();
  }

  void Session( void )
  {
    treenode **T = &Root;
    if (*T == nullptr)
      return;
    while (true)
    {
      std::cout << (*T)->Text << "?";
      uchar key = _getch();
      std::cout << (key == 'Y' || key == 'y' || key == (uchar)'Д' || key == (uchar)'д' ? " Yes" : " No") << std::endl;
      if ((*T)->Yes != nullptr)
        T = (key == 'Y' || key == 'y' || key == (uchar)'Д' || key == (uchar)'д' ? &(*T)->Yes : &(*T)->No);
      else
      {
        if (key == 'N' || key == 'n' || key == (uchar)'Н' || key == (uchar)'н')
        {
          std::cout << "тогда введите новое опрееление: ";
          std::string Qst;
          std::getline(std::cin, Qst);
          std::cout << "введите правильный ответ для определения: ";
          std::string Ans;
          std::getline(std::cin, Ans);
          *T = new treenode(Qst, *T, new treenode(Ans));
        }
        return;
      }
    }
  }

  void ClearRec( treenode **T )
  {
    if (*T == nullptr)
      return;
    ClearRec(&(*T)->No);
    ClearRec(&(*T)->Yes);
    delete *T;
    *T = nullptr;
  }
  
  void Clear( void )
  {
    ClearRec(&Root);
  }

  void DrawRec( treenode *T, int Level )
  {
    if (T == nullptr)
      ;
    else
    {
      DrawRec(T->Yes, Level + 2);
      for (int i = 0; i < Level * 8; i++)
        std::cout << " ";
      std::cout << T->Text;
      DrawRec(T->No, Level + 2);
    }
  }

  void Draw( void )
  {
    DrawRec(Root, 0);
  }

  void LoadRec( std::fstream &f, treenode **T )
  {
    char Text[102];
    char tmp[2];
    treenode *yes = nullptr, *no = nullptr;
    try
    {
      f.read(Text, 102);
      f.read(tmp, 2);
      f.read((char *)&no, 4);
      f.read((char *)&yes, 4);
    }
    catch ( ... )
    {
      return;
    }
    *T = new treenode(Text);
    if (no != nullptr)
      LoadRec(f, &(*T)->No);
    if (yes != nullptr)
      LoadRec(f, &(*T)->Yes);
  }

  bool Load( const std::string &FileName )
  {
    std::fstream f(FileName, std::fstream::in | std::fstream::binary);
    if (!f)
      return false;
    Clear();
    LoadRec(f, &Root);
    return true;
  }

  void SaveRec( std::fstream &f, treenode *T )
  {
    if (T == nullptr)
      return;
    char Text[102];
    char tmp[2];
    tmp[0] = tmp[1] = 0;
    strncpy(Text, T->Text.c_str(), 101);
    f.write(Text, 102);
    f.write(tmp, 2);
    f.write((const char *)&T->No, 4);
    f.write((const char *)&T->Yes, 4);
    SaveRec(f, T->No);
    SaveRec(f, T->Yes);
  }

  bool Save( const std::string &FileName )
  {
    std::fstream f(FileName, std::fstream::out | std::fstream::binary);
    if (!f)
      return false;
    SaveRec(f, Root);
    return true;
  }
};
