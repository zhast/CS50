#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n = get_long("Number: ");
    long CC = n; // Store an original copy of the CC number

    long oddSum = 0;
    long evenSum = 0;
    long numDigits = 0;
    long isValid = 0;

    while(n > 0) // This loop iterates over the credit card's digits (n) from the back, summing the even and odd numbers according to Luhn's Algorithm
    {
        if(numDigits % 2 != 0) // If n's digit is odd, double it and add its digits
        {
            if(n % 10 > 4)
            {
                oddSum += 1 + (2 * (n % 10)) % 10;
            }

            else
            {
                oddSum += 2 * (n % 10);
            }

        }

        else // If n's digit is even, simply sum it
        {
            evenSum += n % 10;
        }

        n /= 10;
        numDigits++;
    }

    if ((evenSum + oddSum) % 10 == 0)
    {
        isValid = 1;
    }


    long firstDigit = (CC / (long)pow(10, (numDigits - 1))) % 10;
    long secondDigit = (CC / (long)pow(10, (numDigits - 2))) % 10;
    long firstTwoDigits = 10 * firstDigit + secondDigit;

    if(numDigits == 15 && isValid == 1 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        printf("AMEX\n");
    }

    else if(numDigits == 16 && isValid == 1 && (firstTwoDigits >= 51 && firstTwoDigits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if((numDigits == 16 || numDigits == 13) && isValid == 1 && firstDigit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }


}

