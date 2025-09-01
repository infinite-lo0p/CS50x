#include <cs50.h>
#include <stdio.h>

void print_row(int bricks, int spaces);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // print the row of bricks
        print_row(i + 1, n - i - 1);
    }
}

void print_row(int bricks, int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
