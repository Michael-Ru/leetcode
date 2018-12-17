#include <stdio.h>
#include "malloc.h"


//ֱ���ϴ��еĴ�
/*
˼·�ǽ���һ��map���飬mapԪ����nums��Ӧ��Ԫ�ص��±꣬map�±�Ϊ
numsԪ����nums��Сֵ�Ĳ
�����ԭ����Ϊnums��Сֵ������ֱ��ʹ��0���ǿ��ǵ����������
*/
int* twoSum(int* nums, int numsSize, int target) {
	int i, min = nums[0], max = nums[0];
	//�ҳ����ֵ����Сֵ
	for (i = 0; i < numsSize; i++) {
		if (nums[i] > max) max = nums[i];
		if (nums[i] < min) min = nums[i];
	}
	//��Ϊmap���±�Ϊ���룬���map�Ĵ�С��Ϊ������+1���ɡ�
	int *map = (int*)calloc((max - min + 1), sizeof(int));
	int *twosum = (int*)malloc(sizeof(int) * 2);
	// ÿɨ��һ��numsԪ�أ�����Ԫ�ص��±�;����¼��map��
	for (i = 0; i < numsSize; map[nums[i] - min] = ++i) {
		int lookfornum = target - nums[i];
		if (lookfornum<min || lookfornum>max)
			continue;
		int dis = lookfornum - min;
		// �ж�Ŀ��������Ƿ��Ѿ�������ֵ
		if (map[dis] != 0) {
			twosum[0] = i;
			twosum[1] = map[dis] - 1;
			break;
		}
	}

	return twosum;
}