#include <iostream>
using namespace std;

class Qwe{
	
	public:
		int a,b,*arr;
		Qwe(){
			a=1;
		}
		
	friend ostream& operator<<(ostream& os, const Qwe& a){
		os<<a.a<<" "<<a.b;
    	return os;
	}
	friend istream& operator>>(istream& is, Qwe& a){
	    is>>a.a>>a.b;
	    return is;
	}
	friend bool operator==(Qwe a,Qwe b){
		return a.a==b.a;
	}
	friend bool operator>(Qwe a,Qwe b){
		return a.a>b.a;
	}
	friend bool operator<(Qwe a,Qwe b){
		return a.a<b.a;
	}
	friend bool operator!=(Qwe a,Qwe b){
		return a.a!=b.a;
	}
	friend bool operator>=(Qwe a,Qwe b){
		return !(a<b);
	}
	friend bool operator<=(Qwe a,Qwe b){
		return !(a>b);
	}
	void operator++(int qq){
		 a++;
	}
	void operator++(){
		 ++a;
	}
	void operator--(int qq){
		 a--;
	}
	void operator--(){
		 --a;
	}
	friend Qwe operator+(Qwe a, Qwe b){
		a.a+=b.a;
		return a;
	}
	friend Qwe operator-(Qwe a, Qwe b){
		a.a-=b.a;
		return a;
	}
	friend Qwe operator*(Qwe a, Qwe b){
		a.a*=b.a;
		return a;
	}
	friend Qwe operator/(Qwe a, Qwe b){
		a.a/=b.a;
		return a;
	}
	void operator+=(Qwe b){
		this->a+=b.a;
	}
	void operator-=(Qwe b){
		this->a-=b.a;
	}
	void operator*=(Qwe b){
		this->a*=b.a;
	}
	void operator/=(Qwe b){
		this->a/=b.a;
	}
	void operator=(Qwe b){
		this->a=b.a;
	}
	int& operator[] (int i){
		return arr[i];
	} 
    int operator() (int i){
		return arr[i]*i;
	}
};


int main(){
	Qwe q,b;

	
	cout<<q+b;
}
	
