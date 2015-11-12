#include <iostream>
#include <stdlib.h>
#include "cheat2.h"

void sort(int *a, int length) {
     for (int j = 0; j < length-1; j++) {
         for (int i = 0; i < length-j-1; i++) {
             if (a[i] > a[i+1]) {
                 int b = a[i]; 
                 a[i] = a[i+1];
                 a[i+1] = b;
             }
         }
     }
 }

int main(){
	queue1<int>a;
	for(int i=0;i<15;++i)
		a.push_back(rand()%41-20);
		a.pop_front();
		
	bool q=0;
	a.show();
	cout<<"min:"<<a.min();
	cout<<"\nmax:"<<a.max()<<"\n";
	
	int i1,i2;
	
	for(int i=0;i<a.count();++i){
		if(a[i]==a.min())
			i1=i;
		if(a[i]==a.max())	
			i2=i;
	}

	int s[i2-i1];
	for(int i=i1;i<=i2;++i)
		 s[i]=a[i];
	for(int i=0;i<=i2-i1;++i)
		a.remove(s[i]);
	
	int z[a.count()];
	for(int i=0;i<a.count();++i)
		z[i]=a[i];
	sort(z,a.count());

	queue1<int>b;
	for(int i=0;i<a.count();++i)
		b.push_back(z[i]);
		
		
	b.show();	
}
