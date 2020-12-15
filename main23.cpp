#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
	����֮��
	�ĸ�������������ϣ����ս��Ϊ0
	A[i] + B[j] + C[k] + D[n] = 0
*/

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int resCount = 0;
	unordered_map<int, int>countAB; // ��Ϊ��������ֵΪ�ý�����ֵĴ���
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