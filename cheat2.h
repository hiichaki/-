#include <iostream>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <math.h>
using namespace std;

 template<class qwe,class asd> void q(qwe a,asd b){
	cout<<a+b;
 }

 template<class qwe> void View(vector<qwe> v){
 	 typename vector<qwe> ::iterator iter=v.begin();
	 while(iter!=v.end()){
	 		cout<<*iter<<" ";
	 		iter++;
	 }
 	 cout<<endl;
 } 

 template<class qwe> void View(vector<vector<qwe> >v){
 	typename vector<vector<qwe>>::iterator iter1=v.begin();
		while(iter1!=v.end()){
			typename vector<qwe>::iterator iter2;
			iter2=(*iter1).begin();
				while(iter2!=(*iter1).end()){
			  		cout<<*iter2<<" ";
			  		iter2++;
				}
			cout<<endl;
			iter1++;
		}		
}

template<class qwe> void View(vector<vector<vector<qwe> > > v){
	typename vector<vector<vector<qwe>>>::iterator iter1=v.begin();	
		while(iter1!=v.end()){
			typename vector<vector<int>>::iterator iter2=(*iter1).begin();
			  while(iter2!=(*iter1).end()){
			  	 typename vector<int>::iterator iter3=(*iter2).begin();	 
			  		while(iter3!=(*iter2).end()){
			  		  cout<<*iter3<<" ";
					  iter3++;		
					}				
			  	iter2++;
			  	cout<<endl;
			  }
			iter1++;
			cout<<endl;
		}
	}

template<class qwe> void View(vector<vector<vector<vector<qwe> > > >v){
	typename vector<vector<vector<vector<qwe>>>>::iterator iter1=v.begin();	
		while(iter1!=v.end()){
			typename vector<vector<vector<qwe>>>::iterator iter2=(*iter1).begin();
			  while(iter2!=(*iter1).end()){
			  	 typename vector<vector<qwe>>::iterator iter3=(*iter2).begin();	 
			  		while(iter3!=(*iter2).end()){
			  			typename vector<int>::iterator iter4=(*iter3).begin();	 
			  			while(iter4!=(*iter3).end()){
			  		 		 cout<<*iter4<<" ";
							  iter4++;		
						}	
						iter3++;
			  			cout<<endl;			
					}				
			  	iter2++;
			  	cout<<endl;
			  }
			iter1++;
			cout<<endl;
		}
}	

template<class qwe> void View(vector<vector<vector<vector<vector<qwe> > > > > v){
	typename vector<vector<vector<vector<vector<qwe>>>>>::iterator iter1=v.begin();
		while(iter1!=v.end()){
			typename vector<vector<vector<vector<qwe>>>>::iterator iter2=(*iter1).begin();
			 while(iter2!=(*iter1).end()){
			 	typename vector<vector<vector<qwe>>>::iterator iter3=(*iter2).begin();
			 		while(iter3!=(*iter2).end()){
			 			typename vector<vector<qwe>>::iterator iter4=(*iter3).begin();
			 			 while(iter4!=(*iter3).end()){
			 			 	typename vector<qwe>::iterator iter5=(*iter4).begin();
			 			 	 while(iter5!=(*iter4).end()){
			 			 	 	cout<<*iter5<<" ";
			 			 	 	iter5++;
			 			 	}
			 			 	iter4++;
			 			 	cout<<endl;
			 			 }
			 			 iter3++;
			 			 cout<<endl;
			 		}
			 		iter2++;
			 		cout<<endl;
			}
			iter1++;
			cout<<endl; 
		}
}

template<class qwe,size_t N> void View(qwe (&a)[N]) { 
	for(int i=0;i<N;++i)
	 cout<<a[i]<<" ";
}

template<class qwe,size_t N,size_t M> void View(qwe (&a)[N][M]) { 
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j)
	 		cout<<a[i][j]<<" ";
	 	cout<<endl;	
	}
}

template <typename T, size_t N> size_t ArraySize(const T (&)[N]){ 
 return N; 
}

template <class qwe, size_t N> double avg(qwe (&a)[N]){
	double sum=0;
	for (int i=0;i<N;++i)
			sum+=a[i];
	return sum/N;	
} 

template <class qwe, size_t N> double avggeom(qwe (&a)[N]){
	double sum=1;
	for (int i=0;i<N;++i)
			sum*=a[i];
	return pow(sum,1/N);	
} 

int reverse(int a){ 
	int sign=1,res=0;
		if(a<0) 
			sign=-1;
	a=abs(a);
	int aa=a; 
	    while(aa>0){
	 	  	res=res*10+aa%10;
				 aa/=10;
		}
	return res*sign;
}

unsigned long long fact(int n){
	return n==0?1:(n*fact(n-1));
}
/* fail
unsigned long long fibo(int n){        
    return (n<2)?1:fibo(n-1)+fibo(n-2);
}
*/
unsigned long long fibo(int n){
   unsigned long long u =1, v = 1;
    for (int i = 0; i < n; ++i){    
        unsigned long long w = u + v;
        u = v; v = w;
    }
    return u;
}

