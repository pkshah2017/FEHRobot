#include "Task.h"
#include "Constants.h"

Task::Task()
{
}

StatusCode Task::checkStatus(StatusCode status){
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine((errordesc[(int)errorCode]));
    }
    return status;
}
