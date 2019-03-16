#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*
Problem_set.txt���� �����͸� �޾ƿͼ� ������ ������
������ ���߸� ���� ������ �Ѿ.
*/
bool getdata(ifstream& data, string& qnum, string& prob);
void hangman(string prob, string& blank, char& guess);//�� ���� ������ guessing fnc
void makeblank(string& prob,string& blank);
void main() {
	ifstream datain;
	datain.open("problem_set.txt");
	char guess;
	string prob, qnum, blank;

	while (getdata(datain, qnum, prob)) {//���� ������ ��ȯ�Ѵ�.
		makeblank(prob, blank);
		while (true) {
			int exitcode = 0;
			for (int i = 0; i <= (prob.length() - 1); i++) {
				if (blank[i] == '_') {
					exitcode += 1;
				}
			}//��ĭ�� �� ä�������� exit�ϴ� �ڵ��
			if (exitcode == 0) { break; }
			hangman(prob, blank, guess); cout << "\n\n";
		}
		cout << "*****************\nNext question!!\n";
	}
	cout << "You cleared all the problems!!!\n";
}

bool getdata(ifstream& data,string& qnum, string& prob) {
	data >> qnum >> prob;
	if (!data) {
		return false;
	}
	return true;
}
void makeblank(string& prob, string& blank) {
	//prob�� ���̸�ŭ _�� ����� �ش�.
	blank = "";//blank �ʱ�ȭ ����
	for (int i = 1; i <= prob.length(); i++) {
		blank += "_";
	}
}
void hangman(string prob, string& blank, char& guess) {
	cout << "Gueess the answer..\n" << blank<<endl;
	cout << "What is in the list?    ";
	cin >> guess;
	int check = 0;
	for (int i = 0;i<=(prob.length()-1);i++) {
		if (prob[i] == guess) {
			blank[i] = guess;
			check += 1;
		}
	}
	if (check > 0) {
		cout << "you're guess is right!\n" ;
	}
	else {
		cout << "you're guess is wrong!\n" ;
	}
	if (check==prob.length()) {
		cout << "Well done!!!" << endl;
	}
}