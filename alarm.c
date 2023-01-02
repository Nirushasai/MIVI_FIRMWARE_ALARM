#include<stdio.h>
#include "alarm.h"
#include "rtc.h"
#include "week.h"
#include<stdbool.h>



void check_alarm(void)

{

    uint8_t index;

    DAY_OF_WEEK day_of_week;

    bool alarmchanged = false;

RtkWristbandSys.alarm_num = 3;

    for (index = 0; index < RtkWristbandSys.alarm_num; index ++)

    {
  printf("global time hour = %d\n",RtkWristbandSys.Global_Time.hour);
  printf("global time minutes = %d\n",RtkWristbandSys.Global_Time.minutes);

printf("global time hour in alarm = %d\n",RtkWristbandSys.alarms[index].alarm.hour);
  printf("global time minute in alarm = %d\n",RtkWristbandSys.alarms[index].alarm.minute);


        if (RtkWristbandSys.Global_Time.hour == RtkWristbandSys.alarms[index].alarm.hour &&

            RtkWristbandSys.Global_Time.minutes == RtkWristbandSys.alarms[index].alarm.minute) // time

        {

            day_of_week = get_day_of_week(RtkWristbandSys.SecondCountRTC); // day of week

printf("day of week = %d\n",day_of_week);

printf("alarm index repeat flag = %d\n ",RtkWristbandSys.alarms[index].alarm.day_repeat_flag);


            if (RtkWristbandSys.alarms[index].alarm.day_repeat_flag == 0)

            {
            printf (" global time day = %d\n",RtkWristbandSys.Global_Time.day);
            printf (" global time month = %d\n",RtkWristbandSys.Global_Time.month);
            printf (" global time year = %d\n",RtkWristbandSys.Global_Time.year);
            
           printf (" global time day in alarm = %d\n",RtkWristbandSys.alarms[index].alarm.day);
            printf (" global time month in alarm = %d\n",RtkWristbandSys.alarms[index].alarm.month);
            printf (" global time year in alarm = %d\n",RtkWristbandSys.alarms[index].alarm.year);
            

                if ((RtkWristbandSys.Global_Time.day == RtkWristbandSys.alarms[index].alarm.day &&

                     RtkWristbandSys.Global_Time.month == RtkWristbandSys.alarms[index].alarm.month &&

                     RtkWristbandSys.Global_Time.year == RtkWristbandSys.alarms[index].alarm.year ))

                {

                    printf("HIT ALARM OF ONE TIME");

                    do_rtc_alarm();

                    //use reserved bit to mark alarm has been alarmed

                    RtkWristbandSys.alarms[index].alarm.reserved = 0x0;

                    alarmchanged = true;

                }

            }

            else

            {
                printf("alarm day repeat flag = %d\n",(1 << (day_of_week)));
                if (RtkWristbandSys.alarms[index].alarm.day_repeat_flag & (1 << (day_of_week)))

                {

                    printf("HIT ALARM DAY OF WEEK");

                    do_rtc_alarm();

                }

            }

        }

    }

    if (alarmchanged)

    {

 //       ftl_save((void *)RtkWristbandSys.alarms, ALARM_OFFSET, ALARM_SIZE);

    }



}
