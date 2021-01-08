#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
	深度优先搜索
	将n个城市及他们之间的关系看作图。城市是图中的节点，相连关系是图中的边，给定矩阵isConnected为图的邻接矩阵，省份为连通的数量
	计算省份总数，等价于计算图中的连通分量数，可以通过深度优先搜索或广度优先搜索实现，也可以通过并查集实现。
*/


/*
	深度优先搜索
	深度优先的思路的思路是直观的。遍历所有城市，对于每个城市，若该城市未被访问过，则从该城市开始深度优先搜索
	通过矩阵isConnected得到与该城市直接相连的城市有哪些，这些城市和该城市属于同一个连通分量，然后对这些城市继续深度优先搜索，
	直到同一个连通分量的所有城市都被访问到，即可得到一个省份。遍历完全部城市以后，即可得到连通分量的总数，即省份的总数。
	计算连通分量数
*/

void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int provinces, int i) {
	for (int j = 0; j < provinces; ++j) {
		if(isConnected[i][j] == 1 && !visited[j]) {
			visited[j] = true;
			dfs(isConnected, visited, provinces, j);
		}
	}
}

/*
	计算图中的连接数总数
*/
int findCircleNum1(vector<vector<int>>& isConnected) {
	int provinces = isConnected.size();
	vector<bool> visited(provinces);
	int circles = 0;
	for (int i = 0; i < provinces; ++i) {
		if (!visited[i]) {
			dfs(isConnected, visited, provinces, i);
			circles++;
		}
	}
	return circles;
}

/*
	广度优先搜索
	通过广度优先搜索的方法得到省份的总数。对于每个城市，如果该城市尚未被访问过，
	则从该城市开始广度优先搜索，直到同一个连通分量中的所有城市都被访问到，即可得到一个省份。
*/
int findCircleNum2(vector<vector<int>>& isConnected) {
	int provinces = isConnected.size();
	vector<bool> visited(provinces);
	int circles = 0;
	queue<int> queue;
	for (int i = 0; i < provinces; ++i) {
		if (!visited[i]) {
			queue.push(i);
			while (!queue.empty()) {
				int j = queue.front();
				queue.pop();
				visited[j] = true;
				for (int k = 0; k < provinces; ++k) {
					if (isConnected[j][k] == 1 && !visited[k]) {
						queue.push(k);
					}
				}
			}
			circles++;
		}
	}
	return circles;
}

/*
	并查集
	初始时，每个城市都属于不同的连接分量，遍历整个矩阵isConnected，若两个城市之间存在相连关系，则他们属于同一个连接分量并
	进行合并。遍历整个isConnected连接矩阵的全部元素以后，计算连通分量总数
*/

int unions(vector<int>& parents, int index1, int index2) {
	auto iter1 = findEqual(parents, index1);
	auto iter2 = findEqual(parents, index2);
	parents[iter1] = parents[iter2];
}

int findEqual(vector<int>& parents, int index) {
	if (parents[index] != index) {
		parents[index] = findEqual(parents, parents[index]);
	}
	return parents[index];
}

int findCircleNum3(vector<vector<int>>& isConnected) {
	int provinces = isConnected.size();
	
	// 开始位置集合
	vector<int> parents(provinces);
	for (int i = 0; i < provinces; ++i) {
		parents[i] = i;
	}
	// 遍历所有元素
	for (int i = 0; i < provinces; ++i) {
		for (int j = i + 1; j < provinces; ++j) {
			if (isConnected[i][j]) {
				unions(parents, i, j);
			}
		}
	}
	// 计算循环分量数量
	int circles = 0;
	for (int i = 0; i < provinces; ++i) {
		if (parents[i] == 1) {
			circles++;
		}
	}
	return circles;
}