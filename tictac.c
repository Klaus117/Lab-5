// Version 0
// Testing IO stream, program compilalbity, makefile
// 8/31/23 06:00
//
// Version 1
// Functionality for printing board
// 8/31/2023


#include <stdio.h>
#include <string.h>

int print_board_row(int board_size, int row_num)
{
    char board_square_value = '_'; //this is the value at the board square ___ -> _x_ this represents x ('_' is a default value)
    char board_square_next_to_value = '_'; //this is the character next to value character ___ -> _x_ this represents _ _
    if (row_num == board_size - 1) //checks if this is the bottom row
        board_square_next_to_value = ' '; //if we know last row, then we dont need underscores
    else
        board_square_next_to_value = '_'; //else we need underscores (redudent but hopefully easier to read)

    //prints row of board (row is decided by row_num)
    for (int i = 0; i < board_size - 1; i++)
    {//iterate over every element of row (array?) but last
        board_square_value = 'A'; //this is the value at the board square ___ -> _x_ this represents x
        printf("%c%c%c|", board_square_next_to_value, board_square_value, board_square_next_to_value); //print element of row (skips last because dividers)
    }
    board_square_value = 'A'; //this is the value at the board square ___ -> _x_ this represents x
    printf("%c%c%c\n", board_square_next_to_value, board_square_value, board_square_next_to_value); //print last element of row
}

int print_board_full()
{
    int board_size = 3;
    printf("test board\n");

    //prints full board
    for (int row_num = 0; row_num < board_size; row_num++)
    {//iterate over every row of board (2-d array)
        print_board_row(board_size, row_num); //print a row of board
    }
}

int main(void)
{
    printf("hello world\n");
    //print_board_full();
    print_board_full();
}