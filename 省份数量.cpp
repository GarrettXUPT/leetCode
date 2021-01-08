#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
	�����������
	��n�����м�����֮��Ĺ�ϵ����ͼ��������ͼ�еĽڵ㣬������ϵ��ͼ�еıߣ���������isConnectedΪͼ���ڽӾ���ʡ��Ϊ��ͨ������
	����ʡ���������ȼ��ڼ���ͼ�е���ͨ������������ͨ�������������������������ʵ�֣�Ҳ����ͨ�����鼯ʵ�֡�
*/


/*
	�����������
	������ȵ�˼·��˼·��ֱ�۵ġ��������г��У�����ÿ�����У����ó���δ�����ʹ�����Ӹó��п�ʼ�����������
	ͨ������isConnected�õ���ó���ֱ�������ĳ�������Щ����Щ���к͸ó�������ͬһ����ͨ������Ȼ�����Щ���м����������������
	ֱ��ͬһ����ͨ���������г��ж������ʵ������ɵõ�һ��ʡ�ݡ�������ȫ�������Ժ󣬼��ɵõ���ͨ��������������ʡ�ݵ�������
	������ͨ������
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
	����ͼ�е�����������
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
	�����������
	ͨ��������������ķ����õ�ʡ�ݵ�����������ÿ�����У�����ó�����δ�����ʹ���
	��Ӹó��п�ʼ�������������ֱ��ͬһ����ͨ�����е����г��ж������ʵ������ɵõ�һ��ʡ�ݡ�
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
	���鼯
	��ʼʱ��ÿ�����ж����ڲ�ͬ�����ӷ�����������������isConnected������������֮�����������ϵ������������ͬһ�����ӷ�����
	���кϲ�����������isConnected���Ӿ����ȫ��Ԫ���Ժ󣬼�����ͨ��������
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
	
	// ��ʼλ�ü���
	vector<int> parents(provinces);
	for (int i = 0; i < provinces; ++i) {
		parents[i] = i;
	}
	// ��������Ԫ��
	for (int i = 0; i < provinces; ++i) {
		for (int j = i + 1; j < provinces; ++j) {
			if (isConnected[i][j]) {
				unions(parents, i, j);
			}
		}
	}
	// ����ѭ����������
	int circles = 0;
	for (int i = 0; i < provinces; ++i) {
		if (parents[i] == 1) {
			circles++;
		}
	}
	return circles;
}