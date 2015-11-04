#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cheat2.h"
#define n 10
using namespace std;
int main(){
  srand(time(NULL));
 
  char a[n][n];

  for(int i=0;i<n;++i)
  	for(int j=0;j<n;++j){
  		a[i][j]='0';
  		if( rand()%10 > 7){
  			a[i][j]=1;
  			if((i-1)>=0){
  				a[i-1][j]++;	
  				if((j-1)>=0)
  					a[i-1][j-1]++;	  			
				if((j+1)<n)
  					a[i-1][j+1]++;	  			
			}
			if((i+1)<n){
				a[i+1][j]++;	
				if((j-1)>=0)
					a[i+1][j-1]++;
				if((j+1)<n)
					a[i+1][j+1]++;				
			}	
		}
	}
  	
  View(a);	
  
    
 
  
  
  
  
  
  	
	  		
}
