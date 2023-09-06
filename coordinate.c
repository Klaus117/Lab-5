#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coordinate.h"
struct Coordinate Coordinate(int row, int col) // constructor
{
    struct Coordinate temp;
    temp.row = row;
    temp.col = col;
    return temp;
}