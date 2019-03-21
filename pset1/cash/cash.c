#import <stdio.h>
#import <cs50.h>
#import <math.h>

int main(void){

    float change;
    int coins = 0;

    do{
        change = get_float("Change owed: ");
    }
    while (change < 0);

    change = round(change * 100);


    while (change - 25 >= 0){
        change -= 25;
        coins++;
    }

    while (change - 10 >= 0){
        change -= 10;
        coins++;
    }

    while (change - 5 >= 0){
        change -= 5;
        coins++;
    }

    while (change - 1 >= 0){
        change -= 1;
        coins++;
    }


    printf("%i\n", coins);

}