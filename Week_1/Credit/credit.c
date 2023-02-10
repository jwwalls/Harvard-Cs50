#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_card = get_long("Enter Number: ");
    int credit_card_array_index = 0;
    int credit_card_array[16];
    int checksum = 0;
    int overflow = 0;

    while (credit_card)                                                                             //Reverse fill digits
    {
        credit_card_array[credit_card_array_index] = credit_card % 10;
        credit_card /= 10;
        credit_card_array_index++;
    }

    int array_length = credit_card_array_index;
    int first_two_digits = credit_card_array[credit_card_array_index - 1] * 10 + credit_card_array[credit_card_array_index - 2];



    for (credit_card_array_index = 1; credit_card_array_index < 16; credit_card_array_index+=2)   //Double every other digit and track overflow
    {
        credit_card_array[credit_card_array_index] *= 2;
        if (credit_card_array[credit_card_array_index] > 9)
        {
             credit_card_array[credit_card_array_index] -= 10;
             overflow++;
        }
    }


    for (credit_card_array_index = 0; credit_card_array_index < 16; credit_card_array_index++)    //Checksum + Overflow
    {
        checksum += credit_card_array[credit_card_array_index];
    }
        checksum += overflow;


    if(array_length > 12 && array_length < 17)                                                     //Card Verification
    {
        if (checksum % 10 == 0)
        {
            if (first_two_digits == 34 || first_two_digits == 37)
            {
                    printf("AMEX\n");
            }
            else if (first_two_digits >= 51 && first_two_digits <= 55)
            {
                    printf("MASTERCARD\n");
            }
            else if (first_two_digits >= 40 && first_two_digits <=49)
            {
                    printf("VISA\n");
            }
            else printf("INVALID\n");
        }else printf("INVALID\n");
    }else printf("INVALID\n");
}