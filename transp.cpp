#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;

void SetColor(int text, int background){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int qwe(){
	int q;
	cout<<"n:";
	cin>>q;
	return q;
}

int n=qwe();

class Transp{
	int *z = new int [n];
	int *p = new int [n];
	int **a = new int *[n];
	int **aa = new int *[n];
	int **zp = new int *[n];
	
	int sum;
	
	public:
		
	Transp(){
		sum=0;	
		
		for (int i=0; i<n; i++){
        	a[i] = new int [n];
        	aa[i] = new int [n];
        	zp[i] = new int [n];
		}
		
		for(int i=0;i<n;++i){
			z[i]=rand()%250;
			p[i]=rand()%250;
			for(int j=0;j<n;++j){
				a[i][j]=rand()%7;
				aa[i][j]=a[i][j];
				zp[i][j]=0;
			}
		}
	}
	
	void show(){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				SetColor(7,0);
				if(zp[i][j])
					SetColor(10,0);
				cout<<zp[i][j]<<"\t";
			}
			SetColor(12,0);	
			cout<<z[i]<<"\n";	
			SetColor(7,0);
		}
		SetColor(12,0);
		for(int i=0;i<n;++i)
			cout<<p[i]<<"\t";
		cout<<"\n\n";
		SetColor(7,0);
	}
	
	void showZ(){
		for(int i=0;i<n;++i)
			cout<<p[i]<<" ";
	}
	
	void showA(){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				cout<<aa[i][j]<<" ";
			cout<<"\n";		
		}
		cout<<"\n";	
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
	
	void calc2(){	
		for(int q=0;q<n*n;++q){
			int min=100,iz,jp;
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					if(min>a[i][j]&&a[i][j]!=-1){
						min=a[i][j];
						iz=i; jp=j;
					}
			if(p[jp]>=z[iz]) {
	            zp[iz][jp]=z[iz];
	            p[jp]-=z[iz];
	            z[iz]=0;
	        }
	        if(p[jp]<z[iz]){
	            z[iz]-=p[jp];
	            zp[iz][jp]=p[jp];
	            p[jp]=0;
	        }
	        sum+=zp[iz][jp]*a[iz][jp];
			a[iz][jp]=-1;	
		}
	}
};

int main(){
	srand(time(NULL));
	
	Transp q;
	
	string s="mode con cols="+to_string(n*10-n/2);
	const char * c = s.c_str();
	system(c);
	
	q.show();
	q.calc();
	q.showA();
	q.show();
	q.showSum();
}
