#include <cs50.h>
#include <stdio.h>

int main(void)
{

   int blocks;
   do
   {
        blocks = get_int("Height: ");
   }
    while(blocks > 8 || blocks < 1 );

   for (int i = 0; i < blocks; i++)  //Rows
   {
      for(int h = blocks - i - 1; h > 0; h--) // Decending blank spaces
       {
            printf(" ");
       }

       for (int j = 0; j < i + 1; j++)   //Left Pyramid
       {
        printf("#");
       }

       printf("  ");                    //Blank space between Pyramids

       for (int k = 0; k < i; k++)       // Right Pyramid
       {
        printf("#");
       }

        printf("#\n");
   }

}