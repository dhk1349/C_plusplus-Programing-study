#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
	vector<string> hashtable;
	vector<int> hash;

	for (int i = 0; i < clothes.size(); i++) {
		int Found = -1;
		for (int j = 0; j < hashtable.size(); j++) {
			if (hashtable[j] == clothes[i][1]) {
				Found = j;
				break;
			}
		}
		if (Found == -1) {
			hashtable.push_back(clothes[i][1]);
			hash.push_back(1);
		}
		else {
			hash[Found] += 1;
		}
	}
	int answer = 1;
	for (int i = 0; i < hashtable.size(); i++) {
		cout << hashtable[i] << ": " << hash[i] << endl;
		answer *= (hash[i] + 1);
	}

	return answer - 1;
}
int main() {
	//vector<int>budgets = { 120, 110, 140, 150 };
	//int M = 485;
	vector<vector<string>>input1 = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
	vector<vector<string>>input2 = { {"crow_mask", "face"},{"blue_sunglasses", "face"}, { "smoky_makeup", "face" } };

	cout << solution(input2) << endl;
	return 0;
}