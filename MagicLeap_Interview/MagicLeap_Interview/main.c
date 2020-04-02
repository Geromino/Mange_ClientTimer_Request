#include <stdio.h>
#include "Mang_Client_Timer_Request.h"

void  user_callback(void);


int main(void)
{
	printf("Welcome MagicLeap\r\n");

	int timer_load_value = 9;
	user_set_timer(timer_load_value, user_callback);


	return 0;
}

void  user_callback(void)
{
	printf("well done timer finish\r\n");
}