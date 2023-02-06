#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
   int population_size;
   int population_end;
   int population_growth;
   int years = 0;
   do
   {
        population_size = get_int("Start size: ");
   }while(population_size < 9);

    // TODO: Prompt for end size
   do
   {
        population_end = get_int("End size: ");
   }while(population_end < population_size);


    // TODO: Calculate number of years until we reach threshold
    population_growth = population_size;
    do
    {
        population_growth =  population_growth + (population_growth / 3) - (population_growth / 4) ;
        years++;
    }while(population_growth < population_end);

    // TODO: Print number of years
    if (population_size == population_end)
    {
        printf("Years: 0\n");
    }
    else
    {
    printf("Years: %i\n", years);
    }
}
