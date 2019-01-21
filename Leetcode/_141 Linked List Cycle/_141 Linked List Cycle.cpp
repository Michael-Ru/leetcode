#include<stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

// ʹ�ÿ���ָ�����ʵ��O(1)�ռ临�Ӷ�
bool hasCycle(struct ListNode *head) {
	struct ListNode *f = head, *l = head;
	if (head == NULL) return false;
	while (f->next != NULL && f->next->next != NULL) {
		f = f->next->next;
		l = l->next;
		if (f == l)
			return true;
	}
	return false;
}

