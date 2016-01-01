#include <iostream>
#include <cstring>
#include <set> 
using namespace std;
int main(){
    int shift=0, temp, firstNumVal, numVal, sizeRez, countNum;
    string firstNum, secondNum;
    cout<< "Enter first number: ";  cin>> firstNum ;
    cout<< "Enter first number: ";  cin>> secondNum ;
    sizeRez=firstNum.length()+secondNum.length();
    int* product = new int  [sizeRez];
    
//  // temp
//  firstNum="0";
//  secondNum="123"; sizeRez=6;
//  int* product = new int  [sizeRez];
    memset(product, 0, sizeRez*sizeof(int));
 
    for (int f=firstNum.length(); --f>=0;)
    {
        firstNumVal=firstNum[f]-'0';
        countNum=shift;
        for (int s=secondNum.length(); --s>=0;)
        {           
            numVal=firstNumVal*(secondNum[s]-'0');
            product[countNum]    += numVal%10;
            if (product[countNum]>=10) 
                {product[countNum]-=10; ++product[countNum+1];}
            product[countNum+1]  += numVal/10;
            if (product[countNum+1]>=10) 
                {product[countNum+1]-=10;; ++product[countNum+2];}
            ++countNum;
        }
        ++shift;
    }
 
    for (int i=sizeRez; --i>=0;)
        cout<<product[i];
    cout<<endl; system("pause");
    return 0;
}
