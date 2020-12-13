#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*]
	上升下降字符串
*/

char findBiger(vector<char>& chvec, char& ch2) {
	auto begin = chvec.begin();
	while (begin != chvec.end()) {
		if (ch2 < *begin && *begin != ch2) {
			break;
		}
		begin++;
	}
	if (begin != chvec.end()) {
		char tmp = *begin;
		chvec.erase(begin);
		return tmp;
	}
	return ' ';
}

char findLess(vector<char>& chvec, char& ch2) {
	auto begin = chvec.rbegin();
	while (begin != chvec.rend()) {
		if (ch2 > * begin && *begin != ch2) {
			break;
		}
		begin++;
	}
	if (begin != chvec.rend()) {
		char tmp1 = *begin;
		chvec.erase(find(chvec.begin(), chvec.end(), tmp1));
		return tmp1;
	}
	return ' ';
}

string sortString(string s) {
	const char* ch = s.c_str();
	char* chArr = (char*)malloc(sizeof(char) * s.length() + 1);
	memset(chArr, 0, s.length() + 1);
	vector<char> chVec;
	while (*ch != '\0') {
		chVec.push_back(*ch);
		ch++;
	}
	int k = 0;
	sort(chVec.begin(), chVec.end());
	while (!chVec.empty())
	{
		auto minIter = min_element(chVec.begin(), chVec.end());  // 获取最小的字符
		auto minPos = *minIter;  // 记录最小的字符
		chVec.erase(minIter);  // 将该字符从字符列表中去除

		while (1) {
			if (minPos != ' ') {
				chArr[k] = minPos;
				k++;
				minPos = findBiger(chVec, minPos);  // 寻找比当前最小字符大一的字符
			}
			else {
				break;
			}
		}
		if (chVec.empty()) {
			break;
		}
		auto maxIter = max_element(chVec.begin(), chVec.end());  // 获取最大的字符
		auto maxPos = *maxIter;  // 记录最大的字符
		chVec.erase(maxIter);  // 将该字符从字符数组中去除
		while (1) {
			if (maxPos != ' ') {
				chArr[k] = maxPos;
				k++;
				maxPos = findLess(chVec, maxPos);
			}
			else {
				break;
			}
		}
	}
	return chArr;
}

int main() {
	cout << sortString("leetcode") << endl;
	return 0;
}