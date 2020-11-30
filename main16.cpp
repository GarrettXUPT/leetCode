#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int len = intervals.size();
	if (len == 1) {
		return intervals;
	}
	else if (len == 0) {
		return {};
	}
	sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
		return v1[0] < v2[0];
		});

	set<int> check;
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (intervals[i][1] >= intervals[j][0]) {
				intervals[i][1] = intervals[j][1] > intervals[i][1] ? intervals[j][1] : intervals[i][1];
				check.insert(j);
			}
		}
	}

	vector<vector<int>> ret;
	for (int i = 0; i < intervals.size(); ++i) {
		auto begin = check.begin();
		while (begin != check.end()) {
			if (i == *begin) {
				break;
			}
			begin++;
		}
		if (begin == check.end()) {
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