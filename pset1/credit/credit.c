#include <stdio.h>
#include <cs50.h>

int checkSum(long cardNumber, int cardLength)
{
	int sum1 = 0;
	int sum2 = 0;
	int total = 0;
	long card = cardNumber;
	int mod1, mod2, d1, d2;

	do
	{
		// Remove last digit and add to sum1
		mod1 = cardNumber % 10;
		cardNumber = cardNumber / 10;
		sum1 = sum1 + mod1;

		// Remove second last digit and multiply by 2
		mod2 = cardNumber % 10;
		cardNumber = cardNumber / 10;

		mod2 = mod2 * 2;
		d1 = mod2 % 10;
		d2 = mod2 / 10;
		sum2 = sum2 + d1 + d2;
	} while (cardNumber > 0);

	total = sum1 + sum2;

	if (total % 10 != 0)
	{
		printf("INVALID\n");
		return 0;
	}

	// Get starting digits
	long start = card;
	do
	{
		start = start / 10;
	} while (start > 100);

	// Next check starting digits for card type
	if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
	{
		printf("MASTERCARD\n");
	}
	else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
	{
		printf("AMEX\n");
	}
	else if (start / 10 == 4)
	{
		printf("VISA\n");
	}
	else
	{
		printf("INVALID\n");
	}
	return 0;
}

int main(void)
{
	long cardNumber;
	do
	{
		cardNumber = get_long("Enter credit card number: ");
	} while (cardNumber <= 0);

	// Count card length
	int i = 0;
	long count = cardNumber;

	while (count > 0)
	{
		count = count / 10;
		i++;
	}

	// Check if length is valid
	if (i != 13 && i != 15 && i != 16)
	{
		printf("INVALID\n");
		return 0;
	}
	checkSum(cardNumber, i);
	return 0;
}
