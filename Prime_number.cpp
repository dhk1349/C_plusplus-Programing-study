#include<iostream>
using namespace std;
void prime_detector(int n);//�Ҽ����� �Ǻ����ִ� �Լ�.
int prime_detector2(int n);
void composite_list(int n); //�Է��� ���� ������ ���� �Ҽ����� ����
void composite_breaker(int n);// �Է��� ���ڸ� �Ҽ��� ��������(�ߺ� ����).


void main() {
	int a;
	while (true) {
		cout << "�ռ��� ���ر�:    ";
		cin >> a;
		composite_breaker(a);
		if (a == 0) {
			break;
		}
	}
	while (true) {
		cout << "�Է� �� ���� ���� �Ҽ� ����:    ";
		cin >> a;
		composite_list(a);
		if (a==0) {
			break;
		}
	}
	while (true) {
		cout << "\nprime number detector. \n Type any interger:    ";
		cin >> a;
		prime_detector(a);
		if (a == 0) {
			break;
		}
	}
}

void composite_breaker(int n) {
	for (int i=1; i <= n; i++) {
		int temp = 0;
		if (n%i==0) {//i�� ������� ���� Ȯ��
			temp = prime_detector2(i);
		}
		else {
			temp = 0;
		}
		if (temp != 0) {
			cout << i << endl;
		}
	}
}

void composite_list(int n) {
	int temp;
	cout << "�Է��� ������ �Ҽ����� �׿� ���� �� �Ϳ���." << endl;
	for (int i = 1;i<=n;i++) {
		temp = prime_detector2(i);
		if (temp != 0) {
			cout << temp<<endl;
		}
		else if (temp==0) {
			//�ƹ��͵� ����
		}
		else {
			cout << "Error: Unexpecter case occured" << endl;
		}
	}
}

int prime_detector2(int n) {  //�̰� �Ҽ��� ���� �������ش�. 
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			sum += i;
		}
	}
	if (sum == n + 1) {
		return n;	
	}
	else if (sum != n + 1) {
		return 0;
	}
	else {
		cout << "Unexpected case occured!" << endl;
	}
}

void prime_detector(int n) {
	int sum = 0;
	for (int i=1;i<=n;i++) {
		if (n%i==0) {
			sum += i;
		}
	}
	if (sum==n+1) {
		cout << n << " is prime number." << endl;
	}
	else if (sum!=n+1) {
		cout << n << " is not prime number" << endl;
	}
	else {
		cout << "Unexpected case occured!" << endl;
	}
}
