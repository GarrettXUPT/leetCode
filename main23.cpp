#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
	四数之和
	四个向量中数的组合，最终结果为0
	A[i] + B[j] + C[k] + D[n] = 0
*/

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int resCount = 0;
	unordered_map<int, int>countAB; // 键为计算结果，值为该结果出现的次数
	for (auto u : A) {
		for (auto v : B) {
			countAB[u + v]++;
		}
	}

	for (auto u : C) {
		for (auto v : D) {
			if(countAB.count(-u - v)) {  
				resCount += countAB[-u - v];
			}
		}
	}
	return resCount;
}

int main() {
	vector<vector<int>> vec{ {1, 2}, {-2, -1}, {-1, 2}, {0, 2} };
	cout << fourSumCount(vec[0], vec[1], vec[2], vec[3]) << endl; 
}