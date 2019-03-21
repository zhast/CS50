// Resizes a file by a factor of n

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // make sure there is an appropreate number of commands
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *number = argv[1];
    int n = atoi(number);

    char *infile = argv[2];
    char *outfile = argv[3];

    if (n < 1 || n > 100)
    {
        printf("n must be between 1 and 100\n");
        return 1;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER and copy to new file
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;

    // read infile's BITMAPINFOHEADER and copy to new file
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Determine the new dimensions
    bi_new.biWidth  = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;

    // Determine the old and new paddings

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Determine new image sizes
    bi_new.biSizeImage = (bi_new.biWidth * sizeof(RGBTRIPLE) + outpadding) * abs(bi_new.biHeight);
    bf_new.bfSize = bf.bfSize - bi.biSizeImage + bi_new.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Print each column n times
        for (int j = 0; j < n; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int l = 0 ; l < n; l++)
                {
                    // write n number of RGB triples to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // Add padding for new file
            for (int l = 0; l < outpadding; l++)
                fputc(0x00, outptr);

            // Move pointer to start of scanline
            if (j < n - 1)
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
}