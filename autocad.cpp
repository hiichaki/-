#include <iostream>
#include <fstream>
#include "cheat2.h"
using namespace std;
int main(){
	int a[]={0,0,0,100,200,100,200,200,500,200,500,700,800,700,800,300,900,300,900,400,1600,400,1600,0,1400,-200,1100,-200,1100,0};
	View(a);
	string s;
	string com="\"_dimlinear\" \"";
	string q=" \"300\"";
	cout<<"\n";
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n-2;i+=2)
		s+="(command "+com+to_string(a[i])+","+to_string(a[i+1])+"\" \""+to_string(a[i+2])+","+to_string(a[i+3])+"\""+q+")\n";
	ofstream f("1.txt");
	f<<s;	 		
}
