#include <iostream>
using namespace std;


struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : value(0), left(nullptr), right(nullptr) {}
	TreeNode(int value) : value(value), left(NULL), right(NULL) {}
	TreeNode(int value, TreeNode* left, TreeNode* right) : value(value), left(left), right(right) {}
};

int getHeight(TreeNode* root) {
	if (root == NULL) return -1;

	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	if (abs(leftHeight - rightHeight) > 1) {
		return -2;
	}
	return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
	return getHeight(root) != -2;
}


int main() {
	TreeNode* t6 = new TreeNode(6, NULL, NULL);
	TreeNode* t10 = new TreeNode(6, NULL, NULL);
	TreeNode* t7 = new TreeNode(7, NULL, NULL);
	TreeNode* t8 = new TreeNode(8, t6, t7);
	TreeNode* t9 = new TreeNode(9, NULL, NULL);
	TreeNode* t3 = new TreeNode(3, t9, t8);
	TreeNode* t4 = new TreeNode(4, NULL, NULL);
	TreeNode* t5 = new TreeNode(5, NULL, NULL);
	TreeNode* t2 = new TreeNode(2, t4, t5);
	TreeNode* t1 = new TreeNode(1, t2, t3);

	/*
				 1
				/ \
			   /   \
			  2     3
			 / \   / \
			4   5 9   8
					 / \
					6   7
	*/

	cout << "1st Tree Balanced? " << (isBalanced(t1) ? "True" : "False") << endl;

	t7->left = t10;

	/*
				 1
				/ \
			   /   \
			  2     3
			 / \   / \
			4   5 9   8
					 / \
					6   7
						 \
						  10
	*/

	cout << "2nd Tree Balanced? " << (isBalanced(t1) ? "True" : "False") << endl;

	return 0;
}