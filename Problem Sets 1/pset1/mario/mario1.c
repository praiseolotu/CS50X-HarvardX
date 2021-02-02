#include <stdio.h>
#include <cs50.h>
int get_positive_int(void);
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Enter Positive Number: \n");
    }
    while(n < 1 || n > 8);
    return n;
}

int main ()
{
  	int height = get_positive_int();

	for(int row = 1; row <= height; row++) // row
	{
		for(int sp = 1; sp <= (height - row); sp++) // spacing
		{
			printf(" ");
		}
		for(int col = 1; col <= row; col++) //column
		{
			printf("#"); 
			printf("  ");
            for (int col = 1; col <= row; col++)
            {
            printf("#");
            }
		}
	/*	for(int sp1 = 1; sp1 <= 1; sp1++) // spacing
		{
			printf(" ");
		}
		for(int col1 = 1; col1 <= row; col1++) //column
		{
			printf("  #");

		}*/
		printf("\n");
	}
}