#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;
int main(){
	ifstream f("2.txt");
	string s;
	int a,b;
	f>>a>>b;
	
//	while(std::getline(ifs, tmp_str))
//        vec_lines.push_back(std::istringstream(tmp_str));
//
//    
//    for(vector<std::istringstream>::iterator itr = vec_lines.begin(); itr != vec_lines.end(); ++itr)
//        std::copy(std::istream_iterator<std::string>(*itr), std::istream_iterator<std::string>(), std::back_inserter(words));
        
	vector<int>letter;
	copy(istream_iterator<int>(f), istream_iterator<int>(), back_inserter(letter));
	for(auto c:letter)
		s+=char((c-b)/a);

	cout<<s;

	ofstream ff("2.txt");
	ff<<s;
	ff.close();
}
