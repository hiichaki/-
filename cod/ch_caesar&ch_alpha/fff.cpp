#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	const string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int k;
	string keyword;
	cin>>k>>keyword;
	char kr[alphabet.length()];
	for(int i=0; i<keyword.length(); i++)
	{
		kr[i+k] = keyword[i];
	}
	
	string tmp = alphabet;
	remove_if(tmp.begin(), tmp.end(), [keyword](char c) {
		for(int i=0; i<keyword.length(); i++)
			if(keyword[i] == c) return true;
		return false;
	});
	
	for(int i = k+keyword.length(); i<alphabet.length(); i++) {
		kr[i] = tmp[0];
		tmp.erase(0,1);
	}
	
	for(int i=0; i<k; i++) {
		kr[i] = tmp[0];
		tmp.erase(0,1);
	}
	
//	cout<<kr;
	
	ifstream file1("11.txt");
	string f1,f2="";
	getline(file1,f1,'\0');
	file1.close();
	
	for(int i=0; i<f1.length(); i++) {
		int j = alphabet.find(f1[i]);
		
		if(j == string::npos)
			f2+= f1[i];
		else
			f2+= kr[j];
	}
	
	ofstream file2("22.txt");
	file2<<k<<" "<<keyword<<" ";
	file2<<f2;
	file2.close();
	
	cin.get();
	
}
