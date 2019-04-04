

typedef struct {
	int ptr; //������
	int max; //�뷮
	int *stk; //������ ù ��ҿ� ���� ������
}Stack;

int Initialize(Stack *s, int max);
int isEmpty(const Stack *s);
int Push(Stack *s, int data);
int Pop(Stack *s, int *data);
void Terminate(Stack *s);