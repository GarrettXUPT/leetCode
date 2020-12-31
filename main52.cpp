#include<iostream>
#include<vector>

using namespace std;

/*
	最后一个单词的长度
*/

int lengthOfLastWorld(string s) {
	int resCount = 0;
	s.erase(s.find_last_not_of(" ") + 1);  // 去除后面的空白
	auto rbegin = s.rbegin();
	while ( resCount != s.length() && *rbegin != '\0' &&*rbegin != ' ') {
		resCount++;
		rbegin++;
	}
	return resCount;
}

int main() {
	cout << lengthOfLastWorld("a ") << endl;
	return 0;
}