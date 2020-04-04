#ifndef LINKEDLIST_IMPLEMENT_STACK_H_
#define LINKEDLIST_IMPLEMENT_STACK_H_ 205

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

#include "Mang_Client_Timer_Request.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Mange Client TimerRequest version check */
#if LINKEDLIST_IMPLEMENT_STACK_H_ < 100
#error "Please update LinkedListStack, minimum required version is 2.0.5. clone github repository"
#endif

#define STACK_IS_EMPTY  0

typedef struct _linkedlist_stack {
	element_request_client_timer *clientrequest;
	struct _linkedlist_stack* next;
}linkedlist_stack;

linkedlist_stack* client_requests;

element_request_client_timer* new_element(int time_value, user_callback_func UFunc);

void push_to_begin_list(linkedlist_stack** head,int time_value, user_callback_func callback);

int print_client_request_list(linkedlist_stack* head);

void pop(linkedlist_stack** head);

element_request_client_timer top(linkedlist_stack* head);

void update_top(linkedlist_stack* head, int time_load_value);

bool  is_list_empty(linkedlist_stack* head);



		/* C++ detection */
#ifdef __cplusplus
}
#endif
#endif /* LINKEDLIST_IMPLEMENT_STACK_H_ */
