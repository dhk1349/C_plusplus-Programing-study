#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int recursive(int sum, vector<int> next, int target, int& ans) {
	if (next.size() == 0) { if (sum == target) { ans += 1; } }
	else {
		int addend = next[0];
		next.erase(next.begin());
		recursive(sum + addend, next, target, ans);
		recursive(sum - addend, next, target, ans);
	}
	return ans;
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int num = 0;
	recursive(num, numbers, target, answer);
	return answer;
}

int main(void) {
	vector<int> numbers = { 1,1,1,1,1 };
	int target = 3;
	cout << solution(numbers, target);
	return 0;
}
