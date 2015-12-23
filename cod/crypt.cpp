#include <iostream>
#include <fstream>
using namespace std;

string cryptCaesar(string s){
	int n;
	cin>>n;
	for(int i=0;i<s.length();++i)
		s[i]+=n;
	return s;	
}

void save(string s,string u){
	ofstream ff(u);
	ff<<s;	
	ff.close();	
}

int main(){
	ifstream f("1.txt");
	string s;
	getline (f,s,'\0');
	f.close();

	s=cryptCaesar(s);
	
	save(s,"2.txt");

}
