#include <stdio.h>
#include "cal.h"

int main(void)
{
    int p_a = 10;
    int p_b = 15;
    int p_num = 2;
    printf("totol price is %d", cal_sum(p_a, cal_mul(p_b, p_num)));
    return 0;
}
