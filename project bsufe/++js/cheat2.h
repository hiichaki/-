#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <math.h>
#include <fstream>

///////////////////delLast
#include <fcntl.h>
#include <sys/stat.h>
//////////////////

using namespace std;

template<class qwe,class asd> void q(qwe a,asd b){
	cout<<a+b;
}

enum ConsoleColor{
	Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Magenta       = 5,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    LightMagenta  = 13,
    Yellow        = 14,
    White         = 15
};
// 7,0 default

void setColor(int text=7, int background=0){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void delLast(const char file[],long l){ //del l last symbols in file
	long size;
	ifstream f(file);
	f.seekg (0,ios::end);
	size = f.tellg();	
	f.close();
	int q;
	q=open(file, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
	chsize(q,size-l); 
	close(q);
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

template <typename T, size_t N> size_t arraySize(const T (&)[N]){ 
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

template<class qwe> bool isOdd(qwe a){
	string q=to_string(a);
	char qq=q[q.size()-1];
	int aa = qq - '0';
	if(aa%2==0)
		return 0;
	else
		return 1;
}

bool isOdd(string q){
	char qq=q[q.size()-1];
	int aa = qq - '0';
	if(aa%2==0)
		return 0;
	else
		return 1;
}

template<class qwe> bool isEven(qwe a){
	string q=to_string(a);
	char qq=q[q.size()-1];
	int aa = qq - '0';
	if(aa%2==0)
		return 1;
	else
		return 0;
}

bool isEven(string q){
	char qq=q[q.size()-1];
	int aa = qq - '0';
	if(aa%2==0)
		return 1;
	else
		return 0;
}

/////sort.begin//////
template<typename T>
void selection_sort(T array[], size_t size){
    for (size_t idx_i = 0; idx_i < size - 1; idx_i++){
        size_t min_idx = idx_i;
        for (size_t idx_j = idx_i + 1; idx_j < size; idx_j++){
            if (array[idx_j] < array[min_idx])
               min_idx = idx_j;    
    	}
        if (min_idx != idx_i)
            swap(array[idx_i], array[min_idx]);
    }
}

template <typename T>
void shell_sort(T *A, unsigned N){
	unsigned i,j,k;
	T t;
	for(k = N/2; k > 0; k /=2)
        for(i = k; i < N; i+=1){
            t = A[i];
            for(j = i; j>=k; j-=k){
                if(t < A[j-k])
                    A[j] = A[j-k];
                else
                    break;
            }
            A[j] = t;
        }
}

template <typename T>
void bubble_sort(T *a, size_t n){
	for(int i=0; i<n; ++i)
    	for(int j=i+1; j<n; ++j)
 	   		if(a[j]<a[i])
				swap(a[i],a[j]);
}

template<typename T>
void insertion_sort(T* arr,size_t n){
	for(int i=1;i<n;i++){
		for(int j=i; j>0 && arr[j-1]>arr[j];j--){
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;
		}
	}
}

/////sort.end//////




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

void imperor(){
	int a = 750; 
 
     Beep(392, a); 
     Beep(392, a); 
     Beep(392, a); 
     Beep(311, a*0.75); 
     Beep(466, a*0.25); 
 
     Beep(392, a); 
     Beep(311, a*0.75); 
     Beep(466, a*0.25); 
     Beep(392, a*2); 
 
     Beep(587, a); 
     Beep(587, a); 
     Beep(587, a); 
     Beep(622, a*0.75); 
     Beep(466, a*0.25); 
 
     Beep(369, a); 
     Beep(311, a*0.75); 
     Beep(466, a*0.25); 
     Beep(392, a*2); 
}

void showw(string name,string a){
	cout<<"                  .-\"\"\"-.\n"
		<<"                 / .===. \\ \n" 
		<<"                 \\/ 6 6 \\/ \n"
		<<"                 ( \\___/ )\n"
		<<"  ___________ooo__\\_____/__________________\n"
		<<" /                                          \\\n"
		<<"|                                            |\n"
		<<"|";
	for(int i=0;i<15-name.length();++i)
		cout<<" ";	
	cout<<name<<":"<<a;
	for(int i=0;i<28-a.length();++i)
		cout<<" ";
    cout<<"|\n"
		<<"|                                            |\n"
		<<"|                                            |\n"
		<<" \\__________________________ooo_____________/\n"
		<<"                 |   |   |\n"
		<<"                 |_  |_  |\n"
		<<"                 |   |   |\n"
		<<"                 |___|___|\n"
		<<"                  /- Y -\\_\n"
		<<"                 (__/ _\\__)\n";
		
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




template<class qwe>
class list1{
	qwe val;
	list1 *next;
	public:
		
		list1(){
			next=NULL;
			val=0;
		}
		
		list1(qwe a){
			next=NULL;
			val=a;
		}
		
		~list1(){

		}
		
		void push_back(qwe a){
			list1 *p=this;
			while(p->next!=NULL)
				p=p->next;
			p->next = new list1();	
			p=p->next;
			p->val=a;	
		}	

		void ins(qwe a, int n=0){
			qwe tmp1,tmp2,t3;
			list1 *p=this;
			tmp2=a;
			while(p->next!=NULL)
				p=p->next;
			t3=p->val;
			p->next = new list1();
			p=p->next;
			p->val=t3;
			p=this;
			for(int i=0;i<n;++i)
				p=p->next;
				
			while(p->next!=NULL){
				tmp1=p->val;
				p->val=tmp2;
				tmp2=tmp1;
				p=p->next;	
			}	
		}
		
		void push_front(qwe a){
			ins(a);
		}
		
		void insert(int n,qwe a){
			ins(a,n);	
		}
				
		void show(){
		  list1* p=this;
		  while (p!=NULL){
		    cout<<p->val<<" ";
		    p=p->next;
		  }
		  cout<<"\n";
		}
	
		void remove(qwe a){
			list1 *p=this;
			while(p->next!=NULL){
				if(p->val==a){
					list1 *d=p;
					while(d->next!=NULL){
						d->val=(d->next)->val;
						d=d->next;
					}
					list1 *t=p;
					while((t->next)->next!=NULL)
						t=t->next;
					t->next=NULL;	
					delete(d);
				}	
				else	
					p=p->next;
			}		
			if(p->val==a)	
				pop_back();
		}
		
		void pop_front(){
			list1 *d=this;
			while(d->next!=NULL){
				d->val=(d->next)->val;
				d=d->next;
			}
			list1 *t=this;
			while((t->next)->next!=NULL)
				t=t->next;
			t->next=NULL;	
			delete(d);
		}
		
		void pop_back(){
			list1 *d=this;
			while(d->next!=NULL)
				d=d->next;
			list1 *t=this;
			while((t->next)->next!=NULL)
				t=t->next;
			t->next=NULL;	
			delete(d);
		}
		
		void clear(){
			val=0;
			next=NULL;
		}
		
		void insert_after(qwe a,qwe b){
			list1 *p=this;
			int i=0;
			while(p->next!=NULL){
				i++;
				if(p->val==a){
					insert(i,b);
				}
				p=p->next;
			}
			if(a==p->val)
				push_back(b);
		}
		
		void insert_before(qwe a,qwe b){
			list1 *p=this;
			int i=0,q;
			if(a==p->val)
				push_front(b);
			else{
				while(p!=NULL){
					i++;
					if(p->val==a)
						q=i-1;
					p=p->next;
				}		
				insert(q,b);
			}
		}
	
		qwe max(){
		  bool f=0;
		  qwe max;
		  list1* p=this;
		  list1* prevp;
		  while(p!=NULL){	  
		    if(!f){	    
		      max=p->val;
		      f=1;
		    }     
		    else	    
		     if(p->val>max)
		      max=p->val;		    
		    p=p->next;    
		  }
			return max;
		}
		
		qwe min(){
		  bool f=0;
		  qwe min;
		  list1* p=this;
		  list1* prevp;
		  while(p!=NULL){	  
		    if(!f){	    
		      min=p->val;
		      f=1;
		    }     
		    else	    
		     if(p->val<min)
		      min=p->val;		    
		    p=p->next;    
		  }
			return min;
		}
		
		qwe sum(){
			qwe sum=0;
			list1 *p=this;
			while(p!=NULL){
				sum+=p->val;
				p=p->next;
			}
			return sum;	
		}	
		
		qwe count(){
			list1 *p=this;
			int i=0;
			while(p->next!=NULL){
				i++;
				p=p->next;
			}
			return i;
		}

		qwe avg(){
			return sum()/(count()+1);	
		}	
		
		qwe get_val(){
			return val;
		}
		
		list1* get_next(){
			return next;
		}
		
		template <typename azaza> void remove_if(azaza pred){
			list1 *p=this;
			while(p->next!=NULL){
				if(pred(p->val))
					remove(p->val);
				p=p->next;
			}
			cout<<p->val<<"\n";
			if(pred(p->val))
				pop_back();
		}
	
		qwe operator[](int n){
			list1 *p=this;
			for(int i=0;i<n;++i)
				p=p->next;
			return p->val;	
		}
};





