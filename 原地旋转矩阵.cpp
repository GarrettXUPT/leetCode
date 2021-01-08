#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int> >& matrix) {
	int len = matrix.size();

	// 翻转行
	for (int i = 0; i < len; ++i) {
		for (int j = i; j < len; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	// 翻转列
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len / 2; j++) {
			swap(matrix[i][j], matrix[i][len - j - 1]);
		}
	}
}

int main() {
	return 0;
}