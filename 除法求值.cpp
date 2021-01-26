#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

/*
	除法求值：
	给定一个变量数组equation和实数值数组value作为已知条件
	其中equations[i] = [Ai, bi] 及values[i]，每个Ai和Bi都是一个表示单变量的字符串
*/

/*
	广度优先搜索
	1、将该问题建模为一张图，给定图中的一些点(变量)，以及某些边的权值(两个变量的比例)，试图对任意两点求其路径长
	2、遍历等式数组，找出所有不同的字符串，并通过哈希表将每个不同的字符串映射为整数
	3、完成构图以后，对于任何一个·查询，就可以从起点出发，通过广度优先搜索方式，不断更新起点与当前路径之间的路劲长度，知道搜索到终点为止
*/

vector<double> calcuEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	int nvars = 0;
	unordered_map<string, int> variables;

	int n = equations.size();
	// 将等式中的变量的个数进行记录及本身进行记录
	for (int i = 0; i < n; ++i) {
		if (variables.find(equations[i][0]) == variables.end()) {
			variables[equations[i][0]] = nvars++;
		}
		if (variables.find(equations[i][1]) == variables.end()) {
			variables[equations[i][1]] = nvars++;
		}
	}

	// 对于每一个点，存储其直接连接到所有点的权值
	vector<vector<pair<int, double>>> edges(nvars);
	for (int i = 0; i < n; ++i) {
		int va = variables[equations[i][0]], vb = variables[equations[i][1]];
		edges[va].push_back(make_pair(vb, values[i]));
		edges[vb].push_back(make_pair(va, 1.0 / values[i]));
	}

	vector<double> ret;
	for (const auto& ele : queries) {
		double result = -1;
		// 问题数组中两个变量在已存的变量中存在，若是不存在，则返回值就是-1
		if (variables.find(ele[0]) != variables.end() && variables.find(ele[1]) != variables.end()) {
			int ia = variables[ele[0]], ib = variables[ele[1]];
			if (ia == ib) {
				result = 1.0;
			}
			else
			{
				queue<int> points;
				points.push(ia);
				vector<double> ratios(nvars, -1.0);
				ratios[ia] = 1.0;
				while (!points.empty() && ratios[ib] < 0) {
					int x = points.front();
					points.pop();
					// 查询与该点的连接线，进行广度遍历，知道找到ib
					for (const auto ele : edges[x]) {
						if (ratios[ele.first] < 0) {
							ratios[ele.first] = ratios[x] * ele.second;
							points.push(ele.first);
						}
					}
				}
				result = ratios[ib];
			}
		}
		ret.push_back(result);
	}
	return ret;
}

