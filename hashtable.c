#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000


typedef struct {
	int id;
	char name[20];
}Student;

//�ؽ� ���̺� �ʱ�ȭ
void init(Student ** hashtable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashtable[i] = NULL;
	}
}
//�ؽ� ���̺��� �޸𸮸� ��ȯ
void destructor(Student** hashtable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashtable[i] != NULL) {
			free(hashtable[i]);
		}
	}
}
//�ؽ� ���̺� �� �� ������ ���� Ž������ ã���ϴ�.
int findEmpty(Student** hashtable, int id) {
	int i = id % TABLE_SIZE;
	while (1) {
		if (hashtable[i%TABLE_SIZE] == NULL) {
			return i % TABLE_SIZE;
		}
		i++;
	}
}
//Ư���� ID ���� ��Ī�Ǵ� �����͸� �ؽ� ���̺� ������ ã���ϴ�.
int search(Student** hashtable, int id) {
	int i = id % TABLE_SIZE;
	while (1) {
		if( hashtable[i % TABLE_SIZE] == NULL) return -1;
		else if (hashtable[i % TABLE_SIZE]->id == id) return i;
		i++;
	}
}
//Ư���� Ű �ε����� �����͸� ����
void add(Student** hashtable, Student* input, int key) {
	hashtable[key] = input;
}
// �ؽ� ���̺��� Ư���� Ű�� �����͸� ��ȯ
Student* getValue(Student** hashtable, int key) {
	return hashtable[key];
}
//�ؽ� ���̺� �����ϴ� ��� �����͸� ���
void show(Student** hashtable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashtable[i] != NULL) {
			printf("Ű: [%d] �̸�: [%s]\n", i, hashtable[i]->name);
		}
	}
}

int main(void) {
	Student **hashtable;
	hashtable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
	init(hashtable);

	for (int i = 0; i < INPUT_SIZE; i++) {
		Student* student = (Student*)malloc(sizeof(Student));
		student->id = rand() % 1000000;
		sprintf(student->name, "���%d", student->id);
		if (search(hashtable, student->id) == -1) {
			int index = findEmpty(hashtable, student->id);
			add(hashtable, student, index);
		}
	}
	show(hashtable);
	destructor(hashtable);
	system("pause");
	return 0;
}