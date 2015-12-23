#include <iostream>
#include <stdlib.h>
using namespace std;

struct tel{
	string firm;
	int d,grn;
	
	tel(){
		firm="qwe";
		d=rand()%14+16;
		grn=rand()%10000;
	}
	void show(){
		cout<<"firm:"<<firm
			<<"\nd:"<<d
			<<"\ngrn:"<<grn
			<<"\n";
	}
};

void check(tel q){
	if(q.d>=17&&q.grn<5500)
		q.show();
}

int main(){
	int n;
	cin>>n;
	tel q[n];
	for(int i=0;i<n;++i)
		check(q[i]);
}

