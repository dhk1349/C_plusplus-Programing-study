#include<iostream>
using namespace std;
//입력한 해와 달이 몇 일로 되어있는지 출력해줌.
int days(int yr,int month);

void main() {
	cout << "type\'0 0\' to exit\n";
	while (true) {
		int yr, mth;
		cin >> yr >> mth;
		if ((yr==0)&&(mth==0)) {
			break;
		}
		cout<<days(yr, mth)<<endl;
	}
}

int days(int yr, int month){
	int check = 999;
	int days;
	if (yr % 4 == 0) {
		check =1;
	}
	if ((1 <= month) && (month <= 7)) {
		if (month%2==0) {
			if (month != 2) {
				days = 30 ;
			}
			if (month == 2) {
				if (check==0) {
					days = 28;
				}
				else if (check == 1) {
					days = 29;
				}
			}
		}
		else if (month%2==1) {
			days = 31;
		}
	}
	else if ((8<=month)&&(month<=12)) {//8월부터
		if (month%2==0) {
			days = 31;
		}
		else if (month % 2 == 1) {
			days = 30;
		}
	}
	else {
		cout << "Error\n";
	}
	return days;
}
