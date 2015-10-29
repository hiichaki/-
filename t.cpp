#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	
 double a[n][n],s=1;
 
  for(int i=0;i<n;++i){
  	for(int j=0;j<n;++j){
   		a[i][j]=rand()%10;
   		cout<<a[i][j]<<" ";
	}
	cout<<"\n";
  }
  for(int i=0;i<n;++i){
  	for(int j=0;j<n;++j){
  		if(i==n-j-1)
  			cout<<a[i][j]<<" ";
  	}
 }

  
	  		
}
