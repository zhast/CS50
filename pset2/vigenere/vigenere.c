#include <cs50.h> // Has get_datatype functions
#include <stdio.h>
#include <string.h> // Allows for string use
#include <ctype.h> // Allows for isupper and islower, and isalpha functions
#include <stdlib.h> // Has atoi function, which converts string to int

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Invalid imput! Only one cipher key accepted\n");
        return 1;
    }

    string key = argv[1];
    int keyCounter = 0;

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Cipher code is not alpha!\n");
            return 1;
        }
    }


    int shift;
    int keyLen = strlen(argv[1]);


    string unscrambled = get_string("plaintext: ");

    printf("ciphertext: ");


    for (int i = 0 ; i < strlen(unscrambled); i++)
    {


        if (isalpha(unscrambled[i]))
        {
            keyCounter = keyCounter % keyLen; // Ensure the keycounter can loop through the indexes

            if(isalpha(key[keyCounter])) // Change shift so that it corresponds with the next value of the cipher key
            {
                if (isupper(key[keyCounter]))
                {
                    shift = key[keyCounter] - 'A';
                    keyCounter++;
                }

                else if (islower(key[keyCounter]))
                {
                    shift = key[keyCounter] - 'a';
                    keyCounter++;
                }

                // printf("k:%i", keyCounter);
            }


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