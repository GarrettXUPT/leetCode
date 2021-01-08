#include<iostream>
#include<stack>
#include<vector>
#include<sstream>

using namespace std;

int evalRPN(vector<string> tokes) {
	// ����Ҫ���ⶨ��һ��������Ϊ����ֵ�ģ���ÿһ�εļ�������ѹջΪ��һ�εĲ���������󷵻�ջ��Ԫ��
	stack<int> stk;
	int first = 0, second = 0;
	for (int i = 0; i < tokes.size(); ++i) {
		// ѭ��ȡ��tokes�е�ÿһ��Ԫ��
		string s = tokes[i];
		// �����ַ����ǼӺ��򵯳�ջ�е�����Ԫ�أ��ú�һ��������Ԫ��+ǰһ��������Ԫ�أ�����ٰѼ���õ���ֵѹ��ջ��
		if (s == "+") {
			first = stk.top();
			stk.pop();
			second = stk.top();
			stk.pop();
			int add = second + first;
			stk.push(add);
		}
		// �����ַ���Ϊ�����򵯳�ջ�е�����Ԫ�أ��ú󵯳�����Ԫ��-ǰһ��������Ԫ�أ���󽫼���õ���ֵѹ��ջ��
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
			// �ַ���ת��Ϊ����
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