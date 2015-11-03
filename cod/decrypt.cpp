#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <windows.h>
using namespace std;

void show(map<char,int> m){
	double sum=0;
	for(auto it=m.begin();it!=m.end();++it)
		sum+=it->second;
	for(auto it=m.begin();it!=m.end();++it){
		cout<<it->first<<":"<<it->second;
		if(it->second<10)
			cout<<" ";
		cout<<"  "<<it->second*100/sum<<"%"<<endl;	
	}
}

char maxx(string s,bool q){
	map <char,int> m;
	for(int i=0;i<s.length();i++)
		m[s[i]]++;
		
    char max=m.begin()->first;
    
    for(map<char,int>::iterator it=m.begin();it!=m.end();++it){
        if (it->second>m[max])
            max=it->first;
	}
	if(q)
	  show(m);
	return max;	
}

string decrypt(char a,string l,int max,string s){
	int key=a-max;
	cout<<"\n"<<key<<"\n";
	for(int i=0;i<s.length();++i)
		s[i]+=key;
	return s; 	
}

void save(string s,string u){
	ofstream ff(u);
	ff<<s;	
	ff.close();	
}

string decryptCaesar(string s){
	string ss,sss;
	ss=s;
	sss=s;
	char max;
	
    sort(ss.begin(),ss.end());
    ss.resize(unique(ss.begin(),ss.end())-ss.begin());
    cout<<ss<<"\nwith space 1,norm 0:";
    
    bool q;
	cin>>q;
	max=maxx(s,q);
	
	if(q){
		return decrypt(' ',"space.txt",max,s);
	}
	else{
		sss.erase(std::remove(sss.begin(),sss.end(),max),sss.end()); 
		q=true;
		max=maxx(sss,q);
		return decrypt('e',"e.txt",max,s);
	}
}

int main (){    

	string s,ss;
	ifstream f("1.txt");
	getline (f,s,'\0');
	f.close();
	
	s=decryptCaesar(s);
	save(s,"2.txt");
	
 	system("pause");
}
