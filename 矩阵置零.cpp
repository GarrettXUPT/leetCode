#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	vector<vector<int>> check;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == 0) {
				check.push_back({ i, j });
			}
		}
	}
	for (auto& ele : check) {
		for (int i = 0; i < matrix[0].size(); ++i) {
			matrix[ele[0]][i] = 0;
		}
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i][ele[1]] = 0;
		}
	}
}