#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Making the function prototypes to let know the computer that these functions exist
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Asks for the text for which we want to know its readability level
    string text = get_string("Text: ");

    //Gets the number of letters, words and sentences in the text
    int nLetters = count_letters(text);

    int nWords = count_words(text);

    int nSentences = count_sentences(text);

    //Calculates the readability level of the text
    int index = round(0.0588 * ((nLetters / (float) nWords) * 100.0) - 0.296 * ((nSentences / (float) nWords) * 100.0) - 15.8);

    //Prints the readability level of the text
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Counts the number of letters in a given text
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

//Counts the number of words in a given text
int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    return words;
}

//Counts the number of sentences in a given text
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}
