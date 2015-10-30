#include<iostream>
#include <fstream>
using namespace std;
int main(){
ifstream f("1.txt");
int n;
string s;
getline (f,s,'\0');
f.close();
cin>>n;
for(int i=0;i<s.length();++i)
	s[i]+=n;
	
ofstream ff("1.txt");
	 ff<<s;	
}
