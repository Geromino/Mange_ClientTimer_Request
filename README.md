Purpose : embedded system give only one hw timer as resource therfore need implement 
          services request for clients each client provide load value and callback function
HW API : void set_timer(int loadvalue,callbackfun localfunc)
         Int get_time(void)
Solution : linkedlist implement stack datastducture which save respectevly client request service timer list
           User_set_timer(int loadvalue,callback userfunc)
           the principle save the diffrence between actual left time in loaded timer and next request

Time Line Description
Request for services of timer 
Example :  time line. ......5,3,19,29,48,1......

![](\images\view_stack.PNG)

