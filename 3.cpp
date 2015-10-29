#include <iostream>

double com(int n,int k){
	return (k==0||k==n)?1:com(n-1,k)+com(n-1,k-1);
}

int main(){
	std::cout<<com(15,10);
}
