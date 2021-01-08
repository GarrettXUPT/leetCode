#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : left(nullptr), right(nullptr) {};
};

/*
	������
	������ȱ����������нڵ�
	ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
*/
int countNode1(TreeNode* root) {
	if (!root) {
		return 0;
	}
	return countNode1(root->left) + countNode1(root->right) + 1;
}

/*
	��ȫ����������������һ�����⣬�����ȫ�������������һ������ͣ��
	1�������ڵ��������������������ȣ���˵��������Ϊ��������
	2�������ڵ����������ȴ�����������ȣ���������Ϊ��������
	3 << 2 = 12��Ϊ3 * pow(2, 2)

	��֪������Ϊ����������ô�������Ľڵ�����Ϊ(1 << depth - 1)��Ȼ�����һ���������еݹ�
	ʱ�临�Ӷ�ΪO(long n * log n)���ռ临�Ӷ�ΪO(1)
*/

int countLevel(TreeNode* root) {
	int levels = 0;
	while(root) {
		root = root->left;
		levels++;
	}
	return levels;
}

int countNodes(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int left_levels = countLevel(root->left);
	int right_levels = countLevel(root->right);
	if (left_levels == right_levels) {
		return countNodes(root->right) + (1 << left_levels);
	}
	else {
		return (1 << right_levels) + countNodes(root->left);
	}
}

int main() {
	int a = 3 << 3;
	cout << a << endl;
	return 0;
}