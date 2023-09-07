#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coordinate.h"
Coordinate newCoordinate(int col, int row) // constructor
{
    // Coordinate temp;
    // temp.row = row;
    // temp.col = col;
    // return temp;
    return (Coordinate) {.col=col, .row=row}; // 
}

// coordinate_to_str
// takes a coordinate and a string. Sets the string to the equivalent coordinate value. Example: "A1" == {0,0}
// Columns: 'A' = 0, 'B' = 1, 'C' = 2
// Rows:    '1' = 0, '2' = 1, '3' = 2
void coordinate_to_str(Coordinate coordinate, char* str)
{
    str[0] = coordinate.col + 'A';
    str[1] = coordinate.row + '1';
}

// str_to_coordinate
// takes a string and converts to a coordinate. Returns a Coordinate.
// Assumes string is valid (length 2, between A-C and 1-3)
Coordinate str_to_coordinate(char* str)
{
    return (Coordinate) {.col=str[0] - 'A', .row=str[1] - '1'};
}