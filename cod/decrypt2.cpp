#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

void save(string s,string u){
	ofstream ff(u);
	ff<<s;	
	ff.close();	
}

int main(){
	map<int,int> m;
	string s;
	ifstream f("1.txt");
	getline (f,s,'\0');
	f.close();

    list<int> words;
    istringstream ist(s);
    int tmp;
    while(ist>>tmp)
        words.push_back(tmp);
        
    double n=0;    
    for(auto it=words.begin();it!=words.end();++it){
    	m[*it]++;n++;}
    	
    int maxs=0,maxf;
    
	for(auto it=m.begin();it!=m.end();++it){
		if(it->second>maxs){
			maxf=it->first;
			maxs=it->second;
		}
		cout<<it->first<<" "<<double(it->second/n)<<"\n";
	}
	cout<<"max:"<<maxf<<"\n";
	
	string ss;
	for(auto it=words.begin();it!=words.end();++it)
		ss+=char(*it/2);
	
	save(ss,"2.txt");
	
}
