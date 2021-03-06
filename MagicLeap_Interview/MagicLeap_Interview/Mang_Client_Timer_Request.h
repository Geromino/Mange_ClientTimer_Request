#ifndef MANG_CLIENT_TIMER_REQUEST_H_
#define MANG_CLIENT_TIMER_REQUEST_H_ 100

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

	/* Mange Client TimerRequest version check */
#if MANG_CLIENT_TIMER_REQUEST_H_ < 100
#error "Please update Mngm Client Request timer slot, minimum required version is 1.0.0. clone github repository"
#endif
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>


#define SYSTEM_TIME_INTERVAL  1000  // m sec =1 sec 
#define	INTERNAL_CALLBACK_DONE 1
#define CURRENT_TIMER_VALUE 56
#define CLIENT_REQUEST_IS_ACHIEVED 0

typedef void (*local_callback_func)(void);

typedef void (*user_callback_func)(void); // if need could be change  by  the user 
	
typedef struct _element_request_client_timer {
	int time_value_request;
	user_callback_func UserFunc;
}element_request_client_timer;


extern	int  get_timer(void);
	    void set_timer(unsigned int load_timer_value, local_callback_func callback);
extern	void user_set_timer(int load_timer_value, user_callback_func callback);
	

	/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /* MANG_CLIENT_TIMER_REQUEST_H_ */