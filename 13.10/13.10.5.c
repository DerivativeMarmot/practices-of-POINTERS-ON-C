#include <stdio.h>
#include <stdbool.h>

/****************Declaration***********************/
void do_arg(int ch, char *value);
void illegal_arg(int ch);
char **
do_args(int argc, char **argv, char *control,
        void (*do_arg)(int ch, char *value),
        void (*illegal_arg)(int ch));

/**********************************************/
int main(int argc, char **argv)
{
    do_args(argc, argv, "abcdef", do_arg, illegal_arg);
    return 0;
}

void do_arg(int ch, char *value)
{
    printf("do_arg: %c, %s\n", ch, value);
}
void illegal_arg(int ch)
{
    printf("illegal: %c\n", ch);
}

char **
do_args(int argc, char **argv, char *control,
        void (*do_arg)(int ch, char *value),
        void (*illegal_arg)(int ch))
{
    //check each argument
    while (*++argv != NULL)
    {
        // when the first char of the argument is '-'
        if (*(*argv)++ == '-')
        {
            bool ctn_input = true; // if the program still need to read the rest of the chars of the argument
            // read the argu char by char until '\0'
            while (**argv != '\0' && ctn_input)
            {
                char *cp = control;
                char ctl = **argv;
                bool ctl_exist = false;
                // compare the current command with each char of control
                while (*cp != '\0')
                {
                    // when the current command is presenting in the control
                    if (ctl == *cp)
                    {
                        ctl_exist = true;
                        // when the command need a argument
                        if (*(cp + 1) == '+')
                        {
                            // the string containing the rest chars of current string is the argument
                            if (*(*argv + 1) != '\0')
                            {
                                do_arg(ctl, ++*argv);
                            }
                            // the next program's argument is the command's argument
                            else
                            {
                                if (*(argv + 1) == NULL)
                                {
                                    illegal_arg(ctl);
                                }
                                else
                                {
                                    do_arg(ctl, *++argv);
                                }
                            }
                            // all the chars of current string have been used, and the input should be stopped for current string
                            // the program should start from a new program's argument
                            ctn_input = false;
                            break;
                        }
                        do_arg(ctl, "0");
                        break;
                    }
                    cp++;
                }
                // when the given command is not presenting in the control.
                if (!ctl_exist)
                {
                    illegal_arg(ctl);
                }
                if (ctn_input)
                {
                    (*argv)++;
                }
            }
        }
        else
        {
            break;
        }
    }
    return argv;
}
