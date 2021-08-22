#include <stdio.h>
#include <stdlib.h>

int *int_string();
int main(void){
    int *isp;
    isp = int_string();
    printf("%d", *(isp+2));
    //while (isp != NULL)
    free(isp);
    return 0;
}

int *int_string(){
    int amt = 0;
    int cur_val = 0;
    int *vp, *vsp;
    scanf("%d", &amt);
    vp = malloc(amt * sizeof(int));
    vsp = vp;
    while (scanf("%d", &cur_val) != EOF){
        *vp = cur_val;
        vp++;
    }
    return vsp;
}