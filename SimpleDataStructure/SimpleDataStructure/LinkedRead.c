#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void) 
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode;
	int readData;

	while (1) 
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;
		tail = newNode;
	}

	if (head == NULL)
		printf("저장된 데이터가 없습니다.\n");
	else {
		cur = head;
		printf("%d", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("->%d", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL) {
		printf("삭제할 데이터가 없습니다.\n");
		return 0;
	}
	else {
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%d을(를) 삭제합니다.\n", delNode->data);
		free(delNode);
		head = delNextNode;
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("%d을(를) 삭제합니다.\n", delNode->data);
			free(delNode);
			head = delNextNode;
		}
	}
	return 0;
}