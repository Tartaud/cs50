#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number;
    long lastNumber = 0;
    long numberDivisor = 1;
    int digitsInNumber = 0;
    long singleNumber = 0;
    long sumDigits = 0;
    long firstTwoDigits = 0;

    //Asks the credit card number
    number = get_long("Number: ");

    //Gets the number of digits in the credit card number
    for (long i = 10; lastNumber != number; i *= 10)
    {
        lastNumber = number % i;
        digitsInNumber++;
    }

    //Does the Luhn's Algorithm
    for (long i = 0; i < digitsInNumber; i++)
    {
        numberDivisor *= 10;
        singleNumber = ((number % numberDivisor) - (number % (numberDivisor / 10))) / (numberDivisor / 10);

        //Gets the first two digits of the card number
        if (i == digitsInNumber - 2)
        {
            firstTwoDigits += singleNumber;
        }
        if (i == digitsInNumber - 1)
        {
            firstTwoDigits += singleNumber * 10;
        }

        if (i % 2 == 1)
        {
            singleNumber *= 2;
            if (singleNumber % 100 != singleNumber % 10)
            {
                sumDigits += singleNumber % 10;
                singleNumber = (singleNumber - (singleNumber % 10)) / 10;
            }
        }

        sumDigits += singleNumber;

    }

    //Sees if the credit card is valid and if yes, print the type of the card
    if (sumDigits % 10 == 0 && digitsInNumber >= 13 && digitsInNumber <= 16)
    {
        if ((digitsInNumber == 16 && singleNumber == 8) || (digitsInNumber == 13 && singleNumber == 4))
        {
            printf("VISA\n");
        }
        else if (digitsInNumber == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (digitsInNumber == 16 && firstTwoDigits >= 51 && firstTwoDigits <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}