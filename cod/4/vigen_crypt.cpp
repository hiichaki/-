#include <iostream>
#include <fstream>
using namespace std;

string abc(){
	string s;
	for(int i=97;i<96+27;++i)
		s+=char(i);
	return s;	
}

//void show (char (w)[][26]){
//	  for(int i=0;i<26;++i){
//		for(int j=0;j<26;++j)
//			cout<<w[i][j]<<"";
//		cout<<"\n";
//	}		
//}

int main(){
	const string q=abc();
	int n=q.length();
	char a[n][n];
	int z=0;
	
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){                
            z=j+i;
            if(z>=n) 
				z=z%n;
            a[i][j]=q[z];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
   }

//    char qwe[26][26];			//тупой бред
//    for(int i=0;i<n;i++)		//проверить
//        for(int j=0;j<n;j++)	//просто 'а' не идет в функцию
//        	qwe[i][j]=a[i][j];
//    show(qwe);
    
    string k="encrypting",key="";
    cout<<"key:";
    cin>>k;
    string s;
    ifstream f("1.txt");
    getline(f,s,'\0');
    f.close();
    
//    int i;
//    while((i=s.find(' '))!=string::npos)
//    	s.erase(i,1);
    	
    for(int i=0,z=0;i<s.length();++i,++z){
    	if(z>k.length()-1)
    		z=0;
    	key+=k[z];
	}
	
	int p,w;
	string ss;
	
	for (int i=0; i<s.length(); i++){
        p=q.find(s[i]);
        w=q.find(key[i]);
        ss.insert(i,1,q.at((p+w)%26)); 
    }
    
	ofstream ff("2.txt");
	ff<<ss;
	ff.close();
	cout<<ss;

}
