# Questions

## What's `stdint.h`?

A header file that declares integers should have specific widths

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

They are just examples of fixed width integer types

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE  is 1 byte
DWORD is 4 bytes
LONG  is 4 bytes
WORD  is 2 BYTES

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes is a WORD called bfType which specifies the file type. The signature of a bitmap is (0x4D42)

## What's the difference between `bfSize` and `biSize`?

bfSize specifies the size in bytes of the bitmap file
biSize specifies the size of the structure in bytes.

## What does it mean if `biHeight` is negative?

A negative biHeight value indicates a top down device independent bitmap with its origin in the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount determines the numnber of bits that define each pixel.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Because it can't find a file to write to.

## Why is the third argument to `fread` always `1` in our code?

Because only one byte is being read at a time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

It will assign a value of 1 because the padding width is required to be a multiple of 4.

## What does `fseek` do?

Skips padding and goes to the next pixel.

## What is `SEEK_CUR`?

Specifies the offset to count characters from the current file position.

## Whodunit?

I can't wait to find out
