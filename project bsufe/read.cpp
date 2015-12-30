#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
const int N = 2; // для UNIX и Mac OS: N = 1. 
 
int main()
{
  
  fstream fin("1.txt", ios::in | ios::ate); // открываем файл для чтения, курсор в конце файла
  if (!fin.is_open()) cout << "Error!" << endl;
 
  int i;
  i = fin.tellg(); // текущая позиция курсора
  if (i == 0) cout << "File empty!\n"; // если файл пуст
  else
  {
     char ch;
     while (true) // находим начало последней строки
    {
        fin.seekg(-1, ios::cur); // курсор на одну позицию назад от текущей
        i = fin.tellg(); // текущая позиция курсора
        if (i == 0) break; // если дошли до начала файла, то строка одна
        ch = fin.peek();           
        if (ch == '\n') // для Mac OS: (ch == '\r') // если следующий символ, символ новой строки
        {
            fin.seekg(N, ios::cur); // на начало последней строки
            break;
        }
     }
 
     string str;
     getline(fin, str); // читаем последнюю строку
   
     cout << str << endl;
   }
 
  cin.get();
  return 0;
}
