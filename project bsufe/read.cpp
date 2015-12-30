#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
const int N = 2; // ��� UNIX � Mac OS: N = 1. 
 
int main()
{
  
  fstream fin("1.txt", ios::in | ios::ate); // ��������� ���� ��� ������, ������ � ����� �����
  if (!fin.is_open()) cout << "Error!" << endl;
 
  int i;
  i = fin.tellg(); // ������� ������� �������
  if (i == 0) cout << "File empty!\n"; // ���� ���� ����
  else
  {
     char ch;
     while (true) // ������� ������ ��������� ������
    {
        fin.seekg(-1, ios::cur); // ������ �� ���� ������� ����� �� �������
        i = fin.tellg(); // ������� ������� �������
        if (i == 0) break; // ���� ����� �� ������ �����, �� ������ ����
        ch = fin.peek();           
        if (ch == '\n') // ��� Mac OS: (ch == '\r') // ���� ��������� ������, ������ ����� ������
        {
            fin.seekg(N, ios::cur); // �� ������ ��������� ������
            break;
        }
     }
 
     string str;
     getline(fin, str); // ������ ��������� ������
   
     cout << str << endl;
   }
 
  cin.get();
  return 0;
}
