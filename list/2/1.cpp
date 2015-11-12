#include <iostream>
#include "cheat2.h"
using namespace std;

int main(){
	 stack1<char>a,c;
	 	for(int i=97;i<97+27;++i)
	 		a.push_front(char(i));
	 		a.pop_front();
	 	a.show();


	string q="wrtpsdfghjklzxvbqnmc";
	for(int j=0;j<q.length();++j)
	 	for(int i=0;i<27;++i){
	 		if(a[i]==q[j])
	 			c.push_front(a[i]);
		 }
	
	 q="aeyuio";
	for(int i=0;i<q.length();++i)
		a.remove(q[i]);
	
	a.show();
	c.show();
		 		
}
