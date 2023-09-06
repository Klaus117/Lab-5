// Version 0
// Testing IO stream, program compilalbity, makefile
// 8/31/2023 06:00
//
// Version 1
// Functionality for printing board
// 8/31/2023 08:00
//
// Version 1.1
// Added row and column indicators
// 8/31/2023 08:30
//
// Version 2.0
// Added function that allows input strings to update board state
// 8/31/2023 10:00
//
// Version 3.0
// adding user input requests
// possible implement game loop
//
// Version 3.1
// implement user input requests with enumeration and class coordinate type


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coordinate.h"

#define BOARDSIZE 3
#define A1 1
#define B1 2
#define C1 3
#define A2 4
#define B2 5
#define C2 6
#define A3 7
#define B3 8
#define C3 9

//Global for simplicity
char board_array[BOARDSIZE][BOARDSIZE];

int print_board_row(int board_size, int row_num)
{
    char board_square_value = '_'; //this is the value at the board square ___ -> _x_ this represents x ('_' is a default value, will change if it is occupied)
    char board_square_next_to_value = '_'; //this is the character next to value character ___ -> _x_ this represents _ _ (always '_')
    int row_num_indicator = abs((row_num - (BOARDSIZE - 1)) % BOARDSIZE) + 1; //indicates row number EX "1 ___|___|___" ; the '1' would be the row number //to follow example math operation necessary (too much to explain in comment)

    if (row_num == board_size - 1) //checks if this is the bottom row
        board_square_next_to_value = ' '; //if we know last row, then we dont need underscores
    else
        board_square_next_to_value = '_'; //else we need underscores (redudent but hopefully easier to read)

    //prints row of board (row is decided by row_num)
    printf("%d%c", row_num_indicator, ' '); //prints the beginning of the row EX "1 ___|___|___" ; the '1' would be the row number
    for (int i = 0; i < board_size - 1; i++)
    {//iterate over every element of row (array?) but last
        board_square_value = board_array[row_num_indicator-1][i]; //this is the value at the board square ___ -> _x_ this represents x
        
        printf("%c%c%c|", board_square_next_to_value, board_square_value, board_square_next_to_value); //print element of row (skips last because dividers)
    }
    board_square_value = board_array[row_num_indicator-1][BOARDSIZE-1]; //this is the value at the board square ___ -> _x_ this represents x
    printf("%c%c%c\n", board_square_next_to_value, board_square_value, board_square_next_to_value); //print last element of row
}

int print_board_full()
{
    int board_size = BOARDSIZE;
    printf("test board\n");

    //prints full board
    for (int row_num = 0; row_num < board_size; row_num++)
    {//iterate over every row of board (2-d array)
        print_board_row(board_size, row_num); //print a row of board
    }
    printf("   A   B   C \n");
}

int initialize_board()
{
    for (int i = 0; i < BOARDSIZE; i++) //write all rows
    {
        for (int j = 0; j < BOARDSIZE; j++)
        {
            board_array[i][j] = '_';
        }
    }
    for (int j = 0; j < BOARDSIZE; j++) //overwrite for last row
    {
            board_array[0][j] = ' ';
    }
}

int edit_array_at(int row, int column, char value)
{//variable row is offset from row indicator on game by 1 ([1-3 in game] vs [0-2 in this function]), similar with columns ABC -> 012
    board_array[row][column] = value;
}

int perform_user_request(char input_string[], int input_string_length, char new_character)
{
    printf("%s, %d\n", input_string, input_string_length);
    if (input_string_length != 2) //check for correct size of input
    {
        printf("invalid input string\n");
        return -1;// ERROR code -1
    }

    if(1)//compact IDE
    {
        //printf("1 is true\n");
        if (strcmp(input_string, "A1") == 0)
        {
            //printf("input is A1\n");
            edit_array_at(0,0, new_character);
        }
        else if (strcmp(input_string, "A2") == 0)
        {
            edit_array_at(1,0, new_character);
        }
        else if (strcmp(input_string, "A3") == 0)
        {
            edit_array_at(2,0, new_character);
        }
        else if (strcmp(input_string, "B1") == 0)
        {
            edit_array_at(0,1, new_character);
        }
        else if (strcmp(input_string, "B2") == 0)
        {
            edit_array_at(1,1, new_character);
        }
        else if (strcmp(input_string, "B3") == 0)
        {
            edit_array_at(2,1, new_character);
        }
        else if (strcmp(input_string, "C1") == 0)
        {
            edit_array_at(0,2, new_character);
        }
        else if (strcmp(input_string, "C2") == 0)
        {
            edit_array_at(1,2, new_character);
        }
        else if (strcmp(input_string, "C3") == 0)
        {
            edit_array_at(2,2, new_character);
        }
        else // string was right size, but none of our valid cases
        {
            printf("invalid input string\n");
            return -1;// ERROR code -1
        }
        return 0; //if we reach here assume good input?
    }
}

