#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // I use the get_string function from cs50
    string name = get_string("What is your name?\n");
    printf("hello, world %s\n", name);
}