#include<iostream>
#include<vector>
using namespace std;

void jackpot(const vector<int>& a, const vector<int>& b);

void main() {
	vector<int> result(7);
	vector<int> mynum(6);
	cout << "���� ù ���ڿ� -9�Է� �� exit...\n";
	while (true) {
		for (int i = 0; i < 7; i++) {
			cin >> result[i];
		}
		cout <<"����� �Է� �Ϸ�"<< endl;
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
				count -= 1; //���ʽ� ���� ���߸� 2��, ���ʽ� �ƴ� �� ���߸� 1��
				//���� 6���ڰ� ������ count=2�� �Ǵ� ��Ȳ.
				if (a[6]==elem2) {
					count += 0.5;//���ʽ� ���� ���߸� 2.5�� ��.
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