#include "linkedlist_implement_stack.h"


linkedlist_stack* client_requests = NULL;
/**
 * @brief  push new item to the stack
 * @param  head of the stack
 * @param  data of new item
 * @retval None
 */
void push_to_begin_list(linkedlist_stack** head,int time_value, user_callback_func callback){

	// alloc memory for new item 
	linkedlist_stack* request_element =(linkedlist_stack*)malloc(sizeof(linkedlist_stack));

	//verfying alloc operation 
	if (request_element != NULL)
	{
		request_element->clientrequest = new_element(time_value, callback);
		request_element->next = NULL;
	}
	else
	{
		printf("alloc new request timer faild\r\n");
	}

	// if list is empty
	if (*head == NULL)
	{
		*head = request_element;
	}
	else
	{
		if (request_element != NULL)
		{
			request_element->next = (*head);
			*head = request_element;
		}

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


element_request_client_timer top(linkedlist_stack* head) // show only the time request in order calculate the diffrence 
{
	element_request_client_timer element_request;

	if (head != NULL)
	{
		element_request.time_value_request = head->clientrequest->time_value_request;
	}
	else
	{
		element_request.time_value_request = STACK_IS_EMPTY;
		element_request.UserFunc = NULL;
	}
	return element_request;
}


/**
 * @brief  print element stack values
 * @param  head of the stack
 * @retval None
 */

int print_client_request_list(linkedlist_stack* head)
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

/**
 * @brief  alloc new memory for new client request for timer
 * @param  time_value want value to load timer
 * @param  user_callback_func function which user want to preform in the enf of the timer
 * @retval pointer to new element 
 */
element_request_client_timer* new_element(int time_value, user_callback_func UFunc)
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

void update_top(linkedlist_stack* head, int time_load_value)
{

}

bool  is_list_empty(linkedlist_stack* head)
{
	if (head == NULL)
		return true;
	else
		return false;
}

