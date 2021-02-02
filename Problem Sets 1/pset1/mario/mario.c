#include <stdio.h>
#include <cs50.h>

/*
Ask user for number, make sure number is within the range of 1 to 8.
If user enters 4
   *
  **
 ***
****
*/
// Function declaration
int get_positive_int(void);

// Function to prompt user to enter positive number.
int get_positive_int(void)
{
	int num;
	do
	{
		num = get_int("Enter Positive Number\n");
	}
	while(num < 1);
	return num;
}

int main()
{
	int numInput;
	numInput = get_positive_int();
	for(int row = 1; row <= numInput; row++) // row
	{
		for(int sp = 1; sp <= (numInput - row); sp++) // spacing
		{
			printf(" ");
		}
		for(int col = 1; col <= row; col++) // column
		{
 			printf("#");
		}
		printf("\n");
	}
}
