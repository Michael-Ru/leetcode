#include<stdio.h>
#include<malloc.h>

struct TreeNode {
	int val;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;

};

// ���޶԰��֣�ȡ��ÿ�ζ�ȡ���м�Ԫ����Ϊһ���ڵ㽫��������Ϊ����
struct TreeNode* sortedSubArrayToBST(struct TreeNode* nums, int start, int end) {
	int mid=0;
	switch (end - start)
	{
	case 3:
		mid = (end + start - 1) / 2;
		nums[mid].left = &(nums[mid - 1]);
		nums[mid].right = &(nums[mid + 1]);
		return &(nums[mid]);
		break;
	case 2:
		mid = (end + start) / 2;
		nums[mid].left = &(nums[mid - 1]);
		return &(nums[mid]);
		break;
	case 1:
		return &(nums[start]);
		break;
	case 0:
		return NULL;
	default:
		mid = (end + start) / 2;
		nums[mid].left = sortedSubArrayToBST(nums, start, mid);
		nums[mid].right = sortedSubArrayToBST(nums, mid+1, end);
		return &(nums[mid]);
		break;
	}
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	// ���Ƚ�ÿ��Ԫ���������ڵ�,������ÿ�����ڵ㵽һ��������
	struct TreeNode *t = (struct TreeNode *) malloc(sizeof(struct TreeNode) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		t[i].val = nums[i];
		t[i].left = NULL;
		t[i].right = NULL;
	}

	/* ��������Ϊ���صĽڵ������е�Ԫ�ص�ַ��oj�޷�free()�����
	����һ���м����temp�����ڵ�ֵ�滻���ڵ������һ���ϣ�Ȼ��
	���ؽڵ������׵�ַ������oj��Ȼfree()����*/
	struct TreeNode temp;
	temp = *sortedSubArrayToBST(t, 0, numsSize);
	t[numsSize / 2] = t[0];
	t[0] = temp;
	t[1].left = &(t[numsSize / 2]);

	return t;
}

int main() {
	int nums[] = { -10,-3,0,5,9, 12, 16 };
	struct TreeNode* tree;
	tree = sortedArrayToBST(nums, 7);
	free(tree);
}