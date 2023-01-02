#include <stdio.h>
#include "clock.h"
#include "second.h"
#include "utc.h"
#include "alarm.h"
#include "rtc.h"

int main(void)
{
    uint8_t lpyr = 1;
    uint8_t mon = 1;

        timer.time.seconds = 20;
timer.time.minute = 40;
timer.time.hours = 1;
timer.time.day = 1;
timer.time.month = 1;
timer.time.year = 22;

RtkWristbandSys.Global_Time.seconds = 40;
RtkWristbandSys.Global_Time.minutes = 50;
RtkWristbandSys.Global_Time.hour=2;
RtkWristbandSys.Global_Time.day = 2;
RtkWristbandSys.Global_Time.month = 2;
RtkWristbandSys.Global_Time.year = 24;

RtkWristbandSys.alarms[0].alarm.day_repeat_flag = 0 ;
RtkWristbandSys.alarms[0].alarm.reserved = 0;
RtkWristbandSys.alarms[0].alarm.id = 3;
RtkWristbandSys.alarms[0].alarm.minute = 50;
RtkWristbandSys.alarms[0].alarm.hour = 2;
RtkWristbandSys.alarms[0].alarm.day = 2 ;
RtkWristbandSys.alarms[0].alarm.month = 2;
RtkWristbandSys.alarms[0].alarm.year = 24;

uint32_t time_stamp = convert_time_to_second(timer);

    uint8_t days = month_length_calc(lpyr,  mon);
   
    set_wristband_clock(timer);

    check_alarm();

    printf("The no.of days in a february month is = %d  ", days);

    return 0;
}
