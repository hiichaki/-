#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void show(string q){
	for(int i=0;i<q.length();++i)
		cout<<q[i]<<" ";
	cout<<"\n";
}

int main(){
	ifstream f("2.txt");
	string s,k;
	getline(f,s,'\0');
	
	cout<<"key:";
	cin>>k;
	
	int n=s.length()/k.length(),
		m=k.length();
		
	if((float(s.length())/k.length()) > s.length()/k.length())
		n++;	
	
	char a[n][m];
	
	string kk=k;
	sort(kk.begin(),kk.end());
	
	show(kk);
	
	for(int i=0,z=1;i<n;++i){
		for(int j=0;j<m;++j,++z){
			if(z>s.length())
				a[i][j]=' ';
			else
				a[i][j]=s[z];
			
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	
	while(k!=kk){
		for(int i=0;i<k.length();++i){
			int j=k.find(kk[i]);
			swap(kk[i],kk[j]);
			for(int z=0;z<n;++z)
				swap(a[z][i],a[z][j]);
		}
	}
	
	show(kk);

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
		
	
}
