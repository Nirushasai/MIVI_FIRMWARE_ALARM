#include<stdio.h>
#include "clock.h"


 uint8_t month_length_calc(uint8_t lpyr, uint8_t mon)

{

    uint8_t days = 31;



    if (mon == 1)   // feb

    {

        days = (28 + lpyr);

    }

    else

    {

        if (mon > 6)   // aug-dec

        {

            mon--;

        }



        if (mon & 1)

        {

            days = 30;

        }

    }

    return (days);

}


