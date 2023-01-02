#include "second.h"
#include "clock.h"
#include "utc.h"

RtkWristBandSysType_t RtkWristbandSys;

void set_wristband_clock(time_union_t time)

{

    uint32_t i = 0;

    uint32_t offset = 0;



    //day time

    offset += time.time.seconds;

    offset += time.time.minute * 60;

    offset += time.time.hours * 60 * 60;



    uint8_t leapYear = IsLeapYear(time.time.year + 2000);



    offset += DAY * (time.time.day - 1);



    for (i = 0; i < time.time.month - 1; ++i)

    {

        //month start from 1

        offset += month_length_calc(leapYear, i) * DAY;

    }



    for (i = 0; i < time.time.year ; ++i)

    {

        if (IsLeapYear(i + 2000))

        {

            offset += DAY * 366;

        }

        else

        {

            offset += DAY * 365;

        }

    }

    RtkWristbandSys.SecondCountRTC = offset;
    printf("convert second count rtc = %d\n", RtkWristbandSys.SecondCountRTC);

    convert_to_utc_time(RtkWristbandSys.SecondCountRTC);

}






