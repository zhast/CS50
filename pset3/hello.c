#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Please enter your name: ");
    printf("Hello, %s!", name);
}