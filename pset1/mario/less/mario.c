#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Height: ");

    while (n < 1 || n > 8)
    {
        n = get_int("Height: ");
    }

    for(int i = 1; i <= n; i++) // Loop that starts at 1 and counts up to n
    {
        for(int k = n - i; k > 0; k--) // Loop that prints " " n - i times
        {
            printf(" ");
        }


        for(int j = 0; j < i; j++) // Loop that prints a "#" i times
        {
            printf("#");
        }

        printf("\n");

    }


}