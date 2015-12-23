#include <iostream>
#include <stdlib.h>
using namespace std;

struct time{
	int h,m;
	time(){
		h=rand()%24;
		m=rand()%60;
	}
};

struct train{
	int numb,freePlac,freeKup;
	string from,to;
	time t;	
	train(){
		freePlac=rand()%30;
		freeKup=rand()%30;
		if(rand()%2)
			from="l";
		else
			from="q";	
	}	
};

void Show(train a){
	cout<<"from:"<<a.from<<"\nto:"<<a.to<<"\nnumb:"<<a.numb<<"\nfreePlac:"<<a.freePlac<<"\nfreeKup:"<<a.freeKup<<"\ntime:"<<a.t.h<<":"<<a.t.m<<"\n";
}

void Shows(train a){
	cout<<"freePlac:"<<a.freePlac<<endl;
}

void Showf(train a){
	cout<<"from:"<<a.from<<endl;
}

void Showff(train a){
	if(a.from!="l")
	cout<<"from:"<<a.from<<endl;
}

template<size_t N>train sum(train (&a)[N]){
	train aa;
	int max=0;
	for(int i=0;i<N;++i)
		if(a[i].freePlace+a[i].freeKup>max){
			max=a[i].numb;
			aa=a[i];
		}
	return aa;
}

template<size_t N>train hour(train (&a)[N],int H){
	train aa;
	for(int i=0;i<N;++i)
		if(a.t.h==H+1)
			aa=a[i];	
	return aa;
}

template<size_t N>train sort(train (&a)[N]){
	train aa;
     for (int j = 0; j < N-1; j++) 
         for (int i = 0; i < N-j-1; i++) {
             if (a[i].freePlac > a[i+1].freePlac) {
                 train b = a[i]; 
                 a[i].freePlac = a[i+1].freePlac;
                 a[i+1].freePlac = b.freePlac;
             }
         }
}

int del(train a[],int n){
	
	for(int i=0;i<=n;++i)
		if(a[i].from=="l"){
			cout<<"qwe\n";
			for (int j = i; j < n-1; ++j)
			  a[i]=a[i+1];
			 n--; 
		}
		return n;
}

int main(){
int n=6;
train* a = new train[n];

for(int i=0;i<n;++i)
	Showf(a[i]);
cout<<"del\n";
for(int i=0;i<n;++i)
	Showff(a[i]);

		
delete [] a;
}
