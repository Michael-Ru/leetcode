#include<stdio.h>
//�Ƚϼ򵥲���׸��
int removeElement(int* nums, int numsSize, int val) {
	int hot = 0;
	for (int i = 0; i<numsSize; i++){
		if (nums[i] != val){
			nums[hot++] = nums[i];
		}
	}
	return hot;
}

