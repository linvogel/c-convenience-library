#include "linked_list.h"

#include <stdio.h>


uint32_t ladd(linked_list *list, void* data)
{
	// create a new instance of the doubly_linked_node and set its data
	doubly_linked_node *node = (doubly_linked_node*)malloc(sizeof(doubly_linked_node));
	node->data = data;
	node->next = NULL;
	
	// handle the case where the list is empty
	if (list->first == NULL) {
		node->prev = NULL;
		list->first = node;
		list->last = node;
		list->length = 1;
	} else {	// handle all other cases
		node->prev = list->last;
		list->last->next = node;
		list->last = node;
		list->length++;
	}
	
	return list->length;
}

uint32_t linsert(linked_list *list, void* data, uint32_t index)
{
	// create new instance of the doubly_linked_node and set its data
	doubly_linked_node *node = (doubly_linked_node*)malloc(sizeof(doubly_linked_node));
	node->data = data;
	
	// handle the case, where index is 0
	if (index == 0) {
		node->prev = NULL;
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
		return ++list->length;
	}
	
	//hanlde the case where index is list->length
	if (index == list->length) {
		node->next = NULL;
		node->prev = list->last;
		list->last->next = node;
		list->last = node;
		return ++list->length;
	}
	
	// handle all other cases
	doubly_linked_node *current = NULL;
	
	// if the index is smaller than half the length, begin at the beginning of the list, else begin at the end of the list
	if (index < list->length / 2) {
		current = list->first;
		while (current->next && index-- != 0)
			current = current->next;
	} else {
		current = list->last;
		while (index++ < list->length-1)
			current = current->prev;
	}
	
	doubly_linked_node *prev = current->prev;
	
	node->prev = prev;
	node->next = current;
	prev->next = node;
	current->prev = node;
	
	return ++list->length;
	
}

void* lget(linked_list *list, uint32_t index)
{
	// First, handle the case, where the specified index is outside the bounds of the specified list
	if (index >= list->length)
		return NULL;
	
	// Handle the case, when the index is 0
	if (index == 0)
		return list->first->data;
	
	// Handle the case, when the index is list->length - 1
	if (index == list->length - 1)
		return list->last->data;
	
	// Handle all other cases
	doubly_linked_node *current = NULL;
	
	// if the index is smaller than half the length, begin at the beginning of the list, else begin at the end of the list
	if (index < list->length / 2) {
		current = list->first;
		while (current->next && index-- != 0)
			current = current->next;
	} else {
		current = list->last;
		while (index++ < list->length-1)
			current = current->prev;
	}
	
	return current->data;
}

void* lremove(linked_list *list, uint32_t index)
{
	// First, handle the case, where the specified index is outside the bounds of the specified list
	if (index >= list->length)
		return NULL;
	
	
	// Handle the case, when the index is 0
	if (index == 0) {
		struct doubly_linked_node *node = list->first;
		void* out = list->first->data;
		list->first = list->first->next;
		free(node);
		list->length--;
		return out;
	}
	
	// Handle the case, when the index is list->length - 1
	if (index == list->length) {
		struct doubly_linked_node *node = list->last;
		void* out = list->last->data;
		list->last = list->last->prev;
		free(node);
		list->length--;
		return out;
	}
	
	// Handle all other cases
	doubly_linked_node *current = NULL;
	
	// if the index is smaller than half the length, begin at the beginning of the list, else begin at the end of the list
	if (index < list->length / 2) {
		current = list->first;
		while (current->next && index-- != 0)
			current = current->next;
	} else {
		current = list->last;
		while (index++ < list->length-1)
			current = current->prev;
	}
	
	void* out = current->data;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
	list->length--;
	return out;
}