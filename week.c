#include<stdio.h>
#include "alarm.h"
#include "week.h"

DAY_OF_WEEK get_day_of_week(uint32_t secTime)
{
    uint32_t day = secTime / DAY;

 

    DAY_OF_WEEK today = (DAY_OF_WEEK)(((day % LENGTH_OF_WEEK) + SYSTEM_ORIGIN_DAY_OF_WEEK) %
                                      LENGTH_OF_WEEK);

 

    return today;
}
