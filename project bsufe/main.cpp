#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

ofstream f("1.txt");

tm a;

void write(int t){
	f.open("1.txt",ios::app);
	f<<a.tm_hour<<" "<<a.tm_min<<" "<<a.tm_sec<<" "<<t<<" "<<a.tm_hour*3600+a.tm_min*60+a.tm_sec<<"\n";	
	a.tm_sec++;
	if(a.tm_sec>59){
		a.tm_sec=0;
		a.tm_min++;
	}
	if(a.tm_min>59){
		a.tm_min=0;
		a.tm_hour++;
	}		
	f.close();
}

int main(){
	srand(time(NULL));
	int t=rand()%15,q;
	
	SetTimer(NULL,1,1000,NULL);
	MSG Msg;
	
	while(GetMessage(&Msg,NULL,0,0)){	
		if(Msg.message==WM_TIMER){			
			write(t);		
			q=rand()%3;
			switch(q){
				case 0: t++;break;
				case 1: t--;break;
				case 2:     break;
			}	
		}
	}
	f.close();
	
}
