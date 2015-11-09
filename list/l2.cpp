#include <iostream>
using namespace std;

template<class qwe>
class list2{
    
    struct node{
        qwe val;
        node* next;
        node* prev;

    };
    
    node* front;
    public:
        
        list2(){
            front = new node; 
            front->next = NULL;
        }
        
        ~list2(){
            destroy(); 
            delete front;
        }
        
        void push_back(qwe a){
            node* p,*p1;
            p = front;  
            while(p->next != NULL)  
                p = p->next;
         
            p1 = new node; 
            p1->val = a;  
            p1->next = NULL; 
         
            p1->prev = p; 
            p->next = p1; 
        }
         
        void show(){
            node* p;
            p = front->next;
            while(p != NULL){
                cout<<p->val<<" ";
                p = p->next;
            }
            cout<<"\n";
        }
         
        void push_front(qwe a){
            node* p;
            p = new node;
            p->val = a;
            if(front->next == NULL){
                p->next = front->next;
                front->next = p;
                p->prev = front;
            }
            else{
                p->next = front->next;
                front->next->prev = p;
                front->next = p;
                p->prev = front;
            }
        }
         
        void show_reverse(){
            node* p;
            p = front;
            
            while(p->next != NULL)
                p = p->next;
         
            while(p != front){
                cout<<(p->val)<<" ";
                p = p->prev;
            }
        }
         
        void destroy(){
            node* p,* p1;
            p = front;
            p1 = p->next;
            while(p1 != NULL){
                p = p1;
                p1 = p1->next;
                delete p;
            }
        }
         
        void pop_back(){
            node* p,* p1;
            p = front;
            p1 = p->next;
            while(p1->next != NULL){
                p = p1;
                p1 = p1->next;
            }
            p->next = NULL; 
            delete p1; 
        }
         
        void pop_front(){       
            node* p;
            p = front->next;
            front->next = p->next;
            p->next->prev = front;
            delete p;
        }
        
        void insert(int n,qwe a){
            node *p,*p1;
            p = front;
            for(int i=0;i<n;++i)
                p=p->next;
            p1=new node;
            p1->val=a;       	
            p1->next=p->next;
			(p1->next)->prev=p1;
			p->next=p1;
			p1->prev=p;  

        }
          
		void remove(qwe a){
			node *p;
			p=front;
			while(p!=NULL)
			
		}        
};

int main(){
    list2<int>li;
    
    for(int i=0;i<10;++i)
        li.push_back(i+1);
        
    li.insert(3,111);
    li.show();
}




