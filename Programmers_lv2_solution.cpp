
int solution(int n)
{
	int cnt = 0;
	while (n != 0) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n--;
			cnt++;
		}
	}
	return cnt;
}

int solution2(int n) {
	unsigned int first = 0;
	unsigned int second = 1;
	unsigned int third = 1, tmp;
	unsigned int cnt = 1;
	if (n == 1) { return 1; }
	else if (n == 0) { return 0; }
	while (cnt != n) {
		tmp = second;
		second += first;
		first = tmp;
		first %= 1234567;
		second %= 1234567;
		cnt++;
	}
	return second;
}
