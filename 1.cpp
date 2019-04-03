#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;
void writefile(ofstream& write, int a, int b, int c, int d, int e);
void writefile2(ofstream& write, float a, float b, float c, float d, float e);
bool getdata(ifstream& data, int& a, int& b,int& c,int& d,int& e);
bool getdata2(ifstream& data, float& a, float& b, float& c, float& d, float& e);
float fnc(float a);

void main() {
	int a, b, c, d, e;
	ofstream write;
	write.open("text1.txt");
	if (!write) {
		cerr << "cannot write file1!" << endl;
		exit(102);
	}
	cin >> a >> b >> c >> d >> e;
	writefile(write, a, b, c, d, e);
	write.close();

	write.open("text2.txt");
	if (!write) {
		cerr << "cannot write file2!" << endl;
		exit(102);
	}
	for (int i = 1; i <= 4; i++) {
		a = 1 * i, b = 2 * i, c = 3 * i, d = 4 * i, e = 5 * i;
		writefile(write, a, b, c, d, e);
		write << endl;
	}
	write.close();
	//D
	ifstream data1;
	data1.open("text1.txt");
	ifstream data2;
	data2.open("text2.txt");
	write.open("text3.txt");
	if (!data1) {
		cerr << "cannot open data file!" << endl;
		exit(101);
	}
	int a2, b2, c2, d2, e2;

	while (getdata(data1, a, b, c, d, e)) {
	//text1저장됨
	}
	getdata(data2, a2, b2, c2, d2, e2); 
		write << "+ 연산결과: ";
		a2 += a;
		b2 += b;
		c2 += c;
		d2 += d;
		e2 += e2;
		writefile(write, a2, b2, c2, d2, e2);
		write << " (1의 배수와 연산)" << endl;
	
	getdata(data2, a2, b2, c2, d2, e2);
		write << "- 연산결과: ";
		a2 -= a;
		b2 -= b;
		c2 -= c;
		d2 -= d;
		e2 -= e;
		writefile(write, a2, b2, c2, d2, e2);
		write << " (2의 배수와 연산)" << endl;
		
	getdata(data2, a2, b2, c2, d2, e2);
		write << "* 연산결과: ";
		a2 *= a;
		b2 *= b;
		c2 *= c;
		d2 *= d;
		e2 *= e;
		writefile(write, a2, b2, c2, d2, e2);
		write << " (3의 배수와 연산)" << endl;
	
	getdata(data2, a2, b2, c2, d2, e2);
	float a3, b3, c3, d3, e3;
	float a4, b4, c4, d4, e4;
	a3 = a, b3 = b, c3 = c, d3 = d, e3 = e;
	a4 = a2, b4 = b2, c4 = c2, d4 = d2, e4 = e2;
		write << "/ 연산결과: ";
		a3 /= a4;
		b3 /= b4;
		c3 /= c4;
		d3 /= d4;
		e3 /= e4;
		//text3.txt에서 소수점 둘째자리 까지만 나타내기 위한 작업(아래)
		a3 = fnc(a3); b3 = fnc(b3); c3 = fnc(c3); d3 = fnc(d3); e3 = fnc(e3); a3 = fnc(a3);
		writefile2(write, a3, b3, c3, d3, e3);
		write << " (4의 배수와 연산)" << endl;
	
}
bool getdata(ifstream& data, int& a, int& b, int& c, int& d, int& e) {
	data >> a >> b >> c >> d >> e;
	if (!data) {
		return false;
	}
	return true;
}

bool getdata2(ifstream& data, float& a, float& b, float& c, float& d, float& e) {
	data >> a >> b >> c >> d >> e;
	if (!data) {
		return false;
	}
	return true;
}

void writefile(ofstream& write, int a, int b, int c,int d,int e) {
	//write in proper format
	write << a << " " << b << " " << c << " " << d << " " << e;
}
void writefile2(ofstream& write, float a, float b, float c, float d, float e) {
	//write in proper format
	write << a << " " << b << " " << c << " " << d << " " << e;
}
float fnc(float a) {//소수점 둘째자리 까지
	float temp = floor(a * 100);
	temp /= 100;
	return temp;
}