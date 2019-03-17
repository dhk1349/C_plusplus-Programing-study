#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool read(ifstream& getdata, float& line);
void high(float a, float& hi);
void low(float a, float& lo);

void main() {
	ifstream getdata;
	getdata.open("hopedale.txt");
	if (!getdata) {
		cerr << "cannot open file";
		exit(100);
	}
	float hi, lo;
	float avg,count;
	float data;
	read(getdata, data);
	count = 1;
	hi = data, lo = data;
	avg = data;	
	while (read(getdata, data)) {
		count += 1;
		avg += data;
		high(data, hi);
		low(data, lo);
	}
	avg /= count;
	cout << "Lowest hopedale number:  " << lo << endl;
	cout << "highest hopedale number:  " << hi << endl;
	cout << "Average hopedale number:  " << avg << endl;
	getdata.close();
}

bool read(ifstream& getdata, float& line) {
	getdata >> line;
	if (!getdata) {
		return false;
	}
	return true;
}
void high(float a, float& hi){
	if (a>hi) {
		hi = a;
	}
}
void low(float a, float& lo) {
	if (a<lo) {
		lo = a;
	}
}