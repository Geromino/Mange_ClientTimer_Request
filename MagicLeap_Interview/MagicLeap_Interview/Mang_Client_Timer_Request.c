
#include "Mang_Client_Timer_Request.h"
#include "linkedlist_implement_stack.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief  indicate hw timer finish any client request  timer
 * @param  None
 * @retval 1 time value  which set hw timer finish counting ticks
 */
uint8_t local_callback(void)
{
    uint8_t callback_flag; // need  think if need to be global 

    callback_flag = INTERNAL_CALLBACK_DONE;
    return callback_flag;
}

/**
 * @brief  client recive timer service 
 * @param  load_timer_value which pass to set_time(...) 
 * @param  user_callback_func which will be excute by Mgmt_Algo or save in client_request_list datastructure 
           until Mgmt_Algo will determine excute it 
 * @retval None
 */
void user_set_timer(int load_timer_value, user_callback_func r_callback)
{
    int current_timer_load_value;
    element_request_client_timer current_client;
    //Manager client request slot_timer 
    //initialize client  request 
    current_client.time_value_request = load_timer_value;
    current_client.UserFunc = r_callback;

  
    // local callback function  which dedecate if services for single client done 
    local_callback_func function_pointer_local_callback = local_callback;


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
 * @brief  load value into hw timer
 * @Note   in embedded system  need  implemnt this function 
 * @param  load_timer_value hw timer load  value
 * @param  local_callback_func which update callback_flag 
 * @retval None
 */
void set_timer(int load_timer_value, local_callback_func l_callback)
{
    l_callback();
}
/**
 * @brief  get_timer value
 * @param  None
 * @retval Current time value in timer hw register in sec 
 */

int get_timer(void)
{
    return CURRENT_TIMER_VALUE;
}


   




