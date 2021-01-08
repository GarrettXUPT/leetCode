#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

string reorganizeString(string s) {
	if (s.length() < 2) {
		return s;
	}
	vector<int> chCount(26, 0); // 在该向量中保留26个0,以位置信息为代表的字符，取值为出现的次数
	int maxCount = 0;
	const char* ch = s.c_str();
	while (*ch != '\0') {
		chCount[*ch - 'a']++;
		maxCount = max(maxCount, chCount[*ch - 'a']);
		ch++;
	}
	if (maxCount > (s.length() + 1) / 2) {  // 当字母的最大次数超过该值，那么就不可能出现重构的情况
		return "";
	}

	// 出现次数之间的比较，letter1出现的次数小于letter2出现的次数
	auto cmp = [&](const char& letter1, const char& letter2) {
		return chCount[letter1 - 'a'] < chCount[letter2 - 'a'];
	};
	// 以字母出现次数为决定要素的优先队列
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