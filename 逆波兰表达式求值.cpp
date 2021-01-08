#include<iostream>
#include<stack>
#include<vector>
#include<sstream>

using namespace std;

int evalRPN(vector<string> tokes) {
	// 不需要额外定义一个用来作为返回值的，将每一次的计算结果都压栈为下一次的操作数，最后返回栈顶元素
	stack<int> stk;
	int first = 0, second = 0;
	for (int i = 0; i < tokes.size(); ++i) {
		// 循环取出tokes中的每一个元素
		string s = tokes[i];
		// 若该字符串是加号则弹出栈中的两个元素，让后一个弹出的元素+前一个弹出的元素，最后再把计算得到的值压入栈中
		if (s == "+") {
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			int add = second + first;
			stk.push(add);
		}
		// 若该字符串为减号则弹出栈中的两个元素，让后弹出放入元素-前一个弹出的元素，最后将计算得到的值压到栈中
		else if (s == "-") {
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			int sub = second - first;
			stk.push(sub);
		}
		else if (s == "*") {
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			int mul = second * first;
			stk.push(mul);
		}
		else if (s == "/") {
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			int div = second / first;
			stk.push(div);
		}
		else
		{
			// 字符串转化为整形
			stringstream ss;
			ss << s;
			int value = 0;
			ss >> value;
			stk.push(value);
		}
	}
	return stk.top();
}


int main() {
	vector<string> strVec{ "2", "1", "+", "3", "*" };
	cout << evalRPN(strVec) << endl;
	return 0;
}