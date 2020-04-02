
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
    internal_callback_timer p = local_callback;

    //Manager client request slot_timer 

    // inner callback finish current job 
    if (p() == 1)
    {
        printf("client get slot timer\r\n");
    }

    //Excute choosen request slot_timer 
    r_callback();

    set_timer(load_timer_value, p);
}

void set_timer(int load_timer_value, internal_callback_timer l_callback)
{
    l_callback();
}

int get_timer(void)
{
    return CURRENT_TIMER_VALUE;
}