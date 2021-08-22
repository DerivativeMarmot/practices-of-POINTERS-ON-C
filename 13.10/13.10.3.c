#include <stdio.h>

void new(list, current, transaction);
void delete(list, current, transaction);
void forward(list, current, transaction);
void backward(list, current, transaction);
void search(list, current, transaction);
void edit(list, current, transaction);

void (*oper_func[])(list, current, transaction) = {
    new,
    delete,
    forward,
    backward,
    search,
    edit
};
