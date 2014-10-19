//
//  main.c
//  HeatIndexCalculation
//
//  Created by User Dev on 10/19/14.
//  Copyright (c) 2014 User Dev. All rights reserved.
//

#include <stdio.h>

float HI_Calculation (float T, float RH);

int main() {
    

    printf ("\nHeat Index при температуре: %d\t и влажности: %d равен\t %f\n", 100, 10, HI_Calculation(100, 10));
    printf ("\nHeat Index при температуре: %d\t и влажности: %d равен\t %f\n", 85, 89, HI_Calculation(85, 89));
    printf ("\nHeat Index при температуре: %d\t и влажности: %d равен\t %f\n", 60, 50, HI_Calculation(60, 50));
    printf ("\nHeat Index при температуре: %d\t и влажности: %d равен\t %f\n", 90, 35, HI_Calculation(90, 35));

    return 0;
}


float HI_Calculation (float T, float RH) {
    float HI = 0;
    float ADJ = 0;
    HI = -42.379 + 2.04901523*T + 10.14333127*RH - 0.22475541*T*RH - 0.00683783*T*T - 0.05481717*RH*RH + 0.00122874*T*T*RH + 0.00085282*T*RH*RH - 0.00000199*T*T*RH*RH;

    if ((RH<13)&&((T>=80)&&(T<=112)))
    {
        ADJ = ((13-RH)/4)*sqrt((17-abs(T-95))/17);
        return HI-ADJ;
    }
    else if ((RH>85)&&((T>=80)&&(T<=87)))
    {
        ADJ = ((RH-85)/10) * ((87-T)/5);
        return HI+ADJ;
    }
    else if (RH<80)
    {
        HI = 0.5 * (T + 61.0 + ((T-68.0)*1.2) + (RH*0.094));
        return HI;

    }
       return HI;
}