void showFibo(int n){
   unsigned long long u =1, v = 1;
    for (int i = 0; i < n; ++i){    
    	cout<<i<<" "<<u<<"\n";
        unsigned long long w = u + v;
        u = v; v = w;
    }
}

template <class qwe, size_t N> double sum(qwe (&a)[N]){
	qwe x=0;
		for(int i=0;i<N;++i)
			x+=a[i];
	return x;
}

template <class qwe, size_t N> double mult(qwe (&a)[N]){
	qwe x=1;
		for(int i=0;i<N;++i)
			x*=a[i];
	return x;
}

bool neg(double arg){
	char *p=(char*) malloc(20);
	sprintf(p,"%f",arg);
	return p[0]=='-';
}

double abss(double a){
		return neg(a)?a*-1:a;
}




void DEMACIA(){ 
			for(int i=0;i<30;++i){
				for(int j=0;j<7;++j)
					cout<<"DEMACIA!!! ";
				cout<<endl;
			}	
}	

void timer(int hour,int min,int sec){
	while(true){
			cout.fill('0'); //чем заполнит пустое пространство
			system("cls");
		 	cout.width(2); //сколько символов будет выводится
			cout<<hour<<":";
			cout.width(2);
			cout<<min<<":";
			cout.width(2);
			cout<<sec;
			Sleep(970);
				 
			if(sec>0)
			    sec--;
				else if(sec==0&&min>0){
				    sec=59;
				    min--;
				}

				else if(sec==0&&min==0&&hour>0){
				    sec=59;
				    min=59;
				    hour--;
				}

				else if(sec==0&&min==0&&hour==0){
				    cout<<endl<<"finished"<<endl;
				    break;
		        }

			}
}	

void timer(){
	int sec,min,hour;
		cout<<"seconds:";
		cin>>sec;
			cout<<endl;
		cout<<"minutes:";
		cin>>min;
			cout<<endl;
		cout<<"hours:";
		cin>>hour;
			cout<<endl;
			
		timer(hour,min,sec);
}		

void tudu(){
  Beep (659.26,200);
  Sleep (10);
  Beep (622.26,200);
  Sleep (10);
 
  Beep (659.26,200);
  Sleep (10);
  Beep (622.26,200);
  Sleep (10);
  Beep (659.26,200);
  Beep (493.88,200);
 
  Beep (587.34,200);
  Beep (440,200);
  Sleep (50);
 
  Beep (261.63,200);
  Beep (329.63,200);
  Beep (440,200);
  Sleep (10);
  Beep (493.88,200);
  Sleep (10);
  Beep (329.63,200);
  Beep (391.99,200);
  Beep (493.88,200);
  Beep (261.63,200);
}

void lk(){
	Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(497, 500);
    Sleep(500);
    Beep(497, 500);
    Beep(277, 500);
    Beep(277, 500);
    Beep(440, 500);
    Beep(440, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);    
}


class Qwe{
	
	public:
		int a,b,*arr;
		Qwe(){
			a=1;
		}
		
	friend ostream& operator<<(ostream& os, const Qwe& a){
		os<<a.a<<" "<<a.b;
    	return os;
	}
	friend istream& operator>>(istream& is, Qwe& a){
	    is>>a.a>>a.b;
	    return is;
	}
	friend bool operator==(Qwe a,Qwe b){
		return a.a==b.a;
	}
	friend bool operator>(Qwe a,Qwe b){
		return a.a>b.a;
	}
	friend bool operator<(Qwe a,Qwe b){
		return a.a<b.a;
	}
	friend bool operator!=(Qwe a,Qwe b){
		return a.a!=b.a;
	}
	friend bool operator>=(Qwe a,Qwe b){
		return !(a<b);
	}
	friend bool operator<=(Qwe a,Qwe b){
		return !(a>b);
	}
	void operator++(int qq){
		 a++;
	}
	void operator++(){
		 ++a;
	}
	void operator--(int qq){
		 a--;
	}
	void operator--(){
		 --a;
	}
	friend Qwe operator+(Qwe a, Qwe b){
		a.a+=b.a;
		return a;
	}
	friend Qwe operator-(Qwe a, Qwe b){
		a.a-=b.a;
		return a;
	}
	friend Qwe operator*(Qwe a, Qwe b){
		a.a*=b.a;
		return a;
	}
	friend Qwe operator/(Qwe a, Qwe b){
		a.a/=b.a;
		return a;
	}
	void operator+=(Qwe b){
		this->a+=b.a;
	}
	void operator-=(Qwe b){
		this->a-=b.a;
	}
	void operator*=(Qwe b){
		this->a*=b.a;
	}
	void operator/=(Qwe b){
		this->a/=b.a;
	}
	int& operator[] (int i){
		return arr[i];
	} 
    int operator() (int i){
		return arr[i]*i;
	}
};











