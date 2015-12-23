#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

struct Car{
	string name;
	int year,price;
	
	Car(){
		name="qwe";
		year=rand()%116+1900;
		price=rand()%3000+3000;
	}
	
	void show(){
		cout<<"name:"<<name
			<<"\nyear:"<<year
			<<"\nprice:"<<price
			<<"\n";	
	}
};

void check(Car q){
	if(2015-q.year>10&&q.price<5000)
		q.show();
}

int main(){
	int n;
	cin>>n;
list<Car>q(n);
	for(auto c:q)
		check(c);
		
}

