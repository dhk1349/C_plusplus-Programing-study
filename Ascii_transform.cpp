#include <iostream>
#include<string>
using namespace std;
void relocate(string str);
int ascii_trans(char a);

void main() {
	string data;
	cout << "Type anything:   ";
	cin >> data;
	cout << "Rellocating in alphabetical order:    ";
	relocate(data);
}

void relocate(string str) {
	int code = 0;
	while (code == 0) {
		int changed=0;
		int temp1, temp2;
		for (int i = 0;i<=(str.size()-2);i++) {
			temp1 = ascii_trans(str[i]);
			temp2 = ascii_trans(str[i + 1]);
			if (temp1 > temp2) {
				char temp3=str[i+1];
				str[i + 1] = str[i];
				str[i] = temp3;
				changed += 1;
			}

		/*forÀÇ ´İ´Â °ıÈ£*/}
		if (changed == 0) {
			code = 1;
		}
	}
	cout << str << endl;
}
int ascii_trans(char a) {
	int value=0;
	if ((int(a) >= 65) && (int(a) <= 90)) {
		value = int(a) + 32;
	}
	else if ((int(a)>=97)&&(int(a)<=122)) {
		value = int(a);
	}
	else {
		cout << "unexpected case in ascii_trans fun\n";
	}
	return value;
}
