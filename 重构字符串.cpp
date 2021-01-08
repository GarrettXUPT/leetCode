#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

string reorganizeString(string s) {
	if (s.length() < 2) {
		return s;
	}
	vector<int> chCount(26, 0); // �ڸ������б���26��0,��λ����ϢΪ������ַ���ȡֵΪ���ֵĴ���
	int maxCount = 0;
	const char* ch = s.c_str();
	while (*ch != '\0') {
		chCount[*ch - 'a']++;
		maxCount = max(maxCount, chCount[*ch - 'a']);
		ch++;
	}
	if (maxCount > (s.length() + 1) / 2) {  // ����ĸ��������������ֵ����ô�Ͳ����ܳ����ع������
		return "";
	}

	// ���ִ���֮��ıȽϣ�letter1���ֵĴ���С��letter2���ֵĴ���
	auto cmp = [&](const char& letter1, const char& letter2) {
		return chCount[letter1 - 'a'] < chCount[letter2 - 'a'];
	};
	// ����ĸ���ִ���Ϊ����Ҫ�ص����ȶ���
	priority_queue<char, vector<char>, decltype(cmp)> queue;
	for (char c = 'a'; c <= 'z'; c++) {
		if (chCount[c - 'a'] > 0) {
			queue.push(c);
		}
	}
	string sub = "";
	while (queue.size() > 1) {
		char letter1 = queue.top();  queue.pop();
		char letter2 = queue.top();  queue.pop();
		sub += letter1; sub += letter2;
		int index1 = letter1 - 'a';
		int index2 = letter2 - 'a';
		chCount[index1]--;
		chCount[index2]--;
		if (chCount[index1] > 0) {
			queue.push(letter1);
		}
		if (chCount[index2] > 0) {
			queue.push(letter2);
		}
	}
	if (queue.size() > 0) {
		sub += queue.top();
	}
	return sub;
}

int main() {

	return 0;
}