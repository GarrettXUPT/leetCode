#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0) {
		return false;
	}
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == target) {
				return true;
			}
			else if (matrix[i][j] > target) {
				return false;
			}
		}
	}
	return false;
}

int main() {

	return 0;
}