#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

/*
	检测longStr是否含有子串subStr
	要注意subStr中可能会出现的重复字符带来的判别时候的影响
*/
bool check(string longStr, string subStr) {
	if (longStr.size() < subStr.size()) {
		return false;
	}
	int flag = 0;
	for (int i = 0; i < subStr.size(); ++i) {
		auto findflag = find(longStr.begin(), longStr.end(), subStr[i]);
		if (findflag != longStr.end()) {
			longStr.erase(findflag);
			flag++;
		}
		else {
			return false;
		}
	}
	if (flag == subStr.size()) {
		return true;
	}
	else {
		return false;
	}
}

string minWindow(string s, string t) {
	auto fast = s.begin();
	string ret = "";
	int minLength = 9999;
	string tmpVec;
	while (fast != s.end()) {
		// s从前向后增加到tmpVec中
		tmpVec.push_back(*fast);
		fast++;
		if (check(tmpVec, t)) {  // 若形成的子串tmpVec中已经含有了目标子串t
			char tmp;
			while (check(tmpVec, t)) {
				tmp = *tmpVec.begin();  // 删除从前向后子串tmpVec中字符，直至最后不含有子串
				tmpVec.erase(tmpVec.begin());
			}

			tmpVec.insert(tmpVec.begin(), tmp);
			if (tmpVec.size() < minLength) {  // 若长度比已有的短，则加入为最短子串
				minLength = tmpVec.size();
				ret = tmpVec;
			}
			tmpVec.erase(tmpVec.begin());  // 恢复到非子串状态
		}
	}
	return ret;

}

int main() {
	string s1 = "cabwefgewcwaefgcf";
	string s2 = "cae";
	cout << minWindow(s1, s2) << endl;
	return 0;
}