#include<stdio.h>
#include<malloc.h>
/**
* Definition for a binary tree node.*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

// ˼·������������ֳ������������������������ԳƷֱ������ջ������ٵ�ջ�Աȡ�
bool isSymmetric(struct TreeNode* root) {
	TreeNode *stack[4096];
	int size = 0;
	if (root == NULL) 
		return true;
	else {
		stack[0] = root;
		size++;
	}
	
	while (size) {
		// ��ջ
		size--;
		root = stack[size];
		// ����

	}
}