# Magic Client Request HW Timer Services 

	embedded system give only one hw timer as resource therfore need implement 
	services request for clients each client provide load value and callback function
## IDE 
     IDE-visual studio 2019  TBD : create Mgmt_Client_Request dll
	 IDE-TrueStudio ARM STM32F4Discovery  Mgmt_Client_Request.a (lib)
	 
	
		
### Proposole solution
	    linkedlist implement stack datastducture which save respectevly client request service timer list
           User_set_timer(int loadvalue,callback userfunc)
           the principle save the diffrence between actual left time in loaded timer and next request

## Getting Started

HW API : 
		 set_timer(unsigned int load_timer_value, local_callback_func l_callback)
         int get_time(void)
### Prerequisites

define usercallback function and load time value for load hw timer

```
	int load_value = 2,load_value1=5;

	user_set_timer(load_value, client1_request1_callback);
	
	void  client1_request1_callback(void)
	{
		printf("Client Request excuted\r\n");
	}
```


## Running the tests

TBD

### Break down into end to end tests

TBD

```
Give an example
```

## Description  view stack on time line 

Clients Requests for services of timer 
Example :  time line. ......5,3,19,29,48,1......

![](/images/view_stack.PNG)

## Notes

### (*) <T> defualt  time is Zero needed to change  when run on embeeded system or system which require more accurecy 
### (**) System tim betweeen request defualt is : 1 sec 
### (***)f1.....fn: callback which user client provide
### (****)v1.....vn loadvalue which user client provide
### (*****) c1(v1,f1).......cn(vn,fn)  element which represent  user client request

