#include <stdio.h>
#include "Mang_Client_Timer_Request.h"
#include "linkedlist_implement_stack.h"

void  user_callback(void);
void  user_callback1(void);


int main(void)
{
	int load_value = 8,load_value1=98;
	push_to_begin_list(&client_requests, load_value, &user_callback);
	push_to_begin_list(&client_requests, load_value1, &user_callback1);
	print_client_request_list(client_requests);
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

