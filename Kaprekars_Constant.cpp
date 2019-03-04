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
//다섯자리 숫자임 ex.15234
	int a, b, c, d;
	a = n % 10;  //1의 자리
	b = ((n % 100) - a)/10;  //10의 자리
	c = ((n % 1000) - a - b * 10)/100;  //100의 자리
	d = ((n % 10000) - a - b * 10 - c * 100)/1000;  //1000의 자리
	//아래는 a,b,c,d를 순서에 따라서 재배열 할 것임. 
	//물론 리스트를 만들고 반복문을 돌리는게 훨씬 낫겠지만 
	//리스트를 제댈로 다루지 못하기에 사용하지 않음.
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
	a = n % 10;  //1의 자리
	b = ((n % 100) - a) / 10;  //10의 자리
	c = ((n % 1000) - a - b * 10) / 100;  //100의 자리
	d = ((n % 10000) - a - b * 10 - c * 100) / 1000;  //1000의 자리
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
