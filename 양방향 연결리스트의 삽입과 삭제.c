#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
}Node;

Node *head, *tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node)); //��� �޸� �Ҵ�
	node->data = data; //��忡 ������ ����
	Node* cur; //���縦 ����Ű�� ��带 ����
	cur = head->next; //��� ��� �������� ��ġ ����
	while (cur ->data <data &&cur != tail) { // ��ȸ�ϰ� �ִ� �����Ͱ� �����ͺ��� �۰� ��ȸ�ϰ� �ִ� cur�� tail�� �ƴҶ�����
		cur = cur->next; // cur�� ��� �������� �̵�
	}
	Node* prev = cur->prev; //prev��带 ����� �� ����� ��ġ�� ���� ����� prev
	prev->next = node; //prev ���� ���� node�� ����
	node->prev = prev; //node ���� ���� prev�� ����
	node->next = cur; //node ���� ���� cur�� ����
	cur->prev = node; //cur ���� ���� ���� ����
}

void removeFront() {
	Node* node = head->next; //���� head�� �������� ����
	head->next = node->next; //head ������ node�� �������� ����
	Node* next = node->next; //next ���� node�� next ���� ����
	next->prev = head; //next ���� ���� head�� ����
	free(node);
}
void show() {
	Node* cur = head->next; //cur ��带 head �������� ���� 
	while (cur != tail) { //tail�� �ƴ� ������ ��ȸ�ϸ鼭 cur�� �����͸� ���
		printf("%d ", cur->data);
		cur = cur->next; //�ݺ��� ������ cur �������� ����
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	removeFront();
	show();
	system("pause");
	return 0;
}
