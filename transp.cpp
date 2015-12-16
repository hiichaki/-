#include <iostream>
#include <algorithm>
#define n 3
using namespace std;

class Transp{
	int a[n][n]={{5,3,1},{2,4,1},{3,3,2}},
		z[n]={100,130,220},
		p[n]={210,100,140},
		zp[n][n];
	int sum;
	
	public:
		
	Transp(){
		sum=0;		
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				zp[i][j]=0;
	}
	
	void showA(){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				cout<<a[i][j]<<" ";
			cout<<"\n";		
		}
	}	
	
	void showZP(){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				cout<<zp[i][j]<<" ";
			cout<<"\n";		
		}
	}
	
	void showSum(){
		cout<<"\nsum:"<<sum<<"\n";
	}
	
	void calc(){
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				if(p[j]>=z[i]) {
	                zp[i][j]=z[i];
	                p[j]=p[j]-z[i];
	                z[i]=0;
	            }
	            if(p[j]<z[i]){
	                z[i]=z[i]-p[j];
	                zp[i][j]=p[j];
	                p[j]=0;
	            }
	            sum+=zp[i][j]*a[i][j];   
			}
	}
	
//	void calc2(){
//		int q,j=0;
//		for(int i=0;i<n;++i){
//			q=min(z[i],p[j]);
//				
//		}
//			
//	}
	
	
};

int main(){
	Transp q;
	q.calc();
	q.showZP();
	q.showSum();
}
