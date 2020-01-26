//1003
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;


int main() {
	vector <int> cache_x(41, 0);
	vector <int> cache_y(41, 0);
	cache_x[0] = 1; cache_y[0] = 0;
	cache_x[1] = 0; cache_y[1] = 1;

	for (int i = 2; i <= 40; i++) {
		cache_x[i] = cache_x[i - 1] + cache_x[i - 2];
		cache_y[i] = cache_y[i - 1] + cache_y[i - 2];
	}

	int n, in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		cout << cache_x[in] << " " << cache_y[in] << endl;
	}

	return 0;
}
