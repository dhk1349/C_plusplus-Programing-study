#include<iostream>
using namespace std;
void prime_detector(int n);//소수인지 판별해주는 함수.
int prime_detector2(int n);
void composite_list(int n); //입력한 숫자 이하의 작은 소수들을 나열
void composite_breaker(int n);// 입력한 숫자를 소수로 분해해줌(중복 제외).


void main() {
	int a;
	while (true) {
		cout << "합성수 분해기:    ";
		cin >> a;
		composite_breaker(a);
		if (a == 0) {
			break;
		}
	}
	while (true) {
		cout << "입력 수 보다 작은 소수 나열:    ";
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
		if (n%i==0) {//i가 약수인지 먼저 확인
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
	cout << "입력한 숫자의 소수들이 및에 나열 될 것에요." << endl;
	for (int i = 1;i<=n;i++) {
		temp = prime_detector2(i);
		if (temp != 0) {
			cout << temp<<endl;
		}
		else if (temp==0) {
			//아무것도 안함
		}
		else {
			cout << "Error: Unexpecter case occured" << endl;
		}
	}
}

int prime_detector2(int n) {  //이건 소수의 값을 리턴해준다. 
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
