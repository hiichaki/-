#include <iostream>
#include <fstream>
using namespace std;

string abc(){
	string s;
	for(int i=97;i<96+27;++i)
		s+=char(i);
	return s;	
}

int main(){
	const string q=abc();
	ifstream f("2.txt");

    string k="encrypting",key="";
    cout<<"key:";
    cin>>k;
    string s;
    getline(f,s,'\0');

    for(int i=0,z=0;i<s.length();++i,++z){
    	if(z>k.length()-1)
    		z=0;
    	key+=k[z];
	}
	
	int p,w;
	string ss;
	
	for (int i=0; i<s.length(); i++){
        p=q.find(s[i]);
        w=q.find(key[i]);
        ss.insert(i,1,q.at((p-w+26)%26)); 
    }
    
	ofstream ff("2.txt");
	ff<<ss;
	ff.close();
	cout<<ss;
    
}
