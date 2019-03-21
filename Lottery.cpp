#include<iostream>
#include<vector>
using namespace std;

void jackpot(const vector<int>& a, const vector<int>& b);

void main() {
	vector<int> result(7);
	vector<int> mynum(6);
	cout << "가장 첫 숫자에 -9입력 시 exit...\n";
	while (true) {
		for (int i = 0; i < 7; i++) {
			cin >> result[i];
		}
		cout <<"결과값 입력 완료"<< endl;
		for (int i = 0; i < 6; i++) {
			cin >> mynum[i];
		}
		if (result[0]==-9) {
			break;
		}
		jackpot(result, mynum);
	}
}
void jackpot(const vector<int>& a, const vector<int>& b) {
	double count = 8;
	for (int elem: a) {
		for (int elem2 : b) {
			if (elem==elem2){
				count -= 1; //보너스 숫자 맞추면 2등, 보너스 아닌 것 맞추면 1등
				//지금 6숫자가 맞으면 count=2가 되는 상황.
				if (a[6]==elem2) {
					count += 0.5;//보너스 숫자 맞추면 2.5가 됨.
				}
			}
		}
	}
	if (count > 5) {
		count = -1;
	}
	else if (count == 2) {
		count -= 1;
	}
	else  {
		count =floor(count);
	}
	cout << count << endl;
}