#include <list>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	list<char> a;
	bool q=0;
	for(int i=0;i<20;++i){
			a.push_back(char((rand()%27+97)-48));	
	}
	for(auto it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	a.unique();
	for(auto it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	a.sort();
	cout<<"\n";
	for(auto it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
		cout<<"\n";	
		
}
