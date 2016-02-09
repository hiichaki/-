#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>
using namespace std;

void urez(long l,const char file[]){//l-размер файла
int q;
q=open(file, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
chsize(q,l-3); //1 - 1 символ будет вырезан с конца
close(q);
}

struct T{
	int y,mth,d,h,m,s;
	T(){
		y=2016;
		mth=1;
		d=0;
		h=6;
		m=0;
		s=0;
	}
	void go(){
		s++;
		if(s>59){
			s=0;
			m++;
		}
		if(m>59){
			m=0;
			h++;
		}
		if(h>23){
			h=0;
			d++;
		}
		if(d>31){
			d=0;
			mth++;
		}
		if(mth>12){
			mth=1;
			y++;
		}	
	}
};

int main(){
	srand(time(NULL));
	long size;
	int t1=rand()%15,t2=rand()%15,t3=rand()%15,q1,q2,q3;
	ofstream f("file1.js");
	ofstream ff("file2.js");
	ofstream fff("file3.js");
	
	T systime;

		f<<"f([[Date.UTC("<<systime.y<<","<<systime.mth<<","<<systime.d<<","<<systime.h<<","<<systime.m<<","<<systime.s<<"),"<<t1<<"]\n]);";	
		ff<<"ff([[Date.UTC("<<systime.y<<","<<systime.mth<<","<<systime.d<<","<<systime.h<<","<<systime.m<<","<<systime.s<<"),"<<t2<<"]\n]);";	
		fff<<"fff([[Date.UTC("<<systime.y<<","<<systime.mth<<","<<systime.d<<","<<systime.h<<","<<systime.m<<","<<systime.s<<"),"<<t3<<"]\n]);";	
	f.close();
	ff.close();
	fff.close();
	
	while(systime.h<11){
		q1=rand()%3;
		switch(q1){
			case 0: t1++;break;
			case 1: t1--;break;
			case 2:     break;	
		}
		q2=rand()%3;
		switch(q2){
			case 0: t2++;break;
			case 1: t2--;break;
			case 2:     break;	
		}
		q3=rand()%3;
		switch(q3){
			case 0: t3++;break;
			case 1: t3--;break;
			case 2:     break;	
		}
		
		
		ifstream f1("file1.js");
		f1.seekg (0,ios::end);
		size = f1.tellg();	
		urez(size,"file1.js");
		f1.close();
		
		ifstream f2("file2.js");
		f2.seekg (0,ios::end);
		size = f2.tellg();	
		urez(size,"file2.js");
		f2.close();
		
		ifstream f3("file3.js");
		f3.seekg (0,ios::end);
		size = f3.tellg();	
		urez(size,"file3.js");
		f3.close();
		
		
		ofstream f11("file1.js",ios::app);
		ofstream f22("file2.js",ios::app);
		ofstream f33("file3.js",ios::app);
		for(int i=0;i<rand()%3+9;++i)
			systime.go();
		f11<<",[Date.UTC("<<systime.y<<","<<systime.mth<<","<<systime.d<<","<<systime.h<<","<<systime.m<<","<<systime.s<<"),"<<t1<<"]\n]);";
		f22<<",[Date.UTC("<<systime.y<<","<<systime.mth<<","<<systime.d<<","<<systime.h<<","<<systime.m<<","<<systime.s<<"),"<<t2<<"]\n]);";	
		f33<<",[Date.UTC("<<systime.y<<","<<systime.mth<<","<<systime.d<<","<<systime.h<<","<<systime.m<<","<<systime.s<<"),"<<t3<<"]\n]);";		
		f11.close();

		
	}
	
}
