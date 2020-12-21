#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
void preOrderPrint(TreeNode* T) {
	if (T == NULL) return;
	preOrderPrint(T->left);
	cout << T->val << " ";
	preOrderPrint(T->right);
}

TreeNode* minimalTree(vector<int> v) {
	if (v.empty()) return NULL;
	if (v.size() == 1) {
		return new TreeNode(v[0]);
	}
	int middleElement = v[v.size() / 2];
	TreeNode* t = new TreeNode(middleElement);
	vector<int> leftBranch(v.begin(), v.begin() + v.size() / 2);
	vector<int> rightBranch(v.begin() + v.size() / 2 + 1, v.end());
	t->left = minimalTree(leftBranch);
	t->right = minimalTree(rightBranch);
	return t;
}


int main() {
	vector<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6 };
	preOrderPrint(minimalTree(v1));
	cout << endl;
	preOrderPrint(minimalTree(v2));
	return 0;
}