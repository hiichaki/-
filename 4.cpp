#include <iostream>

int qwe(int q){
	int s=0;
	while(q>0){
		s+=q%10;
		q/=10;
	}
	return s;	
}

int qw(int q){
	if(q/10 == 0) return q;
	return q%10 + qw(q/10);
}

int main(){
std::cout<<qwe(12355);
}
