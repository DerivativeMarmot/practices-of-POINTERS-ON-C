/*
Author: DerivativeMarmot
Version: 1.0.0
Date: 8/5/2021
Title: Check Format
*/
#include <stdio.h>
#include <string.h>

void written_amount(unsigned int amount, char *buffer);
int main(void)
{
    unsigned int amount = 27114514;
    char buffer[256] = {};
    written_amount(amount, buffer);
    return 0;
}

void written_amount(unsigned int amount, char *buffer)
{
    char const *ONE2NINE[] = {
        "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    char const *ELE2NINETN[] = {
        "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
    char const *TENS[] = {
        "TEN", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY", "HUNDRED"};
    char const *ZEROS[] = {
        "THOUASND", "MILLION", "BILLION"};
    /*************************************************************/
    int digit = 1;
    int base = 10;
    int SECTOR_DIGIT = 3;
    while (amount / base > 0)
    {
        base *= 10;
        digit++;
    }
    //printf("digit: %d\n", digit);
    int sector_amt = (digit % SECTOR_DIGIT == 0 ? digit / SECTOR_DIGIT : digit / SECTOR_DIGIT + 1);
    int sector[sector_amt];
    int tmp_amount = amount;
    for (int i = sector_amt - 1; i >= 0; i--)
    {
        sector[i] = tmp_amount % 1000;
        //printf("%d\n", sector[i]);
        tmp_amount /= 1000;
    }
    /*************************************************************/
    int ea_sec[] = {0, 0, 0};
    for (int i = 0; i < sector_amt; i++)
    {
        int cur_sec = sector[i];
        if (cur_sec >= 100)
            ea_sec[0] = cur_sec / 100;
        if (cur_sec >= 10)
            ea_sec[1] = cur_sec / 10 % 10;
        ea_sec[2] = cur_sec % 10;

        //hundreds place
        if (ea_sec[0])
        {
            strcat(buffer, ONE2NINE[ea_sec[0] - 1]);
            buffer[strlen(buffer)] = ' ';
            strcat(buffer, TENS[9]);
            buffer[strlen(buffer)] = ' ';
        }
        //tens place
        if (ea_sec[1])
        {
            if (ea_sec[1] == 1)
            {
                strcat(buffer, ELE2NINETN[ea_sec[2] - 1]);
                buffer[strlen(buffer)] = ' ';
            }
            else
            {
                strcat(buffer, TENS[ea_sec[1] - 1]);
                buffer[strlen(buffer)] = ' ';
                strcat(buffer, ONE2NINE[ea_sec[2] - 1]);
                buffer[strlen(buffer)] = ' ';
            }
        }
        //ones place
        else
        {
            strcat(buffer, ONE2NINE[ea_sec[2] - 1]);
            buffer[strlen(buffer)] = ' ';
        }
        //sector seprator
        if (sector_amt - i - 1)
        {
            strcat(buffer, ZEROS[sector_amt - i - 1 - 1]);
            buffer[strlen(buffer)] = ' ';
        }
    }
    puts(buffer);
}