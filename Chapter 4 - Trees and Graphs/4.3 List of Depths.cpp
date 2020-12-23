#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : value(0), left(nullptr), right(nullptr) {}
	TreeNode(int value) : value(value), left(NULL), right(NULL) {}
	TreeNode(int value, TreeNode* left, TreeNode* right): value(value), left(left), right(right) {}
};

struct Node {
	TreeNode* treeNode;
	Node* next;
	Node() : treeNode(0), next(NULL) {}
	Node(TreeNode* value): treeNode(value), next(NULL) {}
	Node(TreeNode* value, Node* next): treeNode(value), next(next) {}
};

struct LinkedList {
	Node* head;
	LinkedList(): head(NULL) {}
	LinkedList(Node* head): head(head) {}
	void addNode(Node* newNode) {
		if (head == NULL) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
	void print() {
		Node* current = head;
		while (current != NULL) {
			cout << current->treeNode->value << " -> ";
			current = current->next;
		}
		cout << "#" << endl;
	}
};

void getListsOfDepthDFS(TreeNode* root, vector<LinkedList> &lists, int level) {
	if (root == NULL) return;
	Node* n = new Node(root);
	if (level == lists.size()) {
		LinkedList L;
		lists.push_back(L);
	}
	lists[level].addNode(n);
	getListsOfDepthDFS(root->left, lists, level + 1);
	getListsOfDepthDFS(root->right, lists, level + 1);
}

int main() {
	TreeNode* t6 = new TreeNode(6, NULL, NULL);
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
			  2     \
			 / \     3
			4   5   / \
				   9   \
						8
					   / \
					  6   7
	*/

	vector<LinkedList> lists;
	getListsOfDepthDFS(t1, lists, 0);
	for (LinkedList list:lists)
	{
		list.print();
	}
	return 0;
}
