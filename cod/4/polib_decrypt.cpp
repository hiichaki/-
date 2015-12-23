#include <iostream>
#include <fstream>
using namespace std;

//string alpha(){
//	string s;
//	for(int i=97;i<96+27;++i)
//		s+=char(i);
//	s+=" .,-";	
//	return s;	
//}

char decrypt(char a[][6],char q){
	for(int i=0;i<5;++i)
		for(int j=0;j<6;++j)
			if(a[i][j]==q)
				if(i!=0)
					return a[i-1][j];
				else
					return	a[4][j];				
}

int main(){
	char a[5][6];
	//string aa=alpha();
	ifstream k("key_alpha.txt");
	string aa;
	getline(k,aa);
	k.close();	
	string s;
	ifstream f("2.txt");
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
		ss+=decrypt(a,s[i]);
		
	cout<<ss;


}

