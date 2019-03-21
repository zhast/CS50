#include <cs50.h>
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("file.txt", "r");

    if(file == NULL)
    {
        printf("Invalid file");
        return 1;
    }

    int toggle = 0;
    char c = '\0';
    char prev = '\0';

    while(feof(file) == 0)
    {
        c = fgetc(file);

        if (c == ':')
        {
            prev = c;
            c = fgetc(file);

            if (c == ' ')
            {
                toggle = 1;
            }
            else
            {
                c = prev;
            }

        }

        if (c == '\n')
        {
            toggle = 0;
        }

        if (toggle == 1)
        {
            if(prev == ':')
            {
                printf("%c",prev);
            }
            else
            {
                printf("%c", c);
            }
        }
    }

    printf("\n");

    // string name = get_string("Please enter your name: ");

    // fprintf(file, "%s", name);

    // fclose(file);
}