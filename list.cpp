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

void delListt(Listt* front){
  if (front!=NULL){
    delListt(front->next);
    delete front;
  }
}

bool search(Listt* front, int q){
  Listt *iter; 
  iter=front;
  while (iter!=NULL){
    if (q==iter->Data) 
      return true; 
    else 
      iter=iter->next;
  }
  return false;
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

int sum(Listt *front,int n){
	int sum=0;
	for(int i=0;i<n;++i){
		sum+=front->Data;
		cout<<*front<<" ";	
		front=front->next;	
	}
	return sum;
		
}
int main(){
	Listt *front; 
	Listt *cur; 
	create(3,&front);
	show(front);
	cout<<r(front,3);

}



