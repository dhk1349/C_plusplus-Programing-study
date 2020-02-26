#include <iostream>
#include <algorithm>
using namespace std;
#define INF 9999999;


int solve(int num) {
	int coin[3] = { 1,3,4 };
	if (num < 0) { return INF; }
	else if (num == 0) { return 0; }
	int best = INF;
	for (auto c : coin) {
		best = min(best, solve(num - c) + 1);
	}
	return best;
}

int main() {
	//Dynamic Programming
	//Coin: 1, 3, 4
	int num;
	cin >> num;
	cout << solve(num) << endl;

	return 0;
}