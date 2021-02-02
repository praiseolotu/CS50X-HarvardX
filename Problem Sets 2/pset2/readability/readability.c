#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <ctype.h>
/* Coleman-Liau index = 0.0599 * L - 0.296 * S - 15.8
   Note that L = letter / word * 100
   Note that S = sentence / word * 100
   Letter can be uppercase or lowercase. Letters should not include digits, punctuation and other symbols.
   A word is sequence of characters separated by space.
   A sentence ends with poriod, exclamation mark, question mark
   The Grade X should be rounded up.
 */
float countLetter(char *);
float countWords(char *);
float countSentence(char *);
int main()
{

    float L, S, grade;
    char *text = get_string("Text: ");
    L = (countLetter(text) / countWords(text)) * 100.00;
    S = (countSentence(text) / countWords(text)) * 100.00;
    grade = ((0.0588 * L) - (0.296 * S) - 15.8);
    int index = round(grade);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

float countLetter(char mytext[])
{
   int count = 0, i = 0;
   while (mytext[i] != '\0')
   {
      if (isalpha(mytext[i]))
        {
			count++;
		}
		i++;
	}
	return count;
}

float countWords(char mytext[])
{
	int count = 1, i = 0;
	while (mytext[i] != '\0')
	{
		if (mytext[i] == ' ')
		{
			count++;
		}
		i++;
	}
	return count;
}

float countSentence(char mytext[])
{
    int count = 0, i = 0;
	while (mytext[i] != '\0')
	{
		if (mytext[i] == '.' || mytext[i] == '?' ||mytext[i] == '!')
		{
			count++;
		}
		i++;
	}
	return count;
}