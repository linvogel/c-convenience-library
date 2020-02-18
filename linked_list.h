#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdint.h>
#include <stdlib.h>

#include "doubly_linked_node.h"

struct linked_list {
	struct doubly_linked_node *first;
	struct doubly_linked_node *last;
	uint32_t length;
};

typedef struct linked_list linked_list;

uint32_t ladd(linked_list *list, void* data);
uint32_t linsert(linked_list *list, void* data, uint32_t index);
void* lget(linked_list *list, uint32_t index);
void* lremove(linked_list *list, uint32_t index);


#endif