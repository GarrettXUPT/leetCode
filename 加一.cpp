#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	for (int i = 0; i < digits.size(); ++i) {
		digits[digits.size() - i - 1] = (digits[digits.size() - i - 1] + 1) % 10;
		int div = (digits[digits.size() - i - 1] + 1) / 10;
		if (div != 0) {
			digits[digits.size() - i - 2]++;
		}
	}
	return digits;
}

int main() {
	vector<int> vec{ 3, 2, 1 };
	auto res = plusOne(vec);
	for (auto& ele : res) {
		cout << ele << endl;
	}
	return 0;
}