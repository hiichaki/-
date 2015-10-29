#include <iostream>
#include <algorithm>
#include "cheat2.h"
using namespace std;

class Cell{
	int a;
	public:	
	int possible[9];
	
		Cell(){
			for(int i=0;i<9;++i)
				possible[i]=i+1;
			a=0;	
		
		}
		void removePossible(int j){
			possible[j-1]=0;
		}
		
		void operator=(int _a){
			a=_a;
		}
		int operator-(int _a){
			a-=_a;
			return a;	
		}
		
		int geta(){return a;}
		
		friend bool operator<(Cell a, int b);
		friend bool operator==(Cell a, int b);
		
		friend ostream& operator<<(ostream& stream,Cell _a){
		   cout<<_a.a;	
		   return stream;
		}
};
	bool operator<(Cell a,int b){
		return a.geta()<b?1:0;
	}
	bool operator<(int b,Cell a){
		return a.geta()<b?1:0;
	}
	
	bool operator==(Cell a,int b){
		return a.geta()==b?1:0;
	}

class sudoku {
	Cell a[9][9];
	public:

		sudoku(){			
			int aa[9][9]={
					 {1,0,2,3,0,6,9,7,8},
					 {1,2,3,4,4,6,8,7,9},
					 {1,2,3,4,4,6,8,7,9},
					 {1,2,3,4,4,6,8,7,9},
					 {1,2,3,4,4,6,8,7,9},
		 			 {1,2,3,4,4,6,8,7,9},
					 {1,2,3,4,4,6,8,7,9},
					 {1,2,3,4,4,6,8,7,9},
					 {1,2,3,4,4,6,8,7,9}
					 };			 
		
			for(int i=0;i<9;++i)
				for(int j=0;j<9;++j)
					a[i][j]=aa[i][j];
			}
		
		bool search_(int i, int z){
			for(int j=0;j<9;++j)
				return a[i][j]==z?1:0;
		}
		
		void ch(){
//			for(int i=0;i<9;++i)
//				for(int j=1;j<10;++j)
					if(search_(0,4)) 
						for(int z=0;z<9;++z)
							a[0][z].removePossible(4);				
		}

		
		void checkSquare(){
			
		}	
			
		void show(){
			for(int i=0;i<9;++i){
				for(int j=0;j<9;++j)	
					cout<<a[i][j]<<" ";
				cout<<endl;	
			}
			cout<<endl;	
		}

		void test(){
				for(int j=0;j<9;++j){
					for(int i=0;i<9;++i)
						cout<<"x:"<<1<<" y:"<<j+1<<" pos:"<<a[0][j].possible[i]<<"\n";
				cout<<"\n";		
				}
		}
};





int main(){
	sudoku q;
	q.show();
//	q.test();
//	q.checkRowCol();
	q.ch();
	q.test();
	
}
