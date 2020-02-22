#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned int stick = 0, piece = 0;
	string input;
	cin >> input;
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			if (i + 1 < input.length()) {
				if (input[i + 1] == ')') {
					//cout << "Add " << stick << " at " << i <<" ("<<piece<<", "<<stick<<")" <<endl;
					piece += stick;
				}
				else { stick += 1; }
			}

		}
		else {//)
			if (input[i - 1] == '(') {
				//piece+=stick;
			}
			else {
				stick -= 1;
				piece += 1;
				//cout << "Stick ended at " <<  i << endl;
			}
		}
	}
	cout << piece + stick << endl;
	return 0;
}