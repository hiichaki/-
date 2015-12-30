#include <windows.h>
#include <iostream>
 
int main(){
	
	int i=0;
	
	SetTimer(NULL,1,1000,NULL);
	MSG Msg;
	while(GetMessage(&Msg,NULL,0,0)){	
		if(Msg.message==WM_TIMER)
			std::cout<<i<<"\n";
		++i;
	}
	
	
}