// for debugging
int print_board_array()
{
    for (int i = 0; i < BOARDSIZE; i++)
    {
        for (int j = 0; j < BOARDSIZE; j++)
        {
            printf("%c\n", board_array[i][j]);
        }
    }
}

// void print_coordinate(int row, int col){
//     printf("You are here: %c%c\n", col + 'A', row + '1');
// }

int user_input_request()
{
    printf("Please input a coordinate (ex A1):\n");
    char data[64];
    if(fgets(data, sizeof(data), stdin)) //attempt to read user input
    { //sucessful read of user input
        printf("%s", data);
        // print_coordinate(1,1);
        //strip of newline character
        if (strlen(data) > 0 && data[strlen(data)-1] == '\n') 
        {
            data[strlen(data)-1] = '\0';
        }
        //printf("%d, %d, %d\n", data[0], data[1], data[2]);
    }
    else 
    { //fail read of user input
        printf("Error: Reading User Input (return -1)\n");
        return -1;
    }

    //Assumes successful read of user input (otherwise hit return statement when fail)
    printf("length of input is:%lu\n", strlen(data));
    if(strlen(data) != 2) //2 == 2 characters plus terminate
    { //user input is wrong length
        printf("Error: Please Input Correct Number of Inputs: 2 characters ex A1 (return -1)\n");
        return -1; //REPLACE
    }

    //Assumes correct number of characters
    //TODO: 
    // Use enum instead of what I am doing
    // simpler hard coding


    // Use ASCII to determine input row and column
    // char column_input = data[0];
    // int column = column_input - 'A';

    // char row_input = data[1];
    // int row = row_input - '1';

    // transfering data back
    // - create a data type "coordinate" contains 2 integers which access the board array
    //      1. make a Coordinate class
    //      2. add helper / class functions
    //      3. link this class / object with Makefile
    // - or use a int* pointer to an int array (containing the two coordinates)

    if(strcmp(data, "A1") == 0)
        return A1;
    else if(strcmp(data, "A2") == 0)
        return A2;
    else if(strcmp(data, "A3") == 0)
        return A3;
    else if(strcmp(data, "B1") == 0)
        return B1;
    else if(strcmp(data, "B2") == 0)
        return B2;
    else if(strcmp(data, "B3") == 0)
        return B3;
    else if(strcmp(data, "C1") == 0)
        return C1;
    else if(strcmp(data, "C2") == 0)
        return C2;
    else if(strcmp(data, "C3") == 0)
        return C3;
    else // input is not a valid coordinate
    {
        printf("Error: Invalid Coordinate: A1-3 B1-3 C1-3\n");
        return -1;
    }
    printf("Error: you should not be here.\n");
    return -1;
}

// int game_loop()
// {
    
// }

int main(void)
{
    printf("hello world\n");
    //print_board_full();
    // print_board_full();
    // initialize_board();
    // print_board_full();
    // edit_array_at(2, 2, 'h');
    // print_board_full();
    // print_board_array();
    // perform_user_request("A2", strlen("A2"), 'X');
    // print_board_full();
    // perform_user_request("C3", strlen("C3"), 'X');
    // print_board_full();
    initialize_board();
    print_board_full();
    int x = user_input_request();
    printf("Input read is:%d\n", x);
    print_board_full();

    struct Coordinate coord = Coordinate(1,1);
    printf("Testing Struct Members: row=%d, col=%d\n", coord.row, coord.col);
}