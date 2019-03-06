#include<iostream>
#include<cstdlib>
#include<list>
#include<ctime>
using namespace std;
void cover();
void zero();
void one();
void two();
void d_1(int i=0); //1�� ���� �ֻ��� �⺻������ �Է� ��, ������ �ֻ��� ��µ�.
void d_2(int i = 0);
void d_3(int i = 0);
void d_4(int i = 0);
void d_5(int i = 0);
void d_6(int i = 0);
void multi_dice(int a);  //�ֻ����� a�� ����Ѵ�. 
void call_dice(int i, int j); //i�� ���ݸ�ŭ�� �ֻ����� �ҷ� ����Ѵ�.

void main() {
	while (true) {
		int a;
		cout << "�ֻ��� �� �� ������ �������� (0�� �Է��ϸ� EXIT):  ";
		cin >> a;
		if (a==0) {
			break;
		}
		multi_dice(a);
	}
}


void multi_dice(int a) {
	/*
	rand()%6+1: 1-6���� �������� ����.
	*/
	srand((unsigned int)time(NULL));
	list<int> box;
	std::list<int>::iterator it;   //�� ��. �׳� ������
	for (int i = 1; i <= a; i++) {
		box.push_back(rand() % 6 + 1);
	}
	it = box.begin();
	cout << "���� ���ڴ�..." << endl;
	for (int i = 1;i<=box.size();i++) {
		cout << *it << "  ";
		it++;
	}
	cout << "�Դϴ�" << endl;
	//����Ʈ�� a�� ���� ä��
	for (int i = 1; i <= 5; i++) {//��
		it = box.begin();
		for (int j=1;j<=a;j++) {//�ֻ��� by�ֻ���
			call_dice(*it,i);
			it++;
		}
		cout << endl;
	}
}
void d_1(int i ) {// �ټ��� �ֻ����� ����ϱ� ���ؼ� �Լ��� ������. 
	if ((i == 1) ||(i== 5)) { cover(); } 
	else if ((i == 2) || (i == 4)) { zero(); }
	else if (i == 3){ one(); }
	else if (i == 0) { cover(); zero(); one(); zero(); cover(); }
}
void d_2(int i ) {
	if ((i == 1) || (i == 5)) { cover(); }
	else if ((i == 2) || (i == 4)) { zero(); }
	else if (i == 3) { two(); }
	else if (i == 0) { cover(); zero(); two(); zero(); cover(); }
}
void d_3(int i ) {
	if ((i == 1) || (i == 5)) { cover(); }
	else if ((i == 2) || (i == 4)||(i==3)) { one(); }
	else if (i == 0) { cover(); one(); one(); one(); cover(); }
}
void d_4(int i ) {
	if ((i == 1) || (i == 5)) { cover(); }
	else if ((i == 2) || (i == 4)) { two(); }
	else if (i == 3) { zero(); }
	else if (i == 0) { cover(); two(); zero(); two(); cover(); }
}
void d_5(int i ) {
	if ((i == 1) || (i == 5)) { cover(); }
	else if ((i == 2) || (i == 4)) { two(); }
	else if (i == 3) { one(); }
	else if (i == 0) { cover(); two(); one(); two(); cover(); }
}
void d_6(int i ) {
	if ((i == 1) || (i == 5)) { cover(); }
	else if ((i == 2) || (i == 4) || (i == 3)) { two(); }
	else if (i == 0) { cover(); two(); two(); two(); cover(); }
}
void cover() {
	cout << " --------- " ;
}
void zero(){
	cout << "|         |" ;
}
void one(){
	cout << "|    o    |" ;
}
void two() {
	cout << "|  o   o  |" ;
}
void call_dice(int i,int j=0) {
	//calling singular dice
	if (i==1) {
		d_1(j);
	}
	else if (i==2) {
		d_2(j);
	}
	else if (i == 3) {
		d_3(j);
	}
	else if (i == 4) {
		d_4(j);
	}
	else if (i == 5) {
		d_5(j);
	}
	else if (i == 6) {
		d_6(j);
	}
	else {
		cout << "Error: calling singular dice, no such dice exist!!" << endl;
	}
}