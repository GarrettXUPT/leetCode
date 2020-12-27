#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>

using namespace std;

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

bool wordBreak(string s, vector<string>& wordDict) {
	auto wordDictSet = unordered_set <string>();
	for (auto word : wordDict) {
		wordDictSet.insert(word);
	}
	auto dp = vector <bool>(s.size() + 1);
	dp[0] = true;  // ¿Õ´®¼´ÎªÕæ
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