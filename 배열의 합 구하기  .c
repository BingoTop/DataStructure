#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int sum(int *a, int n) {
	int i;
	int sum = 0;
	for (i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

int main(void) {
	int n, i;
	int result =0;
	int *a;
	printf("�迭 ������ �Է��Ͽ� �ּ���: ");
	scanf("%d", &n);
	a = calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		printf("x[%d]:", i);
		scanf("%d", &a[i]);
	}
	result = sum(a, n);
	printf("�迭�� ���� %d�Դϴ�.\n ", result);
	free(a);
	system("pause");
	
}