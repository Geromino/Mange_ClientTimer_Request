#include <stdio.h>
#include "Mang_Client_Timer_Request.h"
#include "linkedlist_implement_stack.h"
void  user_callback(void);
void  user_callback1(void);

int main(void)
{
	linkedlist_stack* client_requests = (linkedlist_stack*)malloc(sizeof(linkedlist_stack));
	
	int timer_load_value = 9, timer_load_value1 = 34;

	if (client_requests != NULL)
	{
		push(&client_requests, timer_load_value, &user_callback);
		push(&client_requests, timer_load_value1, &user_callback1);
		print_stack(client_requests);
	}
	else
	{
		printf("failed allocate memory for request client timer\r\n");
	}



	return 0;
}

void  user_callback(void)
{
	printf("user request 1 well done timer finish\r\n");
}

void  user_callback1(void)
{
	printf("user request 2 well done timer finish\r\n");
}