#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
	贪心算法
	
*/


int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int len = intervals.size();
	if (len < 2) {
		return 0;
	}
	// 由各区间的右限有小到大排序
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {return u[1] < v[1]; });

	// 目前区间右限，确定后 与其不重合的区间就变成子问题
	int right = intervals[0][1];
	int ret = 1;  // 给不重合的区间计数
	for (int i = 1; i < len; ++i) {
		if (intervals[i][0] >= right) {  // 若与首区间不重合
			ret++;
			right = intervals[i][1];
		}
	}
	return len - ret;
}