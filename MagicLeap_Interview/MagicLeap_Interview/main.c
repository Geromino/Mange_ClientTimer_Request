#include <stdio.h>
#include "Mang_Client_Timer_Request.h"
#include "linkedlist_implement_stack.h"
#include <windows.h>
void  client1_request1_callback(void);
void  client1_request2_callback(void);

 


int main(void)
{
	int cnt = 0;
	int load_value = 2,load_value1=5;

	user_set_timer(load_value, client1_request1_callback);
	user_set_timer(load_value1, client1_request1_callback);
	print_client_request_list(client_requests);
	//while (1)
	//{
	//	printf("MagicLeepInterview\r\n");
	//	Sleep(SYSTEM_TIME_INTERVAL);
	//	cnt++;
	//	if (cnt == 10)
	//		break;
	//}
	//printf("finish test\r\n");
	return 0;
}

void  client1_request1_callback(void)
{
	printf("Client Request excuted\r\n");
}

void  client1_request2_callback(void)
{
	printf("user request 2 well done timer finish\r\n");
}




