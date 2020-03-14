#include <iostream>

using namespace std;
//1
int main() {
	unsigned long int result = 0;
	int num;
	cin >> num;
	int range = num / 2;

	if(num%2==0){
		result = 1;
	//맨 앞 자리가 1이 됨
		for(int i=0;i<range-1;i++){
			result *= 10;
			result += 1;
		}
	}

	else{
	//맨 앞 자리가 7이 됨.
		result = 7;
		for (int i = 0; i < range-1; i++) {
			result *= 10;
			result += 1;
		}
	}
	cout << result;
	return 0;
}