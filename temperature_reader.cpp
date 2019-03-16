#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
//temp.txt를 받아서 최저기온, 최고 기온, 
//소수점 첫 째 자리를 반올림해서 최빈값을 구하시오.
bool infile(ifstream& indata, float& temp);
void hot(float& a, float b);
void cold(float& a, float b);
void modev(vector<vector<int>>& v, float a);
void integration(vector<vector<int>>& v, float& hot,float& cold , float indata);
void freq(const vector<vector<int>>& v);
using matrix = vector<vector<int>>;
void main() {
	float value;
	matrix mode;
	ifstream getdata;
	float hotv, coldv;
	getdata.open("temp.txt");
	if (!getdata) { cerr << "Fail to load file\n"; exit(100); }
	int count = 1;
	while (infile(getdata, value)) {
		if (count==1) {
			hotv = value, coldv = value;
			modev(mode,value);
			count += 1;
			continue;
		}
		else {
			integration(mode, hotv, coldv, value);
		}
	}
	cout << "Hottest: " << hotv << endl;
	cout << "Coldest: " << coldv << endl;
	freq(mode);
	getdata.close();
}
void freq(const vector<vector<int>>& v) {
	int modev=v[0][0];
	int mode=v[0][1];
	for (int i = 1;i<v.size();i++) {
		if (mode < v[i][1]) {
			mode = v[i][1];
			modev = v[i][0];
		}
	}
	cout << "mode value: " << modev<<" showed "<<mode<<"times"<<endl;
}
void integration(vector<vector<int>>& v, float& hotv, float& coldv, float indata) {
	hot(hotv, indata);
	cold(coldv, indata);
	modev(v, indata);
}
void modev(vector<vector<int>>& v, float a) {//값들을 반올림해서 저장한다. 하나의 값 단위로 실행함. 
	int temp = round(a);
	int check = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i][0] == temp) { v[i][1] += 1; check += 1; break; }//같은 값이면 +1
	}
	if (check == 0) { v.push_back({ temp,1 }); }//벡터 안에 없는 값은 새로 추가
}
void hot(float& a, float b) {
	if (a < b) {
		a = b;
	}
}
void cold(float& a, float b){
	if (a > b) {
		a=b;
	}
}
bool infile(ifstream& indata, float& temp) {
	indata >> temp;
	while (indata) { return true; }
	return false;
}
