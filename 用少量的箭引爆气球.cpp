#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMinArrawShots(vector<vector<int> >& points) {
	if (points.empty()) {
		return 0;
	}
	// 按首二元组的结束位置进行排序
	sort(points.begin(), points.end(), [](vector<int> v1, vector<int> v2) {
		return v1[1] < v2[1];
		});

	int result = 1;
	int crtEnd = points[0][1];
	for (int i = 0; i < points.size(); ++i) {
		if (points[i][0] > crtEnd) {
			result++;
			crtEnd = points[i][1];
		}
	}
	return result;
}