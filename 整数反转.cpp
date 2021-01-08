#include<iostream>
#include<vector>

using namespace std;

int reverse(int x) {
	long result = 0;
	while (x) {
		result = result * 10 + x % 10;
		x = x / 10;
	}
	if (result >= -pow(2, 31) && result <= pow(2, 31) - 1) {
		return result;
	}
	return 0;
}