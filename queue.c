#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000
#define INF 999999999

int a[SIZE];

int queue[SIZE];
int front,rear = 0;

// ť ���� �Լ�
void push(int data) {
	if (rear >= SIZE) {
		printf("ť �����÷ο찡 �߻��Ͽ����ϴ�.\n");
		return;
	}
	queue[rear++] = data;
}
// ť ���� �Լ�
void pop() {
	if (front == rear) {
		printf("ť ����÷ο찡 �߻��Ͽ����ϴ�.\n");
		return -INF;
	}
	return queue[front];
	front++;
}

void show() {
	printf("----ť�� ��-----\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("----ť�� ��-----\n");
}

int main(void) {
	push(1);
	pop();
	push(2);
	push(3);
	pop();
	show();
	system("pause");
	return 0;
}