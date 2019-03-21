// Make wedges for Mario to jump off of

#include <stdio.h>
#include <cs50.h>

int main(void){

    int n = get_int("Height: ");

    while (n < 0 || n > 23){
        n = get_int("Height: ");
    }

    for (int i = 0; i < n; i ++){
        for(int spaces = n-2-i; spaces >= 0; spaces--){
            printf(" ");
        }

        for (int hash = i; hash >= 0; hash--){
            printf("#");
        }

        printf("  ");

        for (int hash = i; hash >= 0; hash--){
            printf("#");
        }

        printf("\n");
    }

}