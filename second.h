#include<stdio.h>

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

typedef struct
{
    uint32_t seconds    :   6 ;
    uint32_t minute     :   6 ;
    uint32_t hours      :   5 ;
    uint32_t day        :   5 ;
    uint32_t month      :   4 ;
    uint32_t year       :   6 ;
}
time_bit_field_type_t;



typedef union
{
    uint32_t data;
    time_bit_field_type_t time;
} time_union_t;

time_union_t timer;

#define BEGYEAR                     2000     // UTC started at 00:00:00 January 1, 2000
#define DAY                         86400UL  // 24 hours * 60 minutes * 60 seconds
#define SYSTEM_ORIGIN_DAY_OF_WEEK   (Sat)  //2000-01-01 is sat
#define LENGTH_OF_WEEK              (7)
#define RTC_CNT_MAX_VALUE           (1024*1024*16UL -1)         //RTC->CNT: [23:0]
#define RTC_PRESCALER_VALUE         0


#define IsLeapYear(yr) (!((yr) % 400) || (((yr) % 100) && !((yr) % 4)))



#define YearLength(yr) (IsLeapYear(yr) ? 366 : 365)



void set_wristband_clock(time_union_t);

uint32_t convert_time_to_second(time_union_t);
