#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

string decrypt(string s,int q,string key){
	string alpha,a;
	cout<<key<<"\n";
	
	for(int i=97;i<97+26;++i)
		alpha+=char(i);
	a=alpha;
	
	remove_if(alpha.begin(),alpha.end(),[key](char a){
		for(int i=0;i<key.length();++i)
			if(a==key[i])
				return true;
		return false;
	});
	
	alpha.resize(alpha.length()-key.length());
	
	string de;
	for(int i=0;i<26;++i)
		de+='.';
	
	int i,j;
	for(i=q,j=0;j<key.length();++i,++j)
		de[i]=key[j];
		
	j=0;
	while(i<26){
		de[i]=alpha[j];
		i++;
		j++;
	}
	i=0;
	while(i<q){
		de[i]=alpha[j];
		i++;
		j++;
	}
	cout<<s<<"\n";
	
//	for(int i=0;i<26;++i)
//		replace (s.begin(),s.end(),de[i],a[i]);

	for(int i=0;i<s.length();++i)
		for(int j=0;j<a.length();++j)
			if(s[i]==de[j]){
				s[i]=a[j];	
				break;
			}
	
	cout<<a<<"\n";
	cout<<de<<"\n";
	cout<<s<<"\n";	
	
	return s;	
}

int main(){
	ifstream f("22.txt");
	string s,key;
	int q;
	f>>q>>key;
	getline (f,s,'\0');
	
	s=decrypt(s,q,key);
	
	ofstream ff("2.txt");
	ff<<s;
	
}
