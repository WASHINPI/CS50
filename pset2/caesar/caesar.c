/*
 File: credit.c
 Project: CS50
 File Created: Monday, 2nd August 2021 01:26:54 pm
 Author: Taulut Hossain Washi (taulutwashi@gmail.com)
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int getCaesarKey()
{

	int key;
	do
	{
		key = get_int("Enter Number: ");
	} while (key < 0);

	return key;
}

string getMessage()
{
	string msg;
	do
	{
		msg = get_string("Enter Your message: ");
	} while (strlen(msg) <= 0);

	return msg;
}

int alphabetNumber(char keys)
{
	return isupper(keys) ? 65 : 97;
}

string encryptMessageByKey(int key, string message)
{

	int messageLength = strlen(message);

	for (int i = 0; i < messageLength; i++)
	{
		if (isupper(message[i]) || islower(message[i]))
		{
			int remaingNumber = message[i] - alphabetNumber(message[i]);
			int newNumber = key + remaingNumber;
			int result = (newNumber % 26) + alphabetNumber(message[i]);
			message[i] = result;
		}
	}

	return message;
}

int main()
{

	int caesarKey = getCaesarKey();
	string message = getMessage();

	string encryptMessage = encryptMessageByKey(caesarKey, message);

	printf("%s \n", encryptMessage);

	return 0;
}