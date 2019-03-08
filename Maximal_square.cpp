#include<iostream>
#include<string>
using namespace std;
void max_square(string str[]);
int sqr_check(string data[], int a, int b, int c); //location(a,b) and size

void main() {
	string data[5] = { "0111","1111","1111","1111","0000" };
	string data2[5] = {"1111","1111","1111","1111","1111"};
	max_square(data);   //should print 3
	max_square(data2);  //should print 4
}

void max_square(string str[]) {
	/*
	input ex: "101011","101011","101011" (string array format)
	returns 2.
	return area of maximal area
	*/
	int len; //Estimating possible max squre with given size.
	if ((str->size()) > str[1].size()) {
		len = str->size();
	}
	else {
		len = str[1].size();
	}
	int max = 0;
	for (int i = 1; i <= len; i++) {//size of square
		int check = 0;
		int a= (str->size() - i + 1);
		for (int k=1;k<=a;k++) {//checking maxsq moving next line. starting from line1.
			int b = (str[k].size() - i + 1);
			for (int j = 1; j <= b; j++) {//check maxsq moving in horizontal direction
				if (sqr_check(str, j, k, i)==0){ 
					check = 1;

				}
			}
			
			}
		if (check == 1) {
			max += 1;
		}
	
		
	}
	cout<<"size of maximal square is:   "<< max<<"\n\n";
}

int sqr_check(string str[], int a, int b, int c) {
	/*
	data=data that I want to check.
	a=location,b=location(y axis) c=size
	return 0 if it is square with 1
	*/
	int result = 0;
	for (int i = b-1; i <= b+c-2; i++) {//column
		for (int j = a-1; j <= a+c-2; j++) {
			if (str[i][j] != '1') {
				result = 1;
			}
		}
	}
	return result;
}