#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

/*
	������ֵ��
	����һ����������equation��ʵ��ֵ����value��Ϊ��֪����
	����equations[i] = [Ai, bi] ��values[i]��ÿ��Ai��Bi����һ����ʾ���������ַ���
*/

/*
	�����������
	1���������⽨ģΪһ��ͼ������ͼ�е�һЩ��(����)���Լ�ĳЩ�ߵ�Ȩֵ(���������ı���)����ͼ��������������·����
	2��������ʽ���飬�ҳ����в�ͬ���ַ�������ͨ����ϣ��ÿ����ͬ���ַ���ӳ��Ϊ����
	3����ɹ�ͼ�Ժ󣬶����κ�һ������ѯ���Ϳ��Դ���������ͨ���������������ʽ�����ϸ�������뵱ǰ·��֮���·�����ȣ�֪���������յ�Ϊֹ
*/

vector<double> calcuEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	int nvars = 0;
	unordered_map<string, int> variables;

	int n = equations.size();
	// ����ʽ�еı����ĸ������м�¼��������м�¼
	for (int i = 0; i < n; ++i) {
		if (variables.find(equations[i][0]) == variables.end()) {
			variables[equations[i][0]] = nvars++;
		}
		if (variables.find(equations[i][1]) == variables.end()) {
			variables[equations[i][1]] = nvars++;
		}
	}

	// ����ÿһ���㣬�洢��ֱ�����ӵ����е��Ȩֵ
	vector<vector<pair<int, double>>> edges(nvars);
	for (int i = 0; i < n; ++i) {
		int va = variables[equations[i][0]], vb = variables[equations[i][1]];
		edges[va].push_back(make_pair(vb, values[i]));
		edges[vb].push_back(make_pair(va, 1.0 / values[i]));
	}

	vector<double> ret;
	for (const auto& ele : queries) {
		double result = -1;
		// ���������������������Ѵ�ı����д��ڣ����ǲ����ڣ��򷵻�ֵ����-1
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
					// ��ѯ��õ�������ߣ����й�ȱ�����֪���ҵ�ib
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

