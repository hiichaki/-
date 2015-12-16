#include <iostream>
#include <map>
#include <set>
#include <vector>
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

void fail(int q){
	for(int i=0;i<q;++i)
		cout<<rand()%100<<" ";
	cout<<"\n";
	for(int i=0;i<q;++i)
		cout<<char(rand()%100);
}

bool isSimple(int n){
    for(int i=2;i<=n/2;i++) 
		if(n%i==0) 
			return 0;
	return 1;
}

bool check(int *q){
	if(q[0]!=15||q[1]!=7||q[2]!=16)
		return 0;
	else
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
	srand(time(NULL));
	string s;
	int k[3];
	cout<<"k(3):";
	for(int i=0;i<3;++i)
		cin>>k[i];
	
	
			
	map<char,int>m;
	
	m=fill();
//	show(m);	
	
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
	
	vector<int> v;
	
	ifstream f("2.txt");
	int tmp;
	while(!f.eof()){
		f>>tmp;
		v.push_back(tmp);
	}
	if(!check(k)){
		fail(v.size());
		return 0;
	}

	
	int c[v.size()];
	int i=0;
	for(vector<int>::iterator it=v.begin();it<v.end();++it){
		c[i]=decrypt(*it,d,n);
		cout<<c[i]<<" ";
		i++;
	}
	
	cout<<"\n\n";
	ofstream ff("2.txt");
	for(int i=0;i<v.size()-1;++i)
		for(auto it=m.begin();it!=m.end();++it)
			if(c[i]==it->second){
				cout<<it->first;
				ff<<it->first;
			}
	
					
	cout<<"\n";
}
