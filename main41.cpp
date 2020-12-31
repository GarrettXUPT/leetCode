#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>

using namespace std;

/*
	单词拆分，要使用动态规划
*/

vector<int> _termLength(vector<string>& w1) {
	int maxLen = 0;
	int minLen = 9999;
	for (auto& ele : w1) {
		if (ele.size() > maxLen) {
			maxLen = ele.size();
		}
		if (ele.size() < minLen) {
			minLen = ele.size();
		}
	}
	return {maxLen, minLen};
}

bool subStrJudge(vector<string>& strVec, string str) {
	bool flag = false;
	for (auto& ele : strVec) {
		if (ele != str) {
			int i = 0;
			for (i = 0; i < str.length(); i++) {
				if (ele[i] != str[i]) {
					break;
				}
			}
			if (i == str.length()) {
				return true;
			}
		}
	}
}


bool wordBreak1(string s, vector<string>& wordDict) {
	set<string> checkSet;
	set<string> allWords{ wordDict.begin(), wordDict.end() };
	auto leng = _termLength(wordDict);
	int maxLen = leng[0];
	int minLen = leng[1];
	string strTain;
	const char* ch = s.c_str();
	string strTmp = "";
	while (*ch != '\0') {
		strTmp += *ch;
		auto iterTmp = find(wordDict.begin(), wordDict.end(), strTmp);
		if (iterTmp != wordDict.end()) {
			checkSet.insert(strTmp);
			strTain = strTmp;
			strTmp = "";
		}
		else if (strTmp.size() > maxLen) {
			return false;
		}
		ch++;
	}
	if (!strTmp.empty() && (allWords.find(strTain + strTmp) == allWords.end())) {
		return false;
	}
	else
	{
		return true;
	}
	return false;
}


/*
	动态规划解决单词拆分问题
*/

bool wordBreak(string s, vector<string>& wordDict) {
	auto wordDictSet = unordered_set <string>();
	for (auto word : wordDict) {
		wordDictSet.insert(word);
	}
	auto dp = vector <bool>(s.size() + 1);
	dp[0] = true;  // 空串即为真
	//  需要枚举s[0...i - 1]中分割点s[0,...j - 1]组成的字符串s1与s[j,...i]组成的字符串s2是否合法，若是两个都合法，那么两者拼接起来的字符串也是合法的
	// 	我们已经得到dp[0，... i - 1]的值，所以s1是否合法判断dp[j]就可以，只需要看s2是否合法即可
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.size()];
}

int main() {
	string s = "aaaaaaa";
	vector<string> vec{ "aaaa", "aaa" };
	cout << wordBreak(s, vec) << endl;
	return 0;
}