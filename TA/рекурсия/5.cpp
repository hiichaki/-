#include <iostream>

int reverse(int a){ 
	int sign=1,res=0;
		if(a<0) 
			sign=-1;
	a=abs(a);
	int aa=a; 
	    while(aa>0){
	 	  	res=res*10+aa%10;
				 aa/=10;
		}
	return res*sign;
}

int main() {
	std::cout<<reverse(12345);
}
