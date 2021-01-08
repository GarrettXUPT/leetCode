#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/*
	�����������
	�����������������λ֮�ʹ���k�ĸ��ӿ���Ϊ�ϰ���
	��Ϊ�ϰ����򶼿���(0, 0)λ�ý������������ƶ�
*/

int getValue(int x) {
	int res = 0;
	for (; x > 0; x /= 10) {
		res += x % 10;
	}
	return res;
}

int movingCount(int m, int n, int k) {
	if (k == 0) {
		return 1;
	}
	// �𰸶���
	queue<pair<int, int>> Q;
	// �������Ҽ����µķ�������
	vector<int> right{ 0, 1 };
	vector<int> down{ 1, 0 };
	vector<vector<int>> visited(m, vector<int>(n, 0));
	Q.push(make_pair(0, 0));
	visited[0][0] = 1;
	int ret = 1;
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int i = 0; i < 2; ++i) {
			int tx = p.first + right[i];
			int ty = p.second + down[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || visited[tx][ty] || getValue(tx) + getValue(ty) > k) {
				continue;
			}
			Q.push(make_pair(tx, ty));
			visited[tx][ty] = 1;
			ret += 1;
		}
	}
	return ret;

}