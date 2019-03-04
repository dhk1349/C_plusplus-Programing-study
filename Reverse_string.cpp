#include<iostream>
#include<string>
using namespace std;
string reverse(string str);

/*
Reverse string
*/
void main() {
	string blank;
	cout << "Type anything:   ";
	cin >> blank;
	cout<<reverse(blank);
}

string reverse(string str) {
	string temp1;
	string temp2;
	for (int i=0;i<=(str.size())/2;i++) {
		temp1 = str[i];
		temp2 = str[str.size()-i-1];
		str.replace(i,1,temp2);
		str.replace(str.size()-1-i, 1, temp1);	
	 }
	return str;
}
