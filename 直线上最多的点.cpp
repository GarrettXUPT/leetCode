#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int getPlus(map<vector<int>, int>p1, map<vector<double, double>, set<vector<int>>>::iterator p2) {
	int ret = 0;
	auto begin1 = p2->second.begin();
	while (begin1 != p2->second.end()) {
		ret += (p1[*begin1] - 1);
		begin1++;
	}
	return ret;
}

vector<double, double> parameter1(vector<int> vec1, vector<int> vec2) {
	if (vec1[0] - vec2[0] == 0) {
		return vector<double, double>{ INT16_MAX, 0 };
	}
	double k = double(vec1[1] - vec2[1]) / double(vec1[0] - vec2[0]);
	double b = vec1[1] - k * vec1[0];
	return vector<double, double>{ k, b };
}

int maxPoints(vector<vector<int>>& points) {
	int len = points.size();
	if (len < 3) {
		return len;
	}
	map<vector<double, double>, set<vector<int>>> check;
	map<vector<int>, int> flagVec;
	for (auto& ele : points) {
		if (flagVec.find(ele) != flagVec.end()) {
			flagVec.at(ele)++;
		}
		else
		{
			flagVec.insert({ ele , 1 });
		}
	}
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 1 + i; j < len; ++j) {
			auto res = parameter1(points[i], points[j]);
			if (check.find(res) != check.end()) {
				check.at(res).insert(points[i]);
				check.at(res).insert(points[j]);
			}
			else
			{
				if (res[0] == INT16_MAX) {
					check.insert({ {res[0] - points[i][0], res[1]}, {points[i], points[j]} });
				}
				else
				{
					check.insert({ res, {points[i], points[j]} });
				}
			}
		}
	}
	int max = 0;
	auto begin = check.begin();
	while (begin != check.end()) {
		if (begin->second.size() > max) {
			max = begin->second.size() + getPlus(flagVec, begin);
		}
		cout << "k = " << begin->first[0] << " " << " b = " << begin->first[1] << endl;
		for (auto& ele : begin->second) {  
			for (auto& elem : ele) {
				cout << elem << " ";
			}
			cout << endl;
		}
		begin++;
	}
	return max;
}
// cout << k << "  " << points[i][0] << ", " <<points[i][1] << "  " << points[j][0] << ", " <<points[j][1] << endl;

int main() {
	
	return 0;
}

