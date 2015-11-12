#include <iostream>
#include <stdlib.h>
using namespace std;

struct Listt {
    int Data;
    Listt *next; 
	
	friend ostream& operator<<(ostream& os, const Listt& a){
		os<<a.Data;
    	return os;
	}
};

void create(int n,Listt** front){
  if (n>0){
    (*front) = new Listt();
    for(int i=0;i<n;++i)
    	(*front)->Data=rand()%20;
    (*front)->next=NULL;
    create(n-1,&((*front)->next));
  }
}

void show(Listt* front) {
  if (front != NULL) {
    cout << front->Data<<" ";
    show(front->next);
  }
  else
  cout<<"\n";
}

Listt* add(Listt* front,int in,int n){

  Listt *newL=new(Listt);
  newL->Data=in; 
  newL->next = NULL;	
  Listt *cur=front;
    for(int i=1;i<n&&cur->next!=NULL;i++)
      cur=cur->next;
    if (n==0){
      newL->next = front;
      front = newL;
    }
    else {
      if (cur->next != NULL) 
        newL->next=cur->next;
      cur->next=newL;
    }
  
  return front; 
}

Listt* del(Listt* front,int n){
  Listt *iter;
  Listt *cur=front;
  for (int i=1;i<8&&cur!=NULL;i++){
  	if(cur->Data==n)
  		break;
  	else	
  		cur=cur->next;			
  }
  if (cur!=NULL){
    if (cur==front){
      front=front->next;
      delete(cur);
      cur=front;
    }
    else {
      iter=front;
      while(iter->next != cur)
        iter=iter->next; 
      iter->next=cur->next;
      delete(cur);
      cur=iter;
    }
  }
  return front;
}

Listt* del_front(Listt* front){
	Listt* cur = front;
	if (cur==front){
	      front=front->next;
	      delete(cur);
	      cur=front;
	    }
	return front;
}

Listt* del_back(Listt* front){
 	Listt* iter=front;
 	Listt *cur=front;
 	for(int i=0;i<5;++i)
 		cur=cur->next;
      while(iter->next != cur)
        iter=iter->next; 
      iter->next=cur->next;
      delete(cur);
      return front;
}

int sum(Listt *front,int n){
	int sum=0;
	for(int i=0;i<n;++i){
		sum+=front->Data;
		cout<<*front<<" ";	
		front=front->next;	
	}
	return sum;	
}

int avg(Listt *front,int n){
	int avg;
	return sum(front,n)/n;
}

void delListt(Listt* front){
  if (front!=NULL){
    delListt(front->next);
    delete front;
  }
}

int main(){
	Listt* li;
	create(5,&li);
	show(li);
	add(li,55,6);
	show(li);
	add(li,23,1);
	show(li);
	li=del_front(li);
	show(li);
	li=del_back(li);
	show(li);
	
}
