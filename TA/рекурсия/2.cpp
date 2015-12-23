#include <iostream>
#include <math.h>

double qwe(double x,double n){
	if(n==0)
		return 1;
	if(n>0)
		return qwe(x,n-1)*x;
	if(n<0)
		return 1.0/qwe(x,-n);		
}

int main(){
	std::cout<<qwe(2,3);
}
