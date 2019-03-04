#include<iostream>
#include<cmath>
using namespace std;

/*

*/
int kap(int n);
int lower(int n);
int higher(int n);

void main() {
	while (true) {
		int n;
		cout << "Type any 4digit number:    ";
		cin >> n;
		if (n==0) {
			break;
		}
		cout << "Untill above number reaches Kaprekars Constant, " << kap(n) << "times of calculation is needed. " << endl;
	}
}

int kap(int n) {
	int hi, lo;
	int number = n;
	int iter = 0;
	while (true) {
		hi = higher(number);
		lo = lower(number);
		if (number== (hi-lo)) {
			break;
		}
		number = (hi-lo);
		iter += 1;
	}
	return iter;
}
int lower(int n) {
//�ټ��ڸ� ������ ex.15234
	int a, b, c, d;
	a = n % 10;  //1�� �ڸ�
	b = ((n % 100) - a)/10;  //10�� �ڸ�
	c = ((n % 1000) - a - b * 10)/100;  //100�� �ڸ�
	d = ((n % 10000) - a - b * 10 - c * 100)/1000;  //1000�� �ڸ�
	//�Ʒ��� a,b,c,d�� ������ ���� ��迭 �� ����. 
	//���� ����Ʈ�� ����� �ݺ����� �����°� �ξ� �������� 
	//����Ʈ�� ����� �ٷ��� ���ϱ⿡ ������� ����.
	int code = 0;
	while (code == 0) {
		int changed = 0;
		if (a>b) {
			int temp = b;
			b = a;
			a = temp;
			changed += 1;
		}
		if (b>c) {
			int temp = c;
			c = b;
			b = temp;
			changed += 1;
		}
		if (c>d) {
			int temp = d;
			d = c;
			c = temp;
			changed += 1;
		}
		if (changed == 0) {
			code = 1;
		}
	}
	return a*1000+b*100+c*10+d;
}
int higher(int n) {
	int a, b, c, d;
	a = n % 10;  //1�� �ڸ�
	b = ((n % 100) - a) / 10;  //10�� �ڸ�
	c = ((n % 1000) - a - b * 10) / 100;  //100�� �ڸ�
	d = ((n % 10000) - a - b * 10 - c * 100) / 1000;  //1000�� �ڸ�
	int code = 0;
	while (code == 0) {
		int changed = 0;
		if (a<b) {
			int temp = b;
			b = a;
			a = temp;
			changed += 1;
		}
		if (b<c) {
			int temp = c;
			c = b;
			b = temp;
			changed += 1;
		}
		if (c<d) {
			int temp = d;
			d = c;
			c = temp;
			changed += 1;
		}
		if (changed == 0) {
			code = 1;
		}
	}
	return a * 1000 + b * 100 + c * 10 + d * 1;
}
