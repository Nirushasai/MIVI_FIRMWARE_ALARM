#include<stdio.h>
#define MAX_ALARM_NUM 3

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

typedef struct

{

uint64_t day_repeat_flag: 7;

uint64_t reserved: 4;

uint64_t id: 3;

uint64_t minute : 6;

uint64_t hour : 5;

uint64_t day : 5;

uint64_t month : 4;

uint64_t year : 6;

}

alarm_clock_bit_field_type_t;

typedef union

{

uint64_t data __attribute__((packed));

alarm_clock_bit_field_type_t alarm __attribute__((packed));

} T_ALARM;

T_ALARM alarm;

typedef struct

{

volatile uint16_t year;// 2000+

volatile uint8_t month;// 0-11

volatile uint8_t day;// 0-30

volatile uint8_t seconds;// 0-59

volatile uint8_t minutes;// 0-59

volatile uint8_t hour;// 0-23

} T_UTC_TIME;

typedef struct

{

volatile uint8_t alarm_num;

volatile uint32_t SecondCountRTC;

volatile uint32_t pre_rtc_tick_count;

volatile T_ALARM alarms[MAX_ALARM_NUM];

volatile T_UTC_TIME Global_Time;

} RtkWristBandSysType_t;
RtkWristBandSysType_t RtkWristbandSys;

void convert_to_utc_time(uint32_t);




