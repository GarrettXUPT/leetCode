#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {

}