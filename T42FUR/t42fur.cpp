#include <cstdlib>
#include "fur.h"

int main( void )
{
  bool run = true;
  fur ExSys;
  ExSys.Load("M.Orlov.DB");
  system("chcp 1251");

  while (run)
  {
    std::string FileName;
    std::cout << std::endl;
    std::cout << "0. exit" << std::endl;
    std::cout << "1. session" << std::endl;
    std::cout << "2. draw tree" << std::endl;
    std::cout << "3. save tree" << std::endl;
    std::cout << "4. load tree" << std::endl;

    switch(_getch())
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
      std::cout << "Input file name:";
      std::getline(std::cin, FileName);
      if (ExSys.Save(FileName))
        std::cout << "Success" << std::endl;
      else
        std::cout << "Fail" << std::endl;
      break;
    case '4':
      std::cout << "Input file name:";
      std::getline(std::cin, FileName);
      if (ExSys.Load(FileName))
        std::cout << "Success" << std::endl;
      else
        std::cout << "Fail" << std::endl;
      break;
    default:
      std::cout << "Incorrect choice" << std::endl;
    }
  }
  ExSys.Save("M.Orlov.DB");
  return 0;
}
