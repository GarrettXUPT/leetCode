#include<iostream>
#include<vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int ret = 0;
	int n = heights.size();
	for (int left = 0; left < n; ++left) {
		int minHeight = INT_MAX;
		for (int right = left; right < n; right++) {
			minHeight = min(minHeight, heights[right]);
			ret = max(ret, (right - left + 1) * minHeight);
		}
	}
	return ret;
}