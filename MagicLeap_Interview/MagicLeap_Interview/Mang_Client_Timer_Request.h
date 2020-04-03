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

#include <stdint.h>

#define INTERNAL_CALLBACK_DONE 1
#define CURRENT_TIMER_VALUE 4 // TBD  get from hw 

	

	typedef uint8_t(*internal_callback_timer)(void);
	typedef void    (*user_callback_timer)(void); // if need could be change  by  the user 
	
	typedef struct _element_request_client_timer {

		int time_value_request;
		user_callback_timer UserFunc;

	}element_request_client_timer;

	int  get_timer(void);
	void set_timer(int load_timer_value, internal_callback_timer callback);
	void user_set_timer(int load_timer_value, user_callback_timer callback);
	

	/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /* MANG_CLIENT_TIMER_REQUEST_H_ */