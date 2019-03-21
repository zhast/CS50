#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2) // Check if there is only one command line argument
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    string hash = argv[1];

    char salt[3]; // Creating a salt, which is the first two characters of the hash
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';

    string lettersToTry = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int lettersCount = strlen(lettersToTry);

    char key[6] = {'\0','\0','\0','\0','\0','\0'};

    for(int fifth = 0; fifth < lettersCount; fifth++)
    {
        for(int fourth = 0; fourth < lettersCount; fourth++)
        {
            for(int third = 0; third < lettersCount; third++)
            {
                for(int second = 0; second < lettersCount; second++)
                {
                    for(int first = 0; first < lettersCount; first++)
                    {
                        key[0] = lettersToTry[first];
                        key[1] = lettersToTry[second];
                        key[2] = lettersToTry[third];
                        key[3] = lettersToTry[fourth];
                        key[4] = lettersToTry[fifth];

                        if(strcmp(crypt(key, salt), hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }


                    }

                }

            }

        }

    }

}