#include "linked_list.h"
#include "sorting.h"
#include <stdio.h>
#include <string.h>

int8_t str_compare(void* av, void* bv) {
	char* a = (char*)av;
	char* b = (char*)bv;
	int diff = strlen(b) - strlen(a);
	if (diff < 0) return -1;
	if (diff > 0) return 1;
	return 0;
}

int main(void)
{
	linked_list *list = (linked_list*)calloc(1, sizeof(linked_list));
	
	char *c1 = "0: This is a string";
	char *c2 = "1: This is another string";
	char *c3 = "2: This will be on a different line";
	char *c4 = "3: Just another string of characters";
	char *c5 = "4: Yet another string";
	char *c6 = "5: This is getting old";
	char *c7 = "6: Still not an integer";
	char *c8 = "7: A float maybe? No, still string";
	
	ladd(list, c1);
	ladd(list, c2);
	ladd(list, c3);
	ladd(list, c4);
	ladd(list, c5);
	ladd(list, c6);
	ladd(list, c7);
	ladd(list, c8);
	
	printf("Structure of list:\n");
	doubly_linked_node *c = list->first;
	while (c != NULL) {
		printf("Node [ next: %llx prev: %llx, data: %llx ]\n", c->next, c->prev, c->data);
		c = c->next;
	}
	
	printf("\n\nContents of list:\n");
	for (int i = 0; i < list->length; i++)
		printf("%d of %d: %s\n", i, list->length-1, (char*)lget(list, i));
	
	printf("\n\nRemoving indices 2, 3 and 6\n");
	lremove(list, 6);
	lremove(list, 3);
	lremove(list, 2);
	
	printf("\nContents of list:\n");
	for (int i = 0; i < list->length; i++)
		printf("%d of %d: %s\n", i, list->length-1, (char*)lget(list, i));
	
	linsert(list, c3, 2);
	linsert(list, c4, 3);
	linsert(list, c7, 6);
	
	printf("\n\nContents of list:\n");
	for (int i = 0; i < list->length; i++)
		printf("%d of %d: %s\n", i, list->length-1, (char*)lget(list, i));
	
	
	printf("\n\nSorting list using bubblesort\n");
	lbubblesort(list, str_compare);
	
	printf("\nContents of list:\n");
	for (int i = 0; i < list->length; i++)
		printf("%d of %d: %s\n", i, list->length-1, (char*)lget(list, i));
}