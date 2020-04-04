
#include "Mang_Client_Timer_Request.h"
#include "linkedlist_implement_stack.h"


volatile uint8_t callback_flag;

/**
 * @brief  indicate hw timer finish any client request  timer
 * @param  None
 * @retval 1 time value  which set hw timer finish counting ticks
 */
void local_callback(void)
{
    callback_flag = INTERNAL_CALLBACK_DONE;  
}

/**
 * @brief  client recive timer service 
 * @param  load_timer_value which pass to set_time(...) 
 * @param  user_callback_func which will be excute by Mgmt_Algo or save in client_request_list datastructure 
           until Mgmt_Algo will determine excute it 
 * @retval None
 */
void user_set_timer(int load_timer_value, user_callback_func user_callback)
{
    int current_hw_load_timer_value;
    local_callback_func check_hw_timer = &local_callback;
    int diff;
    callback_flag = 0;

    //verfying if list is empty meaning  this is the first request by any client
    if (is_list_empty(client_requests))
    {
        
        push_to_begin_list(&client_requests, load_timer_value, user_callback);
        set_timer(load_timer_value, check_hw_timer);
    }
    else // request starts coming from clients
    {
       
        if (callback_flag) //hw timer stop get request 
        {
            push_to_begin_list(&client_requests, load_timer_value, user_callback);
            set_timer(load_timer_value, check_hw_timer);
        }
        else
        {
            current_hw_load_timer_value = get_timer();

            if (top(client_requests).time_value_request > load_timer_value)
            {
                //update privious item in order save relative vaule when request shuold excute
                diff = top(client_requests).time_value_request - load_timer_value;
                update_top(client_requests, diff);
                //push new request
                push_to_begin_list(&client_requests, load_timer_value,user_callback);
                
                //check if previous client request timer is finish 
                if (current_hw_load_timer_value - diff == CLIENT_REQUEST_IS_ACHIEVED)
                {
                    //excute user function becuse tick of the timer was equal to request
                    top(client_requests).UserFunc();
                    //delete client request 
                    pop(&client_requests);
                }

            }
            /* 
            the value from current  is higher therefore no switch between request
            only update the load value before push to the list
            */
            else
            {

            }
           

        }

    }

}

/**
 * @brief  load value into hw timer
 * @Note   in embedded system  need  implemnt this function 
 * @param  load_timer_value hw timer load  value
 * @param  local_callback_func which update callback_flag 
 * @retval None
 */
void set_timer(unsigned int load_timer_value, local_callback_func l_callback)
{
#ifdef WIN_APPLICATION
    MSG msg;
    int id_timer;
    id_timer = SetTimer(NULL, 0, SYSTEM_TIME_INTERVAL*load_timer_value, (TIMERPROC)l_callback);
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        KillTimer(NULL, id_timer);
        break;
    }
#elif STM32F07DISCOVERY

#endif
}
/**
 * @brief  get_timer value
 * @param  None
 * @retval Current time value in timer hw register in sec 
 */

int get_timer(void)
{
#ifdef WIN_APPLICATION

    return CURRENT_TIMER_VALUE;

#elif STM32F07DISCOVERY

#endif
    
}


   




