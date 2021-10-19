#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int	data;
	struct _node *next;
} Node;

int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newnode = NULL;
	int	readData;

	// 데이터를 입력받는 과정
	while(1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)
			break ;
		
		// 노드의 추가 과정
		newnode = (Node*)malloc(sizeof(Node));
		newnode->data = readData;
		newnode->next = NULL;

		if (head == NULL)
			head = newnode;
		else
			tail->next = newnode;
		
		tail = newnode;
	}
	printf("\n");

	// 입력받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체 출력 ! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;
		printf("%d ", cur->data);		// 첫번째 데이터 출력

		while(cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리의 해체 과정
	if (head == NULL)
	{
		return 0;			// 해체할 노드가 존재하지 않음
	}
	else
	{
		Node *delNode = head;
		Node *delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);		// 첫 번째 노드 삭제

		while (delNextNode != NULL)		// 두 번째 이후 노드 삭제
		{
			delNode = delNextNode;
			delNextNode = delNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	return (0);
}
