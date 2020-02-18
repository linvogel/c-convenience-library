#ifndef _DBLY_LINKED_LIST_H
#define _DBLY_LINKED_LIST_H

struct doubly_linked_node {
	struct doubly_linked_node *next;
	struct doubly_linked_node *prev;
	void *data;
};

typedef struct doubly_linked_node doubly_linked_node;


#endif