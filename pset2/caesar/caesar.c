#include <cs50.h> // Has get_datatype functions
#include <stdio.h> // printf
#include <string.h> // Allows for string datatype
#include <ctype.h> // Allows for isupper and islower, and isalpha functions
#include <stdlib.h> // Has atoi function, which converts string to int

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid imput! Only one k value accepted\n");
        return 1;
    }

    int shift = atoi(argv[1]);

    string unscrambled = get_string("plaintext: ");

    printf("ciphertext: ");


    for (int i = 0 ; i < strlen(unscrambled); i++)
    {
        if (isalpha(unscrambled[i]))
        {
            if (isupper(unscrambled[i]))
            {
                printf("%c", ((unscrambled[i] - 'A' + shift) % 26) + 'A');
            }

            else
            {
                printf("%c", ((unscrambled[i] - 'a' + shift) % 26) + 'a');
            }

        }
        else
        {
            printf("%c", unscrambled[i]);
        }

    }

    printf("\n");



    return 0;

}