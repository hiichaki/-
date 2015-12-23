#include <iostream>

double sumr(double n){
	return n<1?1:sumr(n-1)+1/(1+n);
}

int main(){
	std::cout<<sumr(3);
}
