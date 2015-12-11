#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct Graph{
	double x,y;
	string s;
	
	void Show(){
		cout<<x<<" "<<y<<"\n";
	}
};

typedef list<Graph> graph;

int main(){
	
ifstream f("1.txt");	
graph q;//list
Graph tmp;//struct tmp

while(!f.eof()){
	f>>tmp.x>>tmp.y;
	q.push_back(tmp);
}
f.close();
 	for(auto it=q.begin();it!=q.end();it++){
 		it->Show();
	}	
	 
	 
	ofstream ff("2.txt");
	for(auto c:q){
		if(c.y<0.5*c.x+5 && c.y<3*c.x )
			c.s="Area 1";
		if(c.y<3*c.x && c.y<-0.8*c.x+7.6 && c.y<-2*c.x+16)	
			c.s="Area 2";
		if(c.y>-2*c.x+16 && c.y<5/3*c.x-29/3)
			c.s="Area 3";
		if(c.y>-0.8*c.x+7.6 && c.y>5/3*c.x-29/3)
			c.s="Area 4";		
		ff<<c.s<<"\n";	
	}
	
	
	
	
		
		
}
