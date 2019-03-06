#include<iostream>
#include<cstdlib>
#include<list>
#include<ctime>
using namespace std;
void cover();
void zero();
void one();
void two();
void d_1(int i=0); //1이 적힌 주사위 기본값으로 입력 시, 온전한 주사위 출력됨.
void d_2(int i = 0);
void d_3(int i = 0);
void d_4(int i = 0);
void d_5(int i = 0);
void d_6(int i = 0);
void multi_dice(int a);  //주사위를 a개 출력한다. 
void call_dice(int i, int j); //i의 눈금만큼의 주사위를 불러 출력한다.

void main() {
	while (true) {
		int a;
		cout << "주사위 몇 개 굴리고 싶으세요 (0을 입력하면 EXIT):  ";
		cin >> a;
		if (a==0) {
			break;
		}
		multi_dice(a);
	}
}


void multi_dice(int a) {
	/*
	rand()%6+1: 1-6까지 랜덤으로 나옴.
	*/
	srand((unsigned int)time(NULL));
	list<int> box;
	std::list<int>::iterator it;   //잘 모름. 그냥 따라함
	for (int i = 1; i <= a; i++) {
		box.push_back(rand() % 6 + 1);
	}
	it = box.begin();
	cout << "나온 숫자는..." << endl;
	for (int i = 1;i<=box.size();i++) {
		cout << *it << "  ";
		it++;
	}
	cout << "입니다" << endl;
	//리스트에 a개 원소 채움
	for (int i = 1; i <= 5; i++) {//층
		it = box.begin();
		for (int j=1;j<=a;j++) {//주사위 by주사위
			call_dice(*it,i);
			it++;
		}
		cout << endl;
	}
}
void d_1(int i ) {// 다수의 주사위를 출력하기 위해서 함수를 변경함. 
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