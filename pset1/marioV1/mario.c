#include<stdio.h>
#include<cs50.h>

void printHash(int length, int i){
    for( int j = length; j > i; j--){
        printf(" ");
    }
    for(int j = 1; j <= i; j++){
        printf("#");
    }
}

int main(void){
    int height;
    
    do{
        height = get_int("Height: ");
    }
    while(height<1 || height>8);
    
    for(int i=1;i<=height;i++){
        printHash(height,i);
        printf("\n");
    }
}