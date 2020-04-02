
#include "Mang_Client_Timer_Request.h"

//private function  to be considur implemnt  in oop ( c++) 
uint8_t local_callback(void)
{
    //printf("Job Done\r\n");
    return INTERNAL_CALLBACK_DONE;
}

void user_set_timer(int load_timer_value, user_callback_timer r_callback)
{
    int current_timer_load_value;

    // local callback function  which dedecate if services for single client done 
    internal_callback_timer function_pointer_local_callback = local_callback;

    //Manager client request slot_timer 

    // inner callback finish current job 
    if (function_pointer_local_callback() == 1)
    {
        printf("client get slot timer\r\n");
    }

    //Excute choosen request slot_timer 
    r_callback();

    set_timer(load_timer_value, function_pointer_local_callback);
}

void set_timer(int load_timer_value, internal_callback_timer l_callback)
{
    l_callback();
}

int get_timer(void)
{
    return CURRENT_TIMER_VALUE;
}