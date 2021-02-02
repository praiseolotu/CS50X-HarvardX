#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_num(void);

float get_positive_num(void)
{
    float num;
    do
    {
        num = get_float("Change Owned\n");

    }
    while (num < 0.00);
    return num;
}

int main()
{
    float change = get_positive_num();
    int cent = round(change * 100);
    int count = 0;
    while (cent > 0)
    {
        if (cent >= 25)
        {
            cent -= 25;
            count++;
        }
        else if (cent >= 10)
        {
            cent -= 10;
            count++;
        }
        else if (cent >= 5)
        {
            cent -= 5;
            count++;
        }
        else
        {
            cent -= 1;
            count++;
        }
    }
    printf("Number of coins to receive is %d\n", count);
}