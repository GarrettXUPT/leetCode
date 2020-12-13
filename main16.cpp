#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

/*
	合并区间
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int len = intervals.size();
	if (len == 1) {
		return intervals;
	}
	else if (len == 0) {
		return {};
	}

	// 根据各数组的开始位置进行排序
	sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
		return v1[0] < v2[0];
		});

	set<int> check;
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			// 若前区间结尾包含于后区间开始
			if (intervals[i][1] >= intervals[j][0]) {
				intervals[i][1] = intervals[j][1] > intervals[i][1] ? intervals[j][1] : intervals[i][1];
				check.insert(j);  // 将需要删除的位置记录下来
			}
		}
	}


	vector<vector<int>> ret;
	for (int i = 0; i < intervals.size(); ++i) {
		auto begin = check.begin();
		while (begin != check.end()) {
			if (i == *begin) {  // 若保存有待删的位置
				break;
			}
			begin++;
		}
		if (begin == check.end()) {  // 若没有待删位置
			ret.push_back(intervals[i]);
		}
	}
	
	return ret;
}

int main() {
	vector<vector<int>> vec{ {2,3 }, { 4,5 }, { 6,7 }, { 8,9 }, { 1,10 }};
	auto res = merge(vec);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}