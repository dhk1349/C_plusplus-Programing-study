#include<iostream>
#include<string>
#include<fstream>
using namespace std;
string even(int a);
string weather(int a);
void weather_forecast(ofstream& write, string a, int b, int c);

void main() {
	int a;
	cin >> a;
	ofstream write;
	write.open("out_date.txt");
	if (!write) {
		cerr << "cannot write file!" << endl;
		exit(102);
	}
	string b="no";
	int c=0;
	int d=0;
	for (int i = 1;i<=a;i++) {
		cin >> b>> c>> d;
		weather_forecast(write, b, c, d);
	}
	write.close();
}

void weather_forecast(ofstream& write, string a, int b, int c) {
	write << "today is " << a << " this is " << even(b) << " day and the weather is " << weather(c) << endl;
}
string even(int a) {
	if (a%2==0) {
		return "even";
	}
	else { return "odd"; }
}
string weather(int a) {
	if(a==1){
		return "rainy";
	}
	else if (a == 0) {
		return "sunny";
	}
	else if (a == 2) {
		return "cloudy";
	}
}