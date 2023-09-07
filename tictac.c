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
//
// Version 4.0
// user input requests using char manipulatio and struct coodinate type


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coordinate.h"

#define BOARDSIZE 3
#define PLAYERCOUNT 2

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
    // printf("test board\n");

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

int edit_array_at(Coordinate coordinate, char new_character)
{
    board_array[coordinate.row][coordinate.col] = new_character; // notice that during access of array, [row][col] is used (everywhere else we use {col,row})
    return 1; //if we reach here assume good 
}

int perform_user_request(Coordinate coordinate, char new_character)
{
    // printf("input coordinate recieved in perform_user_input col:%d, row:%d\n", coordinate.col, coordinate.row);
    edit_array_at(coordinate, new_character);
    return 1; //if we reach here assume good 
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

// user_input_request
// requires a coordinate value to edit results into.
// processes user input. if the user input is valid, set the given coordinate to the value of the user input. else return -1.
// returns -1 for failure and 1 for success.
int user_input_request(Coordinate *coordinate) //user_input_validation 
{
    printf("Please input a coordinate (ex A1):\n");
    char data[64];
    if(fgets(data, sizeof(data), stdin) == NULL) //attempt to read user input
    { //fail read of user input
        printf("Error: Reading User Input (return -1)\n");
        return -1;
    }
    // continue if not fail read.

    // sucessful read of user input
    // printf("%s", data);
    // strip of newline character
    if (strlen(data) > 0 && data[strlen(data)-1] == '\n') 
    {
        data[strlen(data)-1] = '\0';
    }

    // Assumes successful read of user input (otherwise hit return statement when fail)
    // printf("length of input is:%lu\n", strlen(data));
    if(strlen(data) != 2) //2 == 2 characters plus terminate
    { //user input is wrong length
        printf("Error: Please Input Correct Number of Inputs: 2 characters ex A1 (return -1)\n");
        return -1;
    }
    
    if(data[0] >= 'A' && data[0] <= 'C' && data[1] >= '1' && data[1] <= '3')
    { // user input has valid range of chars
        *coordinate = str_to_coordinate(data); //edits given coordinate with user input

        // success //dont return because more validation (returns at end of function) // success
    }
    else
    { // user input does not have valid range of chars
        printf("Error: Please Input Correct Range of Inputs: 2 characters ex A-C and 1-3 (return -1)\n");
        return -1; 
    }

    // check if designated coordinate is available (empty == '_' or ' ')
    if(board_array[coordinate->row][coordinate->col] == '_' || board_array[coordinate->row][coordinate->col] == ' ')
    { // success it is a valid spot
        return 1; // if we manage to get here we have complete task successfully
    }
    else
    { // fail it is not a valid spot
        printf("Error: Invalid location (already occupied)\n");
        return -1;
    }
    
    printf("should not be here Line:%d File:%s\n", __LINE__, __FILE__);
    return -1;
}

int game_loop()
{
    initialize_board();
    int free_spaces = BOARDSIZE * BOARDSIZE;
    int winner = 0; //zero no win, 1 == player1 wins, 2 == player2 wins
    int turn_counter = 0;
    char player_piece = 'X';
    int player_turn = 1;
    while(free_spaces > 0 && !winner) // while there are still free spaces and there is not winner yet
    {
        print_board_full();
        Coordinate coord = newCoordinate(0,0);
        if(turn_counter % 2 == 0)
        { // if an even turn (player1 is X)
            player_piece = 'X';
            player_turn = 1;
        }
        else
        { // if an odd turn (player2 is O)
            player_piece = 'O';
            player_turn = 2;
        }

        printf("turn number:%d ... player%d's turn (places %c)\n", turn_counter, player_turn, player_piece);

        while(user_input_request(&coord) != 1)
        { // repeatedly attempt to get user input until sucess

        }
        
        perform_user_request(coord, player_piece);
        free_spaces--; // every successful turn should reduce free space by 1
        turn_counter++;
    }
    print_board_full(); // print last time as game finishes
}

int main(void)
{
    printf("hello world\n");
    // initialize_board();
    // print_board_full();
    game_loop();
    // Coordinate coord = newCoordinate(2,1);
    // perform_user_request(coord, 'X');
    // printf("Testing Struct Members: col=%d, row=%d\n", coord.col, coord.row);
    // print_board_full();
    // char string_coordinate[2];
    // coordinate_to_str(coord, string_coordinate);
    // printf("String value of coordinate: %s\n", string_coordinate);
    // printf("Change back to string: {%d,%d}\n", str_to_coordinate(string_coordinate).col, str_to_coordinate(string_coordinate).row);
}