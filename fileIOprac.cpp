#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
bool getdata1(ifstream& getdata, string& stuID, int& sub1, int& sub2, int& sub3, int& sub4);
void writefile(ofstream& writeline, string stuID, int avg, int rank);
float avgcal(string& stuID, int& sub1, int& sub2, int& sub3, int& sub4, int& avg);
void rank();
/*
txt파일을 받아서 학생의 성적을 입력 받은 후, 평점을 내주고 등수까지 메긴다. 
*/
void main() {
	cout << "Grade calculation procedure begin....\n";
	ifstream getdata;
	getdata.open("stugrade.txt");
	ofstream writeline;
	writeline.open("final_result.txt");
	if (!getdata) {
		cerr << "Error while opening data file.../";
		exit(100);
	}
	if (!writeline) {
		cerr << "File for recoring has not been successfully made.../";
		exit(101);
	}
	string stuID;
	int sub1, sub2, sub3, sub4, avg;
	int rank = 0;
	int count = 0;
	while (getdata1(getdata, stuID, sub1, sub2, sub3, sub4)) {
		cout << "iterating" << endl;
		avg = avgcal(stuID, sub1, sub2, sub3, sub4, avg);
		cout << "avg: " << avg << endl;
		writefile(writeline, stuID, avg, rank);
	}
	getdata.close();
	writeline.close();
	cout << "data writing process done" << endl;
	
}

bool getdata1(ifstream& getdata, string& stuID, int& sub1, int& sub2, int& sub3, int& sub4){
	getdata >> stuID >> sub1 >> sub2 >> sub3 >> sub4;
	if (!getdata) {
		return false;
	}
	return true;
}
void writefile(ofstream& writeline, string stuID, int avg, int rank) {
	writeline << setw(12)<<setfill('*') << stuID;
	writeline << setw(3) << setfill(' ') << avg;
	writeline << setw(2) << rank<<"등\n";
}
float avgcal(string& stuID, int& sub1, int& sub2, int& sub3, int& sub4, int& avg) {
	avg = (sub1 + sub2 + sub3 + sub4) / 4;
	return avg;
}
void rank() {}