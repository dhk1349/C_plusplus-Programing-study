#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
/*
���� ������ txt���Ϸ� �����Ǿ��ִ�.
�� ������ �о�ͼ� Ŭ������ ������ ���̴�.
txt������ ù ° ������ �̸�, �Ѥ��� ID, �� °�� �Ա� ��, �� °�� �ſ� ����̴�.
*/
void write(ofstream& outfile, string name, int ID, double balance, char grade);
bool getfile(ifstream& infile, string& name, int& ID,double& balance, char& grade);
class acc {
public:
	acc(string getname, int getID, double amt, char getgrade) :
		name(getname), ID(getID), balance(amt), grade(getgrade) {
		if (amt < 0) {
			balance=0;
		}
		save();
	}
	acc():
		name("No_name"),ID(0000),balance(0),grade('X'){
	}
	bool withdraw(double amt) {
		bool result = false;
		if (balance-amt>=0) {
			result = true;
			balance -= amt;
			save();
		}
		return result;
	}
	void deposit(double amt) {
		balance += amt;
		save();
	};
	void gradeupdate(char temp) {
		grade = temp;
		save();
	};
	void display() {
		cout << name << " " << ID << " " << balance << " " << grade<<endl;
	}
private:
	string name;
	int ID;
	double balance;
	char grade;
	ofstream outfile;
	void save() {
		outfile.open("save.txt", ios::app);
		write(outfile, name, ID, balance, grade);
		outfile.close();
 
	}

};
void main() {
	acc a1("Joe", 1231, 500,'A');
	acc a2("Jack", 1111, 3, 'B');
	a1.display();
	a2.display();
	a1.deposit(10);
	a1.display();
}
void write(ofstream& outfile, string name, int ID, double balance, char grade) {
	outfile << setw(5) << left << name << " ";
	outfile << setw(5) << left << ID << " ";
	outfile << setw(5) << left << balance << " ";
	outfile << setw(5) << left << grade << endl;

}
bool getfile(ifstream& infile, string& name, int& ID, double& balance, char& grade) {
	infile >> name >> ID >> balance >> grade;
	if (!infile) {
		return false;
	}
	return true;
}