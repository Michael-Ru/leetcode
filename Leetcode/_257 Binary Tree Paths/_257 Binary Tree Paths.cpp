#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// ����ת��,[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
struct TreeNode* arrayToTree(int* nums, int numsSize) {
	// ��ֵΪnullNode ��Ԫ�ؽ�����Ϊ�˴��޺���
	const int nullNode = 0;
	struct TreeNode* tree = (struct TreeNode*)calloc(0, sizeof(struct TreeNode)*numsSize);
	for (int i = 0; i < numsSize; i++) {
		tree[i].val = nums[i];
		if (i * 2 + 1 < numsSize && nums[i * 2 + 1] != nullNode)
			tree[i].left = &(tree[i * 2 + 1]);
		else
			tree[i].left = NULL;
		if (i * 2 + 2 < numsSize && nums[i * 2 + 2] != nullNode)
			tree[i].right = &(tree[i * 2 + 2]);
		else
			tree[i].right = NULL;
	}
	return tree;
}

/*���Ľ�ѵ������C�Ļ������ص�char**��������malloc�����ģ��տ�ʼ����ֱ��char bin_tree_paths[100][100]
�������˵��ִ�г�������֮���û�������ˣ���ʵ��ĿҲ˵��The returned array must be malloced*/
void dfs(struct TreeNode* root, char** bin_tree_paths, int* path, int* returnSize, int depth)
{
	int i = 0;
	path[depth++] = root->val;  //��Ҫ�����depth��depth��ÿһ���ֵ����һ���ģ����ص��Ĳ㣬depth������һ��ĵ�ֵ
	if (root->left == NULL && root->right == NULL)
	{
		bin_tree_paths[*returnSize] = (char*)malloc(sizeof(char) * 100);
		bin_tree_paths[*returnSize][0] = 0;
		for (i = 0; i < depth - 1; i++)
		{
			sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d->", bin_tree_paths[*returnSize], path[i]); //��һ������sprintf,ͦ���õ�
		}
		sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d", bin_tree_paths[*returnSize], path[i]); //���һ�����ü�ͷ
		(*returnSize)++;
		return;
	}
	
	if (root->left != NULL)
	{
		dfs(root->left, bin_tree_paths, path, returnSize, depth);
	}

	if (root->right != NULL)
	{
		dfs(root->right, bin_tree_paths, path, returnSize, depth);
	}
	return;  //������void���ͣ���ʵ��һ����дҲ��
}

char** binaryTreePaths1(struct TreeNode* root, int* returnSize)
{
	int path[100] = { 0 }, depth = 0;
	char** bin_tree_paths = (char**)malloc(sizeof(char*) * 100);
	if (root == NULL)
	{
		return NULL;
	}
	*returnSize = 0;
	dfs(root, bin_tree_paths, path, returnSize, depth);
	return bin_tree_paths;
}


/*
ע��leetcode���ύʱ��Ҫ��sprintf_s�滻Ϊsprintf��
16ms
���������û����һ��Ҷ�ڵ������һ��·����
����·����һ��·��ջ�������һ��·��ʱ������һ�����ʽڵ�ĸ߶���Ϊ����·���Ŀ�ʼ��֮ǰ��·�����Ա���
*/
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
	char** bin_tree_paths = (char**)malloc(sizeof(char*) * 100);
	if (root == NULL)		return NULL;
	*returnSize = 0;

	// �������
	struct TreeNode *stack[4096];
	int ss = 0;
	// ���ջ������ÿ���ڵ�����
	int dStack[4096] = { 0 };
	int dss = 0;
	int cd = 0;	//���浱ǰ���ʽڵ�����
	// ·��ջ
	int pathStack[4096] = {0};
	int pss = 0;

	stack[ss++] = root;
	dStack[dss++] = 0;
	while (ss) {
		// ��ջ ����
		struct TreeNode *ct = stack[--ss];
		cd = dStack[--dss];
		
		// ��ȡ��ǰ�ڵ�ĸ߶�
		pss = cd;

		// ����ýڵ㵽·��ջ
		pathStack[pss++] = ct->val;

		// ������ջ�����Һ���
		// ���ΪҶ�ڵ㣬������һ��·��
		if (!ct->left && !ct->right) {
			bin_tree_paths[*returnSize] = (char*)calloc(100, sizeof(char));
			for (int i = 0; i < pss-1; i++) {
				sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d->", bin_tree_paths[*returnSize], pathStack[i]);
			}
			sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d", bin_tree_paths[*returnSize], pathStack[pss-1]);

			(*returnSize)++;
		}
		
		if (ct->right) {
			stack[ss++] = ct->right;
			dStack[dss++] = cd + 1;
		}
			
		if (ct->left) {
			stack[ss++] = ct->left;
			dStack[dss++] = cd + 1;
		}
			
	}

	return bin_tree_paths;
}


int main() {
	int b[] = { 1,21,22,321,321,322,322,4321,4322,4,4,4,4,0,0,5,5 };
	struct TreeNode *root;
	root = arrayToTree(b, 17);
	int returnSize;
	char** res = binaryTreePaths(root, &returnSize);
	return 0;
}
