/*
Author: DerivativeMarmot
Version: 1.0.0
Date: 8/8/2021
Title: Encrypt
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int preapre_key(char *key);
void encrypt(char *data, char const *key);
void decrypt(char *data, char *key);
char *gen_key(char *key);
char *strToUpper(char *string);

int main(int argc, char **argv)
{
    if (argc >= 3)
    {
        if (strcmp(argv[1], "-e") == 0)
        {
            if (argc != 3)
            {
                puts("Incorrect number of arguments");
                return 0;
            }
            char key[27] = {};
            gen_key(key);
            preapre_key(key);
            printf("%-12s %s\n", "Source:", argv[2]);
            printf("%-12s %s\n", "Key:", key);
            encrypt(argv[2], key);
            printf("%-12s %s\n", "Ciphertext:", argv[2]);
        }
        else if (strcmp(argv[1], "-d") == 0)
        {
            if (argc != 4)
            {
                puts("Incorrect number of arguments");
                return 0;
            }
            printf("%-12s %s\n", "Source:", argv[2]);
            printf("%-12s %s\n", "Key:", argv[3]);
            decrypt(argv[2], argv[3]);
            printf("%-12s %s\n", "Plaintext:", argv[2]);
        }
        else
            puts("Invalid option");
    }
    else
        puts("Missing arguments");
    return 0;
}

void test()
{
    char key[27] = "IAMDOWNBUTSTILLALIVE";
    char data[] = "NIER AUTOMATA";
    printf("%-12s %s\n", "Source:", data);
    preapre_key(key);
    printf("%-12s %s\n", "Key:", key);
    encrypt(data, key);
    printf("%-12s %s\n", "Ciphertext:", data);
    decrypt(data, key);
    printf("%-12s %s\n", "Plaintext:", data);
}

char *gen_key(char *key)
{
    srand((unsigned)time(NULL));
    int amt = rand() % 6 + 15; // 15 ~ 20
    for (int i = 0; i < amt; i++)
    {
        key[i] = rand() % 26 + 65;
    }
    puts(key);
}

void decrypt(char *data, char *key)
{
    while (*data != '\0')
    {
        if (*data != ' ')
        {
            char *cur_key = key;
            while (*cur_key != '\0')
            {
                if (*data == *cur_key)
                {
                    *data = cur_key - key + 65;
                    break;
                }
                cur_key++;
            }
        }
        data++;
    }
}

void encrypt(char *data, char const *key)
{
    while (*data != '\0')
    {
        if (*data != ' ')
            *data = *(key + *data - 65);
        data++;
    }
}

int preapre_key(char key[])
{
    char *temp = key;
    if (*key == '\0')
        return 0;
    while (*temp != '\0')
    {
        if (*temp < 65 || *temp > 90)
            return 0;
        temp++;
    }

    // merge reapted letters
    char *start = &key[0];
    char *cur = start + 1;
    while (*start != '\0')
    {
        while (*cur != '\0')
        {
            if (*start == *cur)
            {
                char *temp = cur;
                while (*temp != '\0')
                {
                    *temp = *(temp + 1);
                    temp++;
                }
                // IAMDOWNBUTSLLLVE
                if (*start == *cur)
                    continue;
            }
            cur++;
        }
        cur = ++start + 1;
    }

    // fill out the table of letters
    start = &key[0];
    char *end = key + strlen(key);
    cur = end;
    for (int i = 65; i < 91; i++)
    {
        bool flag = false;
        while (start != end)
        {
            if (*start == i)
            {
                flag = true;
                break;
            }
            start++;
        }
        start = &key[0];
        if (!flag)
        {
            *cur = i;
            cur++;
        }
    }
    return 1;
}