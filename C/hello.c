#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Asks the name of the person
    string name = get_string("What is your name?\n");

    //Greets this person
    printf("hello, %s\n", name);
}