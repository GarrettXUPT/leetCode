#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

/*
	插入区间
	给出一个五无重叠的，按照区间其实端点排序的区间列表
	在列表中插入一个新的区间，确保列表之间仍然有序但是又不互相重叠(可以允许进行区间合并)
*/

vector<vector<int>> merge(vector<vector<int>>& intervals, vector<int>& newIntreval) {
	intervals.push_back(newIntreval);
	int len = intervals.size();
	/*
		特殊情况的判定
	*/
	if (len == 1) {
		return intervals;
	}
	else if (len == 0) {
		return {};
	}
	// 以左限进行排序
	sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
		return v1[0] < v2[0];
		});

	set<int> check;
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			// 比较前右限和后左限的大小关系，若是是包含关系则对区间进行合并，对需要删除的区间进行记录
			if (intervals[i][1] >= intervals[j][0]) {
				intervals[i][1] = intervals[j][1] > intervals[i][1] ? intervals[j][1] : intervals[i][1];
				check.insert(j);
			}
		}
	}
	// 删除上一步记录下来的区间
	auto begin = check.begin();
	int n = check.size();
	int i = 0;
	while (n > 0) {
		intervals.erase(intervals.begin() + *begin  - i);
		i = 1; n--;
	}

	return intervals;
}

int main() {
	vector<vector<int>> vec{ {1,2 }, { 3,5 }, { 6,7 }, { 8,10 }, { 12,16 } };
	//vector<vector<int>> vec{ {1,3},{6,9} };
	vector<int> vec1{ 4, 8 };
	auto res = merge(vec, vec1);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}