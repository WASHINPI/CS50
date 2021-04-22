#include<stdio.h>

void printWhiteSpace(int length){
   for(int i = 0; i< length;i++){
	   printf(" ");
   }
}
void printHash(int length){
	for(int i = 0; i< length;i++){
	   printf("#");
    }
}

int main(void){
	int height;
	do {
		printf("Enter height of pyramids: ");
		scanf("%d",&height);
	}while(height < 0 || height > 8);

	for(int i = 1; i<= height; i++){
		printWhiteSpace(height-i);
		printHash(i);
		printWhiteSpace(1);
		printHash(i);
		printf("\n");
	}
}