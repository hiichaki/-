#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct Data{
	int d,m,y;
	
	Data(){
		d=rand()%31+1;
		m=rand()%12+1;
		y=rand()%215+1800;
	}
	
};

void Show(Data a){
	cout<<a.d<<":"<<a.m<<":"<<a.y<<"\n";
}
int azaza=0;
struct Product{
	string name,create;
	double price;
	Data from,to;	 
	
	Product(){
		name="qwe"+to_string(azaza);
		create="asd"+to_string(azaza);
		azaza++;
		price=rand()%5000;
		while(to.y<from.y)	
			to.y+=10;		
	}
};

void Show(Product a){
	cout<<"name:"<<a.name<<" create:"<<a.create;
	cout<<"\nprice:"<<a.price;
	cout<<"\nfrom:";Show(a.from);
	cout<<"  to:";Show(a.to);
	cout<<(a.to.q-a.from.q)/30<<"\n";
	
}

void fitness(Product *a,int n){
	for(int i=0;i<n;++i)
		if(a[i].to.q-a[i].from.q>365/2)
			cout<<"name:"<<a[i].name<<" q:"<<(a[i].to.q-a[i].from.q)/30<<"\n";
}

void min_max(Product *a,int n){
	int min=a[0].price;
	int max=min;
	for (int i=0;i<n;++i){
		if(a[i].price>max)
			max=i;
		if(a[i].price<min)
			min=i;	
	}	
	cout<<"min:\n";
	Show(a[min]);
	cout<<"max:\n";
	Show(a[max]);
}

int main(){
	srand (time(NULL));
	int n;
	cin>>n;
	Product *a = new Product[n];
	for(int i=0;i<n;++i)
		Show(a[i]);
	fitness(a,n);	
//	min_max(**a);
}
