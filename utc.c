#include <stdio.h>
#include "clock.h"
#include "utc.h"
#include "second.h"

RtkWristBandSysType_t RtkWristbandSys;


void convert_to_utc_time(uint32_t sec_time)

{

    /* calculate the time less than a day - hours, minutes, seconds */

    {

        uint32_t day = sec_time % DAY;

        RtkWristbandSys.Global_Time.seconds = day % 60UL;
	printf("global time seconds = %d\n",RtkWristbandSys.Global_Time.seconds);

        RtkWristbandSys.Global_Time.minutes = (day % 3600UL) / 60UL;
	printf("global time minutes = %d\n", RtkWristbandSys.Global_Time.minutes);

        RtkWristbandSys.Global_Time.hour = day / 3600UL;
	printf("global time hour = %d\n", RtkWristbandSys.Global_Time.hour);

    }



    /* Fill in the calendar - day, month, year */

    {

        uint16_t numDays = sec_time / DAY;

        RtkWristbandSys.Global_Time.year = BEGYEAR;

        while (numDays >= YearLength(RtkWristbandSys.Global_Time.year))

        {

            numDays -= YearLength(RtkWristbandSys.Global_Time.year);

            RtkWristbandSys.Global_Time.year++;

        }



        RtkWristbandSys.Global_Time.month = 0;

        while (numDays >= month_length_calc(IsLeapYear(RtkWristbandSys.Global_Time.year),

                                            RtkWristbandSys.Global_Time.month))

        {

            numDays -= month_length_calc(IsLeapYear(RtkWristbandSys.Global_Time.year),

                                         RtkWristbandSys.Global_Time.month);

            RtkWristbandSys.Global_Time.month++;

        }



        RtkWristbandSys.Global_Time.day = numDays;
	

        RtkWristbandSys.Global_Time.month = RtkWristbandSys.Global_Time.month + 1;

	printf("global month = %d\n",RtkWristbandSys.Global_Time.month);

        RtkWristbandSys.Global_Time.day = RtkWristbandSys.Global_Time.day + 1;

printf("global day = %d\n",RtkWristbandSys.Global_Time.day);
    }

}


