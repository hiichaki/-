#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "cheat2.h"
#include <fstream>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>
using namespace std;

void urez(long l){//l-размер файла
int q;
q=open("file.js", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
chsize(q,l-3); //1 - 1 символ будет вырезан с конца
close(q);
}

int main(){
	long size;
	ofstream f("file.js");
	SYSTEMTIME systime;
		GetLocalTime(&systime);
		f<<"f([[Date.UTC("<<systime.wYear<<","<<systime.wMonth<<","<<systime.wDay<<","<<systime.wHour<<","<<systime.wMinute<<","<<systime.wSecond<<"),"<<rand()<<"]\n]);";	
	f.close();
	
	while(1){		
		ifstream ff("file.js");
		ff.seekg (0,ios::end);
		size = ff.tellg();	
		urez(size);
		ff.close();
		ofstream fff("file.js",ios::app);
		GetLocalTime(&systime);
		fff<<",[Date.UTC("<<systime.wYear<<","<<systime.wMonth<<","<<systime.wDay<<","<<systime.wHour<<","<<systime.wMinute<<","<<systime.wSecond<<"),"<<rand()<<"]\n]);";	
		fff.close();
		timer(0,0,10);	
		
	}
	
}
