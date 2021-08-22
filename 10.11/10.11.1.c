#include <stdio.h>

typedef struct{
    char areacode[10];
    char exchange[10];
    char station[10];
}PhoneNumber;

typedef struct
{
    int year;
    int month;
    int day;
} date;

typedef struct
{
    date dat;
    float time_s;
    PhoneNumber from;
    PhoneNumber to;
    PhoneNumber pay;
} Call;