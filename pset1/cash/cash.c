#include<stdio.h>
#include<cs50.h>
#include<math.h>


int calculateCoins(int coins, int changes);

int main(void){
    float cash;
    int coins;
    int totalChanges = 0;

    do {
        cash = get_float("Change owed:");
    }
    while(cash <= 0);

    coins = round(cash * 100);

    totalChanges = calculateCoins(coins, totalChanges);

    printf("%d \n", totalChanges);

    return 0;
}


int calculateCoins(int coins, int changes){

    int quarters = 25,
        dimes = 10,
        nickels = 5,
        pennies = 1;

    if(coins >= quarters) {
        return calculateCoins(coins - quarters, ++changes);
    }

    if(coins >= dimes) {
        return calculateCoins(coins - dimes, ++changes);
    }

    if(coins >= nickels) {
        return calculateCoins(coins - nickels, ++changes);
    }

    if(coins >= pennies) {
       return calculateCoins(coins - pennies, ++changes);
    }

    return changes;

}

