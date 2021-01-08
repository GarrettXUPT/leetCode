#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

// 字符转数字
map<int, char> mapTrans() {
	map<int, char> numMap;
	numMap.insert(make_pair(1, 'A'));
	numMap.insert(make_pair(2, '2'));
	numMap.insert(make_pair(3, '3'));
	numMap.insert(make_pair(4, '4'));
	numMap.insert(make_pair(5, '5'));
	numMap.insert(make_pair(6, '6'));
	numMap.insert(make_pair(7, '7'));
	numMap.insert(make_pair(8, '8'));
	numMap.insert(make_pair(9, '9'));
	numMap.insert(make_pair(10, '10'));
	numMap.insert(make_pair(11, 'J'));
	numMap.insert(make_pair(12, 'Q'));
	numMap.insert(make_pair(13, 'K'));
	return numMap;
}

// 数字转字符
int charTransToInt(map<int, char> mapVec, const char ch) {
	auto begin = mapVec.begin();
	while (begin != mapVec.end()) {
		if (begin->second == ch) {
			return begin->first;
		}
		begin++;
	}
}

vector<vector<int> > permutation(vector<int> nums) {
	vector<vector<int> > retVec;
	retVec.push_back(nums);
	auto pos = nums;
	reverse(pos.begin(), pos.end());
	while (1) {
		int len = nums.size();
		int i = len - 1;
		while (i > 0 && nums[i - 1] >= nums[i]) {
			i--;
		}
		int j = len - 1;
		while (j > 0 && nums[j] <= nums[i - 1]) {
			j--;
		}
		swap(nums[i - 1], nums[j]);
		reverse(nums.begin() + i, nums.end());
		
		/*for (auto& ele : nums) {
			cout << ele << " ";
		}
		cout << endl;*/

		retVec.push_back(nums);
		if (nums == pos) {
			break;
		}
		
	}
	return retVec;
}

int calcu(int num1, int num2, char note) {
	int res;
	switch (note){
	case '+': return num1 + num2; break;
	case '-': return num1 - num2; break;
	case '*': return num1 * num2; break;
	case '/': res = (num1 / num2); return res; break;
	default:
		break;
	}
}

vector<vector<char> > noteVec() {
	vector<vector<char> > ret;
	vector<char> vec{'+', '-', '*', '/'};
	int len = vec.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			for (int k = 0; k < len; ++k) {
				ret.push_back({ vec[i], vec[j], vec[k] });
			}
		}
	}
	return ret;
}

string compute(vector<vector<int> > permutation, vector<vector<char> > noteVecRes) {

	for (auto& ele : permutation) {
		for (auto& elem : noteVecRes) {
			int tmp = calcu(ele[0], ele[1], elem[0]);
			tmp = calcu(tmp, ele[2], elem[1]);
			tmp = calcu(tmp, ele[3], elem[2]);
			if (tmp == 24) {
				char ch[10] = { mapTrans().at(ele[0]), elem[0], mapTrans().at(ele[1]) ,elem[1] , mapTrans().at(ele[2]), elem[2], mapTrans().at(ele[3]) };
				return ch;
			}
		}
	}
	return "None";
}

string conclusion(string str) {
	if (str.length() > 11) { // 若字符串中存在大小王
		return "ERROR";
	}
	auto mapVec  = mapTrans();
	const char* ch = str.c_str();
	vector<int> intVec;
	while (*ch != '\0') {
		if (*ch != ' ' && 48 <= *(ch + 1) && *(ch + 1) <= 57) {
			intVec.push_back(charTransToInt(mapVec, *ch) * 10 + charTransToInt(mapVec, *(ch + 1)));
			ch++;
		}
		else if (*ch != ' ') {
			intVec.push_back(charTransToInt(mapVec, *ch));
		}
		ch++;
	}
	sort(intVec.begin(), intVec.end());

	auto permuVec = permutation(intVec);
	auto noteVecRes = noteVec();
	string res = compute(permuVec, noteVecRes);
	return res;
}


int main() {
	auto res = conclusion("2 7 J Q");
	cout << res << endl;

	return 0;
}