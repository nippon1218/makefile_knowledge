#include <stdio.h>
#include "cal.h"
#include "single/single.h"

int main(void)
{
    int p_a = 10;
    int p_b = 15;
    int p_num = 2;
    int total_price = cal_sum(p_a, cal_mul(p_b, p_num));
    printf("totol price is %d\n", total_price);
    if(is_single(total_price))
        printf("price is single");
    else
        printf("price is not not single");
        
    return 0;
}
