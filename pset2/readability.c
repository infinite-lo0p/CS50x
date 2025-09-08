#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_sentences(string s);
int count_letters(string s);
int count_words(string s);

int main(void)
{
    // prompt the user
    string s = get_string("Text: ");

    // counts
    int letters = count_letters(s);
    int words = count_words(s);
    int sentences = count_sentences(s);

    // Coleman–Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // print result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string s)
{
    int count = 1; // start at 1 because words = spaces + 1
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count++;
        }
    }
    return count;
}
