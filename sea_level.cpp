#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
/*
원래 sealeveltxt에서 missing variable까지 고려해서 스트링타입으로 데어터를 받은 후,
숫자인이 판별 후, 최대 최소 값을 출력하는 프로그램을 작성하려 했으나,
형변환을 배우지 않아서 txt파일에서 missing var을 없애고 그냥 flaot 타입으로 데이터를 받았다.
*/
using namespace std;
void highest(float a, float& hi );
void lowest(float a, float& lo);
bool datain(ifstream& getdata, float& data);
void datawrite(ofstream& writefile, float& write);
/*
finding highest and lowest sea level among givien data.
*/

void main() {
	cout << "Start data processing...." << endl;
	ifstream getdata;
	getdata.open("sea_level.txt");
	ofstream writefile;
	writefile.open("result.txt");
	if (!getdata) {
		cerr << "failed to open data file";
		exit(100);
	}
	if (!writefile) {
		cerr << "failed to open result file";
		exit(101);
	}
	float data;
	float hi;
	float lo;
	datain(getdata, data);
	lo = data; hi = data;
	while (datain(getdata, data)) {
		highest(data, hi);
		lowest(data, lo);
	}
	cout << "Highest sea level: " << hi << endl;
	cout << "lowest sea level: " << lo << endl;
	writefile<< "Highest sea level: " << hi << endl;
	writefile << "lowest sea level: " << lo << endl;
	getdata.close();
	writefile.close();
	cout << "Ending data processing process....." << endl;
}
void highest(float a, float& hi) {
	if (hi <= a) {
		hi = a;
	}
}
void lowest(float a,float& lo) {
	if (lo >= a) {
		lo = a;
	}
	
}

bool datain(ifstream& getdata, float& data) {
	getdata >> data;
	if (!getdata) {
		return false;
	}
	return true;
}
void datawrite(ofstream& writefile, float& write) {
	writefile << write << endl;
}