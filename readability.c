#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main(void)
{
    string s = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    float average_letters;
    float average_words;

    for (int i = 0; s[i]; i++)
    {
        s[i] = tolower(s[i]) ;
    }

    //create for loop to make your string include only letters
    for (int i = 0; i < strlen(s); i++)
    {
        // //this loop looks through the string and calculates whitespaces
        int c = s[i];
        if (isspace(c))
        {
            words++;
        }


        //this loop excludes symbols and only calculates letters
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            letters++;
        }

        // //this loop calculates symbols aka number of sentences
        if (c == '!' || c == '?' || c == '.')
        {
            sentences++;
        }
    }

    // printf("%i sentence(s)\n", sentences);
    // printf("%i letter(s)\n", letters);
    // printf("%i words(s)\n", words);

    average_letters = 100 * ((float) letters / (float) words);
    average_words = 100 * ((float) sentences / (float) words);
    float index = round(0.0588 * average_letters - 0.296 * average_words - 15.8);

    // printf("%.0f\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}

