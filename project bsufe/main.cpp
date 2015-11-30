#include <fstream>
#include <time.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

ofstream f("1.txt");

tm a;

//void write(int t){
//	f<<a.tm_hour<<" "<<a.tm_min<<" "<<a.tm_sec<<" "<<t<<" "<<a.tm_hour*3600+a.tm_min*60+a.tm_sec<<"\n";	
//	a.tm_sec++;
//	if(a.tm_sec>59){
//		a.tm_sec=0;
//		a.tm_min++;
//	}
//	if(a.tm_min>59){
//		a.tm_min=0;
//		a.tm_hour++;
//	}		
//}

ofstream h("h.txt"),m("m.txt"),s("s.txt"),tt("t.txt");
void write(int t){
	h<<a.tm_hour<<"\n";
	m<<a.tm_min<<"\n";
	s<<a.tm_sec<<"\n";
	tt<<t<<"\n";
	a.tm_sec++;
	if(a.tm_sec>59){
		a.tm_sec=0;
		a.tm_min++;
	}
	if(a.tm_min>59){
		a.tm_min=0;
		a.tm_hour++;
	}	
}

ifstream ff("1.txt");

int main(){
	srand(time(NULL));
	int t=rand()%15,q;
	for(int i=0;i<10000;++i){		
		write(t);		
		q=rand()%3;
		switch(q){
			case 0: t++;break;
			case 1: t--;break;
			case 2:     break;
		}		
	}
	f.close();
	
}
