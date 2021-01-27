#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/*
	单词规律：
		给定一种指定的模式和一个字符串，判断字符串是否遵循相同的规律
		这里的遵循指的是完全匹配，就是模式中的每一个字母和字符串中的每个非空单词之间存在着双向连接的规律

		先查看模式字符是否出现过，若是出现过，那么就要比较两次对应的单词是否一致
		若是没有出现过，那么检查单词有没有在以前对应过其他的模式字符，若是没有，则进行{模式字符：对应单词}的插入，若是有，则直接返回失败
		该处在提取单词以后，对模式长度与单词个数进行比较，可以得出一些结论
*/

bool wordPattern(string pattern, string s) {

	string tmp = "";
	vector<string> strVec;
	auto begin = s.begin();
	/*
		将字符串中的单词进行提取
	*/
	while (begin != s.end()) {
		if (*begin == ' ') {
			strVec.push_back(tmp);
			tmp = "";
		}
		else
		{
			tmp += *begin;
		}
		begin++;
		if (begin == s.end()) {
			strVec.push_back(tmp);
		}
	}

	/*
		若是模式的长度与单词的个数不同，那么单词不可能符合该模式
	*/
	if (strVec.size() != pattern.length()) {
		return false;
	}

	map<char, string> check;
	for (int i = 0; i < strVec.size(); ++i) {
		// 判断当前模式下的该字符在以前是否出现过
		auto iter = check.find(pattern[i]);
		// 若是出现过
		if (iter != check.end()) {
			// 若是出现过的字符对应的单词与以前对应的单词不同
			if (strVec[i] != check.at(pattern[i])) {
				return false;
			}
		}
		// 若是该模式没有出现过
		if (iter == check.end()){
			auto tmpBegin = check.begin();
			bool flag = true;
			// 观察该单词有没有对应其他的模式字符
			while (tmpBegin != check.end()){
				if (tmpBegin->second == strVec[i]) {
					flag = false;
				}
				tmpBegin++;
			}
			// 若是没有对应其他的模式字符
			if (flag == true) {
				check.insert({ pattern[i], strVec[i] });
			}
			else  // 若是对应了其他的模式字符
			{
				return false;
			}
		}
	}
	return true;
}

int main() {
	wordPattern("abba", "dog dog dog dog");
}