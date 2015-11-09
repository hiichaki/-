#include <iostream>

using namespace std;

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
};

int main(){
	list1<int> li;
}
