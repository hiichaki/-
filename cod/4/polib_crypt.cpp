#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

string alpha(){
	string s;
	for(int i=97;i<96+27;++i)
		s+=char(i);
	s+=" .,-";	
	random_shuffle(s.begin(),s.end());
	ofstream k("key_alpha.txt");
	k<<s;
	k.close();
	return s;	
}

char crypt(char a[][6],char q){
	for(int i=0;i<5;++i)
		for(int j=0;j<6;++j)
			if(a[i][j]==q)
				if(i!=4)
					return a[i+1][j];
				else
					return	a[0][j];				
}

int main(){
	char a[5][6];
	string aa=alpha(),s;
	ifstream f("1.txt");
	getline(f,s,'\0');
	f.close();
	
	for(int i=0,z=0;i<5;++i){
		for(int j=0;j<6;++j,++z){
			a[i][j]=aa[z];
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	string ss="";
	cout<<"\n";
	for(int i=0;i<s.length();++i)
		ss+=crypt(a,s[i]);
	
	ofstream ff("2.txt");
	ff<<ss;
	ff.close();
	cout<<ss;
			
}
