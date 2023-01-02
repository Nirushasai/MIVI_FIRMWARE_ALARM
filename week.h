#include<stdio.h>
#include "second.h"
#include "utc.h"

typedef enum
{
MOn = 0,
Tues = 1,
Wed = 2,
Thur = 3,
Fri =4,
Sat =5,
Sun =6,
}DAY_OF_WEEK;

DAY_OF_WEEK get_day_of_week(uint32_t); 
