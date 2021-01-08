#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string s) {
	auto begin = s.begin();
	auto end = s.end();
	auto rbegin = s.rbegin();
	auto rend = s.rend();
	while (begin != end && rbegin != rend) {
		if (((isalnum(*begin) || isalpha(*begin)) && (isalnum(*rbegin) || isalpha(*rbegin)))) {
			if (toupper(*begin) != toupper(*rbegin)) {
				return false;
			}
			begin++; rbegin++;
			continue;
		}
		else if (!isalnum(*begin) && !isalpha(*begin)) {
			begin++;
			continue;
		}
		else if (!isalnum(*rbegin) && !isalpha(*rbegin)) {
			rbegin++;
			continue;
		}
	}
	return true;
}

int main() {
	auto res = isPalindrome("v' 5:UxU:5 v'");
	cout << res << endl;
	return 0;
}