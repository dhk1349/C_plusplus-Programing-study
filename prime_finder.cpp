#include<iostream>
#include<cmath>
using namespace std;
void primefind(int a);
int divisorfind(int a, int& count);
//�Է� �� A�� �� �Ҽ��� ������ ��Ÿ���� �� ������ ���, �Ұ����ϸ� IMPOSSIBLE���.
void main() {
	int a;
	cout << "Type -9 to exit!\n";
	while (true) {
		cin >> a;
		if (a == -9) {
			break;
		}
		primefind(a);
	}
}

void primefind(int a) {
	int count = 0;
	int div=divisorfind(a, count);
	if (count==1) {
		cout << div << " " << (a / div) << endl;
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}
int divisorfind(int a, int& count) {//sqrt(a)������ ������ �ϳ��� ������ ����, 0���̰ų� �ϳ� �̻��̸� �Ұ����̴�.
	int div = -999;
	for (int i = 2;(i<sqrt(a));i++) {
		if (a%i==0) {//������ ������
			count += 1;
			div = i;
		}
	}
	return div;
}