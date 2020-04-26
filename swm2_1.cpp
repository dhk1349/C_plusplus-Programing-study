#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, tmpsum = 0;
	vector<int> cont1, cont2;
	cin >> n;

	//양수끼리 모두 합침
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x < 0) {
			if (tmpsum > 0) {
				cont1.push_back(tmpsum);
			}
			cont1.push_back(x);
			tmpsum = 0;
		}
		else {
			//0보다 큰 당도인 경우
			tmpsum += x;
		}
	}
	if (tmpsum != 0) { cont1.push_back(tmpsum); }
	tmpsum = 0;

	//음수끼리 합쳐야함.
	int cnt = 0;
	for (int i = 0; i < cont1.size(); i++) {
		if (cont1[i] >= 0) {
			if (tmpsum < 0) { cont2.push_back(tmpsum); tmpsum = 0; }
			cont2.push_back(cont1[i]);
		}
		else {
			tmpsum += cont1[i];
		}
	}
	if (tmpsum < 0) { cont2.push_back(tmpsum); tmpsum = 0; }
	cont1.clear();

	for (int i = 0; i < cont2.size(); i++) {
		cout << cont2[i] << " ";
	}
	cout << endl;

	vector<int>tmpcont;
	int localmax = 1;
	bool cond = true;
	while (cond) {
		cond = false;
		for (int i = 0; i < cont2.size(); i++) {
			//음수를 끼고 합칠지 결정.
			if (cont2[i] < 0) {
				tmpsum = cont2[i];
				if (i > 0) {
					tmpcont.push_back(cont2[i - 1]);
					tmpsum += cont2[i - 1];
				}
				if (i < cont2.size() - 1) {
					tmpcont.push_back(cont2[i + 1]);
					tmpsum += cont2[i + 1];
				}
				tmpcont.push_back(tmpsum);
				localmax = *max_element(tmpcont.begin(), tmpcont.end());
				if (localmax == tmpsum) {
					//합치기!
					cond = true;
					cont2[i] = localmax;
					localmax = i;
					break;
				}
			}
		}
		if (cond == false) { break; }
		cont2[localmax - 1] = tmpsum;
		cont2.erase(cont2.begin() + localmax);
		cont2.erase(cont2.begin() + localmax);

		for (int i = 0; i < cont2.size(); i++) {
			cout << cont2[i] << " ";
		}
		cout << endl;

	}
	cout << *max_element(cont2.begin(), cont2.end());
	return 0;
}