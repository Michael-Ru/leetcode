#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

/*����һ�����нṹ*/
typedef struct
{
	int* data;
	int front;
	int rear;
}Myqueue;

/*���еĳ�ʼ��*/
void initqueue(Myqueue* q, int maxSize)
{
	q->data = (int*)malloc(sizeof(int) * maxSize);
	q->front = 0;
	q->rear = 0;
}

/*���*/
void Enqueue(Myqueue* q, int x)
{
	q->data[q->rear++] = x;
}

/*����*/
int Dequeue(Myqueue* q)
{
	return q->data[q->front++];
}

/*����Ϊ�գ�����1���ǿշ���0*/
int is_queue_empty(Myqueue* q)
{
	return q->rear == q->front ? 1 : 0;
}

/*�ص����е���λ*/
void queuetop(Myqueue* q)
{
	q->front = 0;
	q->rear = 0;
}

/*����һ��ջ�Ľṹ�����ж���q1������ջ�� ����q2������ջ*/
typedef struct
{
	Myqueue* q1;
	Myqueue* q2;
} MyStack;

/** Initialize your data structure here. */
/*��ʼ��ջ*/
MyStack* myStackCreate(int maxSize)
{
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	stack->q1 = (Myqueue*)malloc(sizeof(Myqueue));
	initqueue(stack->q1, maxSize);
	stack->q2 = (Myqueue*)malloc(sizeof(Myqueue));
	initqueue(stack->q2, maxSize);
	return stack;
}

/** Push element x onto stack. */
/*��Ԫ��x����ջ�У����Ƕ���q1�Ĺ���*/
void myStackPush(MyStack* obj, int x)
{
	Enqueue(obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
/*��������������ȰѶ���q1�г������һ��Ԫ�������ȫ����Ԫ�ض��������q2�У�Ȼ���q1�еĽ�ʣ����һ��Ԫ�ط��أ����������ջ��
�����ȳ���ԭ���ˣ������ٰѶ���q2�е�Ԫ��ȫ���ֲ��ظ�q1������Ķ���q2��ʵ�͸�����ת���ѣ����������ֱ�ؿյģ��ͳ�ʼ״̬һ��*/
int myStackPop(MyStack* obj)
{
	int tmp;
	if (is_queue_empty(obj->q1)) //���Ⱦ�Ҫ�ж�q1�Ƿ�Ϊ�գ�q1�Ǹ�����ջ�����ģ���Ȼ��ջҲ�����ݣ�����ջ��ȫ���������������ˣ��ǻ�pop����
	{
		return 0;
	}
	else
	{
		while (obj->q1->front != obj->q1->rear - 1) //����q1������һ��Ԫ�أ�����ȫ��q2.
		{
			Enqueue(obj->q2, Dequeue(obj->q1));
		}
		tmp = Dequeue(obj->q1); //q1������һ��Ԫ�ظ�tmp
		queuetop(obj->q1);      //q1�ص�����
		while (!is_queue_empty(obj->q2)) //��q2�е�ȫ��Ԫ���ֻ���q1
		{
			Enqueue(obj->q1, Dequeue(obj->q2));
		}
	}
	return tmp;
}

/** Get the top element. */
/*�ص�ջ�Ķ�������ʵ���ǻص�q1����������Ϊ��ջ�Ĳ���ȫ��q1������*/
int myStackTop(MyStack* obj)
{
	return obj->q1->data[obj->q1->rear - 1];
}

/** Returns whether the stack is empty. */
/*�ǲ��ǿգ���q1�����ˣ���Ϊq1������ջ����*/
bool myStackEmpty(MyStack* obj)
{
	return is_queue_empty(obj->q1);
}

void myStackFree(MyStack* obj)
{
	free(obj->q1->data);
	free(obj->q1);
	free(obj->q2->data);
	free(obj->q2);
	free(obj);
}

