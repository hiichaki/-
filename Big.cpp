#include <iostream>
#include <algorithm>
using namespace std;

class Big{
	int a[1000];
	int n;
	int sign;
	public:	
		
		Big(){
			n=0;
			sign=1;
			for(int i=0;i<1000;++i)
				a[i]=0;	
		}
		
		Big(string q){
			n=q.size();
			sign=1;
			if(q[0]=='-'){
				sign=-1;
				--n;	
				q.erase(q.begin());
			}
			for(int i=0;i<n;++i){
				char qq=q[i];
				a[i]= qq - '0';
			}
		}
		
		void show(){
			if(sign==string::npos)
				cout<<"-";
			for(int i=0;i<n;++i)
				cout<<a[i];	
			cout<<"\n";
		}
		
		void operator=(string q){
			n=q.size();
			sign=1;
			if(q[0]=='-'){
				sign=-1;
				--n;	
				q.erase(q.begin());
			}
			for(int i=0;i<q.length();++i){
				char qq=q[i];
				a[i]= qq - '0';
			}
		}
		
		void operator=(Big q){
			this->n=q.n;
			this->sign=q.sign;
			
			for(size_t i=0;i<n;++i)
				this->a[i]=q.a[i];
		}
		
		friend bool operator<(Big x,Big y){
			if(x.sign<y.sign)
				return 1;
			if(x.sign>y.sign)	
				return 0;
			if(x.sign==1){
				if(x.n<y.n)
					return 1;
				if(x.n>y.n)	
					return 0;
			} else {
				if(x.n>y.n)
					return 1;
				if(x.n<y.n)	
					return 0;
			}
			for(int i=0;i<x.n;++i){
				if(x.a[i]<y.a[i])
					return 1;	
				if(x.a[i]>y.a[i])
					return 0;		
			}	
			
		}
		
		friend bool operator>(Big x,Big y){
			if(x.sign>y.sign)
				return 1;
			if(x.sign<y.sign)	
				return 0;
			if(x.sign==1){
				if(x.n>y.n)
					return 1;
				if(x.n<y.n)	
					return 0;
			} else {
				if(x.n<y.n)
					return 1;
				if(x.n>y.n)	
					return 0;
			}
			for(int i=0;i<x.n;++i){
				if(x.a[i]>y.a[i])
					return 1;
				if(x.a[i]<y.a[i])
					return 0;				
			}	
			return 0;	
		}
		
		friend Big operator+(Big x,Big y){
			Big c;
			int m;
			
			m=max(x.n,y.n);
			c.n=m;
			
			if(x.sign==-1&&y.sign==1){
				return y-x;
			}
			
			if(x.sign==1&&y.sign==-1){
				return x-y;
			}	
			
			reverse(x.a,x.a+x.n);
			reverse(y.a,y.a+y.n);
		
			for(int i=0;i<m;++i){
				c.a[i]+=x.a[i]+y.a[i];
				if(c.a[i]>9){
					c.a[i+1]++;
					c.a[i]-=10;
					if(i==m-1)
						c.n++;
				}		
			}
			
			if(x.sign==-1&&y.sign==-1){
				c.sign=-1;	
			}
			
			reverse(c.a,c.a+c.n);
			return c;
			
		}
	
		friend Big operator-(Big x,Big y){
			Big c;
			int m;
			
			m=max(x.n,y.n);
			c.n=m;
			
			if(x.sign==-1&&y.sign==1){
				x.sign=1; y.sign=1;
				c=x+y;
				c.sign=-1;
				return c;
			}
			
			if(x.sign==1&&y.sign==-1){
				y.sign=1;
				return x+y;
			}
			
			reverse(x.a,x.a+x.n);
			reverse(y.a,y.a+y.n);
			
			if(x.sign==1&&y.sign==1){
				if(x<y){
					for(int i=0;i<m;++i){
						c.a[i]+=y.a[i]-x.a[i];
						if(c.a[i]<0&&i+1<m){
							c.a[i]+=10;
							c.a[i+1]--;
						}			
					}
					c.sign=-1;
				} else {
					for(int i=0;i<m;++i){
						c.a[i]+=x.a[i]-y.a[i];
						if(c.a[i]<0&&i+1<m){
							c.a[i]+=10;
							c.a[i+1]--;
						}			
					}
				}
				
			}
			
			if(x.sign=-1&&y.sign==-1){
				for(int i=0;i<m;++i){
					c.a[i]+=y.a[i]-x.a[i];
					if(c.a[i]<0){
						c.a[i]+=10;
						c.a[i+1]--;
					}			
				}
			}
			
			reverse(c.a,c.a+c.n);
			return c;
		}
			
		friend Big operator*(Big x,Big y){
			
		}	
};



int main(){
Big a("11111111111111111111111"),b("22222222222222222222222"),c;
a.show();
b.show();
(a-b).show();
}

