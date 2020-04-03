
#include "Mang_Client_Timer_Request.h"
#include "linkedlist_implement_stack.h"
#include <stdlib.h>


/**
 * @brief  indicate finish client request timer
 * @param  None
 * @retval 1 time value  which set hw timer finish counting ticks
 */
uint8_t local_callback(void)
{
    //printf("Job Done\r\n");
    return INTERNAL_CALLBACK_DONE;
}

/**
 * @brief  Client Request timer value 
 * @param  load_timer_value
 * @param  r_callback
 * @retval None
 */
void user_set_timer(int load_timer_value, user_callback_timer r_callback)
{
    int current_timer_load_value;
    element_request_client_timer current_client;
    //Manager client request slot_timer 

    //initialize client  request 
    current_client.time_value_request = load_timer_value;
    current_client.UserFunc = r_callback;

    // local callback function  which dedecate if services for single client done 
    internal_callback_timer function_pointer_local_callback = local_callback;


    // inner callback finish current job 
    if (function_pointer_local_callback() == INTERNAL_CALLBACK_DONE)
    {
        printf("client get slot timer\r\n");
    }

    //Excute choosen request slot_timer 
    current_client.UserFunc();

    set_timer(load_timer_value, function_pointer_local_callback);
}

/**
 * @brief  set_timer in hw timer 
 * @Note   in embedded system  need  implemnt this function 
 * @param  load_timer_value
 * @param  l_callback
 * @retval None
 */
void set_timer(int load_timer_value, internal_callback_timer l_callback)
{
    l_callback();
}
/**
 * @brief  get_timer from hw 
 * @param  None
 * @retval Current time value in timer hw register in sec 
 */

int get_timer(void)
{
    return CURRENT_TIMER_VALUE;
}


   




