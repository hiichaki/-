#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream f("1.txt");
	string s;
	int a,b;
	getline (f,s,'\0');
	f.close();
	vector<int>v;
	cin>>a>>b;
	
	for(int i=0;i<s.length();++i)
		v.push_back((s[i]*a+b));
	
	ofstream ff("2.txt"),fff("3.txt");
	ff<<a<<" "<<b<<" ";
	for(auto it=v.begin();it!=v.end();++it){
		ff<<*it<<" ";
		fff<<char(*it%26)<<" ";
	}
		
	ff.close();
	fff.close();
}
