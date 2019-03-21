#include <cs50.h>
#include <stdio.h> // reading and writing of files
#include <stdlib.h> // atoi (string --> integer conversion)

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n"); // There were more than two parameters entered in the command line
        return 1;
    }

    char* input = argv[1]; // Assign char array to input


    // Open card file

    FILE* inptr = fopen(input, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Not readable"); // fprintf prints out to the output stream you specify, in this case stderr
        return 2; // Stops program if file is not readable
    }

    char picture[8]; // JPEG file name

    unsigned char buffer[512]; // Makes a buffer that is the size of one block

    FILE* outptr = NULL; // Makes a pointer to an outfile

    int counter = 0; // A counter for how many files were made

    // Read file

    while (fread(buffer, 512, 1, inptr) == 1) // While the file returns no errors
    {
        // See if this is the beginning of a JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            buffer[3] >= 0xe0 &&
            buffer[3] <= 0xef)
            {
                if (counter > 0) // Closes file every time a start of new JPEG is found (except first)
                {
                    fclose(outptr);
                }

                sprintf(picture, "%03d.jpg", counter); // Name file according to counter

                outptr = fopen(picture, "w"); // Opens image to write

                if (outptr == NULL)
                {
                    fprintf(stderr, "Could not create picture %s.\n", picture);
                    return 3;
                }

                counter++; // Increment pics written

            }

        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }

    // Close file
    fclose(outptr);
    fclose(inptr);

    return 0;
}