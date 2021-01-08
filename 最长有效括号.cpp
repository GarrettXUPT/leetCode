#include<iostream>
#include<stack>

using namespace std;

int longestVaildParentheses(string s) {
	if (s.length() <= 1) {
		return 0;
	}
	int ret = 0;
	stack<char> stk;
	const char* ch = s.c_str();
	while (*ch != '\0') {
		if (*ch == '(') {
			stk.push(*ch);
		}
		else if (*ch == ')') {
			if ((!stk.empty()) && (stk.top() == '(')) {
				stk.pop();
				ret++;
			}
			else {
				stk.push(*ch);
			}
		}
		ch++;
	}
	return ret * 2;
}

int main() {
	string s{ "()(()" };
	cout << longestVaildParentheses(s) << endl;
}