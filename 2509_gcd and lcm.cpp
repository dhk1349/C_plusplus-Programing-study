#include <iostream>
using namespace std;
int gcd(int a, int b) {
	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b, int gcd) {
	//Coded like this just in case it takes long time to calculate gcd.
	return (a * b) / gcd;
}

int main()
{
	int a, b, GCD;
	cin >> a >> b;
	GCD = gcd(a, b);
	cout << GCD << endl << lcm(a, b, GCD) << endl;
}