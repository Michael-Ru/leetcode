#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// ************************************      ����������Ѹ��ڵ��ֵ���ӵ��Լ��ĺ��ӵ�ֵ��ȥ 4ms     **************************************
bool hasPathSum(struct TreeNode* root, int sum) {
	int csum = 0, cv = 0;
	struct TreeNode *stack[4096];
	struct TreeNode *ct = NULL;
	int size = 0;
	if (root)
		stack[size++] = root;
	else
		return false;
	while (size) {
		// ��ջ����
		ct = stack[--size];
		cv = ct->val;
		if (cv == sum && ct->right == NULL && ct->left == NULL)
			return true;
		// ѹջͬʱ�����ýڵ��ֵ���ӵ��亢����
		if (ct->right) {
			ct->right->val += cv;
			stack[size++] = ct->right;
		}

		if (ct->left) {
			ct->left->val += cv;
			stack[size++] = ct->left;
		}
	}
	return false;
}

// ************************************      ������ 4ms     **************************************
bool isequal(struct TreeNode* root, int sum, int temp)
{
	if (root != NULL&&root->left == NULL&&root->right == NULL&&root->val + temp == sum)
	{
		return true;
	}
	if (root != NULL)
	{
		if (isequal(root->left, sum, root->val + temp))
		{
			return true;
		}
		else if (isequal(root->right, sum, root->val + temp))
		{
			return true;
		}
	}

	return false;
}

bool hasPathSum1(struct TreeNode* root, int sum)
{
	return (root != NULL&&isequal(root, sum, 0));
}
