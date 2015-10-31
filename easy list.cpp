#include <iostream>
#include <list>
using namespace std;
typedef list<int> LISTINT;
int main(void)
 {
   LISTINT listOne;
   LISTINT::iterator i;
   listOne.push_front (2);
   listOne.push_front (1);
   listOne.push_back (3);
   for (i = listOne.begin(); i != listOne.end(); ++i)
     cout << *i << " ";
   cout << endl;
   for (i = listOne.end(); i != listOne.begin(); --i)
     cout << *i << " ";
   cout << endl;
 }
