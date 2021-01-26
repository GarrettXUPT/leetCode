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

/*
	对输入数组进行全排列
*/
vector<vector<int> > permutation(vector<int> nums) {
	// 设立返回数组
	vector<vector<int> > retVec;
	// 将开始数组放入返回数组中
	retVec.push_back(nums);
	// 设立最后一种排列情况，当排列结果与其相同，则说明已经做到全排列
	auto pos = nums;
	reverse(pos.begin(), pos.end());
	while (1) {
		int len = nums.size();
		int i = len - 1;
		// 寻找反向递减的第一个元素
		while (i > 0 && nums[i - 1] >= nums[i]) {
			i--;
		}
		// 寻找比已知反向递减元素大的第一个元素
		int j = len - 1;
		while (j > 0 && nums[j] <= nums[i - 1]) {
			j--;
		}
		// 交换两个已知元素
		swap(nums[i - 1], nums[j]);
		// 从反向递减第一个元素向后的数组进行反转
		reverse(nums.begin() + i, nums.end());
		
		/*for (auto& ele : nums) {
			cout << ele << " ";
		}
		cout << endl;*/
		// 将结果放入返回数组中
		retVec.push_back(nums);
		// 停止条件
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

/*
	对操作符的组合情况进行遍历，即四个操作符选三个出来
*/
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

/*
	将两个遍历结果，再次进行组合，寻找完成24点的组合
*/
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
	/*
		判断字符串中是否存在大小王，若存在，则直接返回错误
	*/
	if (str.length() > 11) { // 若字符串中存在大小王
		return "ERROR";
	}
	auto mapVec  = mapTrans();
	const char* ch = str.c_str();
	vector<int> intVec;
	/*
		将字符串中的内容，依照规则，转化为数字，便于进一步处理
	*/
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
	/*
		将转化的来的数字进行排序
	*/
	sort(intVec.begin(), intVec.end());

	/*
		得到所有的数字排列组合结果
	*/
	auto permuVec = permutation(intVec);

	/*
		将操作符的排列组合进行遍历
	*/
	auto noteVecRes = noteVec();

	/*
		将·两个遍历结果进行组合，获得达到24点的结果
	*/
	string res = compute(permuVec, noteVecRes);
	return res;
}


int main() {
	auto res = conclusion("2 7 J Q");
	cout << res << endl;

	return 0;
}