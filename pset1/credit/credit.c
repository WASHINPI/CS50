/*
 File: credit.c
 Project: CS50
 File Created: Sunday, 25th July 2021 2:00:54 pm
 Author: Taulut Hossain Washi (taulutwashi@gmail.com)
*/

#include <stdio.h>
#include <cs50.h>

bool isMasterCard(long card)
{
	return (card / 10 == 5) && (0 < card % 10 && card % 10 < 6);
}

bool isAmexCard(long card)
{
	return (card / 10 == 3) && (card % 10 == 4 || card % 10 == 7);
}

bool isVisaCard(long card)
{
	return card / 10 == 4;
}

long getUserInput()
{
	long cardNumber;
	do
	{
		cardNumber = get_long("Enter credit card number: ");
	} while (cardNumber <= 0);

	return cardNumber;
}

int getCardNumberLength(long cardNumber)
{
	int length = 0;
	while (cardNumber > 0)
	{
		cardNumber = cardNumber / 10;
		length++;
	}
	return length;
}

bool isValidCardLength(int number)
{
	return number != 13 && number != 15 && number != 16;
}

int getMod(long number)
{
	return number % 10;
}

long getDivision(long number)
{
	return number / 10;
}

long getStartingDigit(long number)
{
	do
	{
		number = getDivision(number);
	} while (number > 100);
	return number;
}

void printValidCardName(long cardStartingNumber)
{

	if (isMasterCard(cardStartingNumber))
	{
		printf("MASTERCARD\n");
	}
	else if (isAmexCard(cardStartingNumber))
	{ // Next check starting digits for card type
		printf("AMEX\n");
	}
	else if (isVisaCard(cardStartingNumber))
	{
		printf("VISA\n");
	}
	else
	{
		printf("INVALID\n");
	}
}

int checkSum(long cardNumber, int cardLength)
{
	int sum1 = 0;
	int sum2 = 0;
	int total = 0;
	int mod1, mod2, d1, d2;
	long card = cardNumber;

	do
	{
		// Remove last digit and add to sum1
		mod1 = getMod(cardNumber);
		cardNumber = getDivision(cardNumber);
		sum1 = sum1 + mod1;

		// Remove second last digit and multiply by 2
		mod2 = getMod(cardNumber);
		cardNumber = getDivision(cardNumber);

		mod2 = mod2 * 2;
		d1 = getMod(mod2);
		d2 = getDivision(mod2);
		sum2 = sum2 + d1 + d2;

	} while (cardNumber > 0);

	total = sum1 + sum2;

	if (getMod(total) != 0)
	{
		printf("INVALID\n");
		return 0;
	}

	// Get starting digits
	long start = getStartingDigit(card);
	printValidCardName(start);
	return 0;
}

int main(void)
{
	// Get User Card Number
	long cardNumber = getUserInput();

	// Count Card Number length
	int cardNumberLength = getCardNumberLength(cardNumber);

	// Check if length is valid
	if (isValidCardLength(cardNumberLength))
	{
		printf("INVALID\n");
		return 0;
	}
	// Implement luhn algorithm
	checkSum(cardNumber, cardNumberLength);
	return 0;
}
