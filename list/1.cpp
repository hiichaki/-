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
void show(Listt* front);

void delListt(Listt* front){
  if (front!=NULL){
    delListt(front->next);
    delete front;
  }
}

Listt* del(Listt* front,int n){
  Listt *iter;
  Listt *cur=front;
  for (int i=1;i<n&&cur!=NULL;i++)
    cur=cur->next;
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

Listt* insertt(Listt* front, int n, int in){ 
  n--;
  Listt *newL=new(Listt);
  newL->Data=in; 
  newL->next = NULL;
  if (front == NULL) {
    front = newL;
  }
  else {
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
  }
  show(front);
  return front; 
}

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


int min(Listt *front){
	int min=100;
	for(int i=0;i<3;++i){	
		if(min>front->Data)
			min=front->Data;
		front=front->next;	
	}
	return min;		
			
}

int max(Listt *front){
	int max=0;
	for(int i=0;i<3;++i){	
		if(max<front->Data)
			max=front->Data;
		front=front->next;	
	}
	return max;				
}

int pos(Listt *front){
	int mi=min(front);
	for(int i=0;i<3;++i){
		if(front->Data==mi){
			cout<<"\ni:"<<i;
			return i;
			
		}
		front=front->next;
	}
}

void add(Listt *front){
	int mi,ma;
	mi=min(front);
	ma=max(front);
	cout<<"min:"<<mi;
	cout<<"\nmax:"<<ma<<"\n";
	for(int i=0;i<3;++i){	
		if(front->Data==mi){
			insertt(front->next,2,ma);		
		}
		front=front->next;
	}
}

int main(){
	Listt *front; 
	Listt *cur; 
	create(3,&front);
	
	add(front);
	show(front);
	
	delListt(front);

}



