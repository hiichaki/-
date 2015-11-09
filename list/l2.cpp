#include <iostream>
using namespace std;

template<class qwe>class list2{
    
    struct node{
        qwe val;
        node* next;
        node* prev;

    };
    
    node* head;
    public:
        
        list2(){
            head = new (node); 
            head->next = NULL;
        }
        
        ~list2(){
            destroy(); 
            delete head;
        }
        
        void push_back(qwe a){
            node* p,*p1;
            p = head;  
            while(p->next != NULL)  
                p = p->next;
         
            p1 = new (node); 
            p1->val = a;  
            p1->next = NULL; 
         
            p1->prev = p; 
            p->next = p1; 
        }
         
        void show(){
            node* p;
            p = head->next;
            while(p != NULL){
                cout<<(p->val)<<" ";
                p = p->next;
            }
        }
         
        void push_front(qwe el){
            node* p;
            p = new (node);
            p->val = el;
            if(head->next == NULL){
                p->next = head->next;
                head->next = p;
                p->prev = head;
            }
            else{
                p->next = head->next;
                head->next->prev = p;
                head->next = p;
                p->prev = head;
            }
        }
         
        void show_reverse(){
            node* p;
            p = head;
            
            while(p->next != NULL)
                p = p->next;
         
            while(p != head){
                cout<<(p->val)<<" ";
                p = p->prev;
            }
        }
         
        void destroy(){
            node* p,* p1;
            p = head;
            p1 = p->next;
            while(p1 != NULL){
                p = p1;
                p1 = p1->next;
                delete p;
            }
        }
         
        void pop_back(){
            node* p,* p1;
            p = head;
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
            p = head->next;
            head->next = p->next;
            p->next->prev = head;
            delete p;
        }
        
        
                
};

int main(){
    list2<int>li;
    
    for(int i=0;i<10;++i)
        li.push_back(i+1);
   
}



