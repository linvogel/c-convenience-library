#include "sorting.h"

void lbubblesort(linked_list *list, int8_t cmp(void* a, void* b))
{
	uint32_t len = list->length;
	
	doubly_linked_node *base = list->first;
	int start = 0;
	while (base->next != NULL) {
		doubly_linked_node *a = base;
		int ai = start;
		do {
			int8_t diff = cmp(a->data, a->next->data);
			printf("comparing: %d with %d: ", ai, ai+1);
			if (diff < 0) {
				doubly_linked_node *b = a->next;
				a->prev->next = b;
				b->next->prev = a;
				a->next = b->next;
				b->prev = a->prev;
				b->next = a;
				a->prev = b;
				printf("SWAP\n");
			} else {
				printf("NSWP\n");
			}
			
			
			a = a->next;
			ai++;
		} while (a->next != NULL);
		base = base->next;
		start++;
	}
}