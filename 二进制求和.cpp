#include<iostream>
#include<vector>

using namespace std;

string addBinary(string a, string b) {
	// 字符串翻转，为了使末位对齐
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int maxLen = max(a.size(), b.size());
	int carrry = 0;  // 进位标志
	string ret;
	for (int i = 0; i < maxLen; ++i) {
		carrry += i < a.size() ? (a.at(i) == '1') : 0;
		carrry += i < b.size() ? (b.at(i) == '1') : 0;
		ret.push_back((carrry % 2) ? '1' : '0');
		carrry = carrry / 2;
	}
	if (carrry) {
		ret.push_back('1');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {

	return 0;
}