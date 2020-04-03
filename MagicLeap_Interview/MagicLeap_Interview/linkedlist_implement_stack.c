#include "linkedlist_implement_stack.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief  push new item to the stack
 * @param  head of the stack
 * @param  data of new item
 * @retval None
 */
void push(linkedlist_stack** head, int time_value, user_callback_timer *callback){
	// alloc memory for new item 
	linkedlist_stack* client_request ;
	client_request = (linkedlist_stack*)malloc(sizeof(linkedlist_stack));
	//connect new item to begging of the list
	if (client_request!=NULL)
	{
		client_request->clientrequest = client_element_request(time_value, callback);
		client_request->next = *head;
		client_request->next->next = NULL;
		//  the head update
		(*head) = client_request;
	}
	else
	{
		printf("failed allocte memory for new client item\r\n");
	}

}
/**
 * @brief  pop item from stack
 * @param  head of the stack , update item to manage the requests from clients
 * @retval None
 */
void pop(linkedlist_stack**head){

	linkedlist_stack* remove_item_head = *head;

	if (*head != NULL)
	{
		//moving forword the pointer
		*head = (*head)->next;
		//update client request

		free(remove_item_head);

	}
	else
	{
		printf("stack is empty\r\n");
	}

}


int top(linkedlist_stack* head) // show only the time request in order calculate the diffrence 
{
	int time_load_value=0;
	if (head != NULL)
	{
		time_load_value = head->clientrequest->time_value_request;

	}
	else
	{
		time_load_value = STACK_IS_EMPTY;
	}

	return time_load_value;
}


/**
 * @brief  print element stack values
 * @param  head of the stack
 * @retval None
 */

int print_stack(linkedlist_stack* head)
{
	int cnt = 0;
	// save original pointer of the stack
	linkedlist_stack* temp = head;
	while (temp!= NULL)
	{
		printf("element value %d \r\n", temp->clientrequest->time_value_request);
		temp->clientrequest->UserFunc();
		cnt++;
		temp = temp->next;
	}
	return cnt;
	
}

element_request_client_timer* client_element_request(int time_value, user_callback_timer *UFunc)
{
	element_request_client_timer* client_element = (element_request_client_timer*)malloc(sizeof(element_request_client_timer));
	if (client_element != NULL)
	{
		client_element->time_value_request = time_value;
		client_element->UserFunc = UFunc;
	}
	else
	{
		printf("failed allocate memory");
	}

	return client_element;
}

