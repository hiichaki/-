#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fstream>
using namespace std;

string alpha(){
	string s;
	for(int i=97;i<96+27;++i)
		s+=char(i);
	return s;	
}
string a=alpha()+" ";

void show(map<char,int> m){
	for(auto c:m)
		cout<<c.first<<":"<<c.second<<"\n";
}

map<char,int> fill(){
	int q[a.size()];
	
//	set<int> w;
//	while(w.size()<a.size()){
//		w.insert(rand()%100);
//	}
//	int i=0;
//	for(set<int>::iterator it=w.begin();it!=w.end();++it,++i)
//		q[i]=*it;
	
	for(int i=1;i<=a.size();++i)
		q[i-1]=i;
	
//	random_shuffle(q,q+a.size());
	
	map<char,int> m;
	
	for(int i=0;i<a.size();++i)
		m[a[i]]=q[i];	

	return m;
}

int mod(unsigned long long q,int n){
	n*=1000;
	while(q>n)
		q-=n;
	n/=1000;
	while(q>n)
		q-=n;	
	if(q==n)	
		q=0;
	return q;
}

int Fi(int p,int q){
	return (p-1)*(q-1);
}

bool isSimple(int n){
    for(int i=2;i<=n/2;i++) 
		if(n%i==0) 
			return 0;
	return 1;
}

int genE(int f){
	cout<<"choose E:";
	for(int i=3;i<f;++i)
		if(isSimple(i)&&(f%i))
			cout<<i<<" ";
	cout<<"\n";
	int E;
	cin>>E;
	return E;		
}

int genD(int E,int f){
	cout<<"choose d:";
	for(int i=0;i<100;++i)
		if((i*E)%f==1)	
			cout<<i<<" ";
	cout<<"\n";		
	int d;
	cin>>d;
	return d;		
}

int crypt(int x,int E,int n){
	int c;
	c=mod(pow(x,E),n);
	return c;
}

int decrypt(int c,int d,int n){
	int x;
	x=mod(pow(c,d),n);
	return x;
}

int main(){	
//	srand(time(NULL));
	ifstream f("1.txt");
	string s;
	getline(f,s,'\0');
	f.close();
	int k[3];
	
	map<char,int>m;
	
	m=fill();
	show(m);	
	cout<<"k:";
	for(int c:k){
		c=rand()%26;	
		cout<<c<<" ";
	}
	cout<<"\n";
	int p=3,q=11,n,F;
	
	n=abs(p*q);
	F=Fi(p,q);
	
//	cout<<"\nFi:"<<f
//		<<"\nn:"<<n<<"\n\n"
//		<<"(E*d)%Fi=1\n";
		
	int E,d;
	
//	E=genE(f);
	E=3;
//	d=genD(E,f);
	d=7;
	
	unsigned long long c[s.size()];
	
	cout<<s
		<<"\nchanged: ";
		
	ofstream ff("2.txt");	
	for(int i=0;i<s.length();++i){
		auto it=m.find(s[i]);
		c[i]=crypt(it->second,E,n);
		cout<<it->second<<" ";
		ff<<c[i]<<" ";	
	}
	ff.close();
	cout<<"\ncrypt:   ";
	
	for(int i=0;i<s.length();++i)
		cout<<c[i]<<" ";
	
}
