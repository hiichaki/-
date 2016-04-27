#include <iostream>
#include "cheat2.h"
#include <algorithm>
#include <conio.h>
using namespace std;

int main(){
	string s;
	int a=75;
	int i=1;
	bool flag=false;
	while(!flag)
	{
		s=to_string(i*a);
		cout<<s<<endl;
		bool flag2=true;
		for(int j=1; j<s.length(); j++)
		{
			if(s[j]!='0')
			{
				flag2=false;
			}
		}
		if(flag2)
		{
			flag=true;
		}
		i++;
	}
	getch();
	return 0;
}

