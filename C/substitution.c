#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//Creates the function prototypes to let know the computer that these functions exist
int isOnlyAlphabetical(string text);
int isEachLetterOnce(string text);

int main(int argc, string argv[])
{
    //Watches if there is more or less than a single command line argument and prints it if so
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Watches is the key contains exactly 26 characters and prints it if not
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Watches if there are non-alphabetical characters in the key and printsit if so
    else if (!isOnlyAlphabetical(argv[1]))
    {
        printf("Key must contain only alphabetic characters.\n");
        return 1;
    }
    //Watches if there are letters that appear more than once in the key and prints it if so
    else if (!isEachLetterOnce(argv[1]))
    {
        printf("Key must contain a letter exactly once.\n");
        return 1;
    }

    //Asks for the plaintext to convert
    string plaintext = get_string("plaintext: ");

    //Creates the ciphertext with the same length as the plaintext
    string ciphertext = plaintext;

    //Converts the plaintext to the ciphertext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] <= 90 && plaintext[i] >= 65)
        {
            ciphertext[i] = argv[1][plaintext[i] - 65];

            if (islower(ciphertext[i]))
            {
                ciphertext[i] = toupper(ciphertext[i]);
            }
        }
        else if (plaintext[i] <= 122 && plaintext[i] >= 97)
        {
            ciphertext[i] = argv[1][plaintext[i] - 97];

            if (isupper(ciphertext[i]))
            {
                ciphertext[i] = tolower(ciphertext[i]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}


//Checks if there are non-alphabetical characters in a given text
int isOnlyAlphabetical(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            return false;
        }
    }

    return true;
}

//Checks if there are letters that appear more than once in a given text
int isEachLetterOnce(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (text[i] == text[j] && i != j)
            {
                return false;
            }
        }
    }

    return true;
}
