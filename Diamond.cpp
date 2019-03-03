#include<iostream>
#include<iomanip>
using namespace std;
/*
Diamond will be printed on the screen
*/
void diamond(int a);
void diamond2(int a);
void multi_dia(int a,int b);

void main() {
	int a,b;
	cout << "Type even number:  ";
	cin >> a;
	cout << "How many:  ";
	cin >> b;

	multi_dia(a, b);
}

void diamond(int a) {
	int height = a / 2;
	//upper body
	for (int i = 1; i != height + 1; i++) {
		cout << setw(height - i+1)<<  "/" << setw((i - 1) * 2+1) << "\\" << setw(height - i+1)<< endl;
	}
	//lower body
	for (int i = height; i >= 1; i--) {
		cout << setw(height - i+1) << "\\" << setw((i - 1) * 2+1) << "/" << setw(height - i+1) << endl;

	}
	cout << endl;
}

void diamond2(int a) {
	int height = a / 2;
	//upper body 
	for (int i=1;i<=height;i++) {//floor
		for (int j=1;(j<=(height-i))&&(height-1!=0);j++) {
			cout << " ";
		} 
		cout << "/";
		for (int j=1;(j<=(i-1)*2)&&((i-1)*2!=0);j++) {
			cout << " ";
		}
		cout << "\\";
		for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
			cout << " ";
		}
		cout << endl;
	}
	//lower body
	for (int i = height; i >= 1; i--) {//floor
		for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
			cout << " ";
		}
		cout << "\\";
		for (int j = 1; (j <= (i - 1) * 2) && ((i - 1) * 2 != 0); j++) {
			cout << " ";
		}
		cout << "/";
		for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
			cout << " ";
		}
		cout << endl;
	}
}
void multi_dia(int a,int b) {
	int height = a / 2;
	//upper body 
	for (int i = 1; i <= height; i++) {//floor
		for (int k = 1;k<=b;k++) {
			for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
				cout << " ";
			}
			cout << "/";
			for (int j = 1; (j <= (i - 1) * 2) && ((i - 1) * 2 != 0); j++) {
				cout << " ";
			}
			cout << "\\";
			for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
				cout << " ";
			}
		}
		cout << endl;
	}
	//lower body
	for (int i = height; i >= 1; i--) {//floor
		for (int k = 1; k <= b; k++) {
			for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
				cout << " ";
			}
			cout << "\\";
			for (int j = 1; (j <= (i - 1) * 2) && ((i - 1) * 2 != 0); j++) {
				cout << " ";
			}
			cout << "/";
			for (int j = 1; (j <= (height - i)) && (height - 1 != 0); j++) {
				cout << " ";
			}
			
		}
		cout << endl;

	}

}
