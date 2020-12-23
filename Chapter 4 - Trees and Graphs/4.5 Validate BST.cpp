#include <iostream>
#include <limits>
using namespace std;

const int inf = numeric_limits<int>::max();

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : value(0), left(nullptr), right(nullptr) {}
	TreeNode(int value) : value(value), left(NULL), right(NULL) {}
	TreeNode(int value, TreeNode* left, TreeNode* right) : value(value), left(left), right(right) {}
};

bool validateBST(TreeNode* root, int min=-inf, int max=inf) {
	if (root == NULL) return true;
	if (root->value <= min || root->value > max) return false;
	return validateBST(root->left, min, root->value) && validateBST(root->right, root->value, max);
}


int main() {
	TreeNode* t8 = new TreeNode(17, NULL, NULL);
	TreeNode* t7 = new TreeNode(7, NULL, NULL);
	TreeNode* t6 = new TreeNode(3, NULL, NULL);
	TreeNode* t5 = new TreeNode(15, NULL, t8);
	TreeNode* t4 = new TreeNode(5, t6, t7);
	TreeNode* t3 = new TreeNode(30, NULL, NULL);
	TreeNode* t2 = new TreeNode(10, t4, t5);
	TreeNode* t1 = new TreeNode(20, t2, t3);

	/*
				 20
				/  \
			   /    \
			  10     30
			 / \   
			5   15
		   /\     \
		  3 7     17
	*/

	cout << "1st Tree BST? " << (validateBST(t1) ? "True" : "False") << endl;

	t3->right = new TreeNode(30, NULL, NULL);

	/*
				 20
				/  \
			   /    \
			  10     30
			 / \       \
			5   15      30
		   /\     \
		  3 7     17
	*/

	cout << "2nd Tree BST? " << (validateBST(t1) ? "True" : "False") << endl;

	return 0;
}