#include<vector>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	set<int> s(nums.begin(), nums.end());
	nums.assign(s.begin(), s.end());
	return nums.size();
}

int removeElement(vector<int>& nums, int val) {
	vector<int> tmp;
	for (auto& ele : nums) {
		if (ele != val) {
			tmp.push_back(ele);
		}
	}
	nums = tmp;
	return nums.size();
}


int strStr(string haystack, string needle) {
	int len = needle.length();
	if (len == 0) {
		return 0;
	}
	int i;
	int flag = 0;
	int layLen = haystack.length();
	if (len > layLen) {
		return -1;
	}
	else if (len == layLen) {
		if (haystack == needle) {
			return 0;
		}
		else {
			return -1;
		}
	}
	for (i = 0; i <= layLen - len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (haystack.at(j + i) == needle.at(j)) {
				flag++;
			}
		}
		if (flag == len) {
			return i;
		}
		flag = 0;
	}
	return -1;
	
}

int main() {
	string str = "a";
	cout << strStr(str, "ll") << endl;
	return 0;
}