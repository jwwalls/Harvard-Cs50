#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string passage = get_string("Text: ");
    float sentence_counter = 0;
    float letter_counter = 0;
    float word_counter = 1;
    float average_number_letters = 0;
    float average_number_sentence = 0;
    float reading_score = 0;

     for(int index = 0; index < strlen(passage); index++)
    {
        if(passage[index] == ' ')
        {
            word_counter++;
        }
        else if(passage[index] == '.' || passage[index] == '!' || passage[index] == '?')
        {
            sentence_counter++;
        }
        else
        {
              if(passage[index] >=65 && passage[index] <=122)
              {
                letter_counter++;
              }
        }
    }
    average_number_letters = ((float)letter_counter / word_counter) * 100;
    average_number_sentence = ((float)sentence_counter / word_counter) *100;
    reading_score = (0.0588 * average_number_letters) - (0.296 * average_number_sentence) - 15.8;

    if(reading_score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (reading_score > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(reading_score));
    }

    //printf("let %f  word %f  sen %f\n", letter_counter, word_counter, sentence_counter);
}