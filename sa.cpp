#include <iostream>
#include <algorithm>
#include "cheat2.h"
using namespace std;

int main(){
string s,ss;
cin>>s;

	for(int i=0;i<s.length()/2;++i){
		ss="";
		for(int q=0;q<i;++q)
			ss+=s[q];
		for(int j=0;j<s.length()/(i+1);j+=i){
			int w=0;
			while(find(s.begin(),s.end(),ss)){
				w++;
			}
			if(w==s.length()/(i+1))
				cout<<"\nazaza\n";
				
		}

		cout<<ss<<"\n";
	}
		
		
}

