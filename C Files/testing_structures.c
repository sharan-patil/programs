#include <stdio.h>

typedef struct newName {
	int a;
	char c;
} newName;

typedef struct node {
	char a;
	struct node* next;
} node;

int	main(void)
{
	newName lmao;
	lmao.a = 1;
	lmao.c = 'a';
	printf("%d %c\n", lmao.a, lmao.c);
	node root;
	root = (node)malloc(sizeof(node));
	root.a = 'a';
	node first;
	root.next = &first;
	first.a = 'b';
	first.next = NULL;
	node temp = root;
	while(temp != NULL) {
		printf("%c\n", temp.a);
		node* tempo = temp.next;
		temp = *tempo;
	}
	return 0;
}