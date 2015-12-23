#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	bool ids[n]; 
	vector<int> even,odd;
	for(int i=0; i<n; i++){
		a[i]=rand()%15;
		cout<<a[i]<<" ";
		if(a[i]%2 == 0) {
			even.push_back(a[i]);
			ids[i]=true;
		} else {
			odd.push_back(a[i]);
			ids[i]=false;
		}
	}
	cout<<"\n";
	
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	reverse(even.begin(), even.end());
	
	for(int i=0; i<n; i++){
		int x;
		if(ids[i]){
			x = *even.begin();
			even.erase(even.begin());
		} else {
			x = *odd.begin();
			odd.erase(odd.begin());
		}
		a[i] = x;
		cout<<a[i]<<" ";
	}
}
	
