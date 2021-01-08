#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/*
	广度优先搜索
	将行坐标和列坐标数位之和大于k的格子看作为障碍物
	因为障碍区域都可由(0, 0)位置进行向下向右移动
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
	// 答案队列
	queue<pair<int, int>> Q;
	// 定义向右及向下的方向数组
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