#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h, minnum;
	cin >> x >> y >> w >> h;
	minnum = min(x, y);
	minnum = min(minnum, w - x);
	cout << min(minnum, h - y) << endl;
	return 0;
}