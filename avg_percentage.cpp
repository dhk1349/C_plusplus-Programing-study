#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num, iter, score, student;
	double avg;
	vector<int> temp;
	//vector<double> result;
	cout << fixed;
	cout.precision(3);
	cin >> num;
	for (int i = 0; i < num; i++) {
		avg = 0;
		student = 0;
		cin >> iter;
		for (int j = 0; j < iter; j++) {
			cin >> score;
			temp.push_back(score);
			avg += score;
		}
		avg /= iter;

		for (int i = 0; i < iter; i++) {
			if (temp[i] > avg) {
				student++;
			}
		}

		cout << double(student) / iter * 100 << "%\n";
		temp.clear();
	}


	return 0;
}
