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
	string s;
	ifstream f("1.txt");
	getline(f,s,'\0');
	f.close();
	string k;
	cout<<"key:";
	cin>>k;
	cout<<"\n";
	int n=s.length()/k.length(),
		m=k.length();
		
	if((float(s.length())/k.length()) > s.length()/k.length())
		n++;
	
	char a[n][m];	
	
	show(k);
	
	for(int i=0,z=0;i<n;++i){
		for(int j=0;j<m;++j,++z){
			if(z>s.length())
				a[i][j]=' ';
			else
				a[i][j]=s[z];
			
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<k.length()-1;i++)
    	for(int j=0;j<k.length()-i-1;j++)
        if(k[j]>k[j+1]){
            swap(k[j],k[j+1]);
			for(int i=0;i<n;++i)
				swap(a[i][j],a[i][j+1]);	
		}
		
	cout<<"\n";
	show(k);
	
	ofstream ff("2.txt");
	string q=" ";
	
    for(int i=0,z=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<a[i][j]<<" ";
			q+=a[i][j];
		}
		cout<<"\n";	
	}
	
	ff<<q;
	ff.close();
}
