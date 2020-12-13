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
	二叉树
	深度优先遍历树的所有节点
	时间复杂度为O(n)，空间复杂度为O(1)
*/
int countNode1(TreeNode* root) {
	if (!root) {
		return 0;
	}
	return countNode1(root->left) + countNode1(root->right) + 1;
}

/*
	完全二叉树：除了最有一层以外，其余层全部铺满，且最后一层向左停靠
	1、若根节点的左子树等于右子树深度，则说明左子树为满二叉树
	2、若根节点的左子树深度大于右子树深度，则右子树为满二叉树
	3 << 2 = 12即为3 * pow(2, 2)

	若知道子树为满子树，那么该子树的节点数量为(1 << depth - 1)，然后对另一个子树进行递归
	时间复杂度为O(long n * log n)，空间复杂度为O(1)
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