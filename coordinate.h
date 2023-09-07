typedef struct tagCoordinate // struct declaration
{
    // member variables
    int col;
    int row;
} Coordinate; // typedef name

Coordinate newCoordinate(int col, int row); // prototype constructor
void coordinate_to_str(Coordinate coordinate, char* str); // prototype
Coordinate str_to_coordinate(char* str); //prototype