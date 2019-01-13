/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 12, 2019
** Description: Header file for Ant class
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum Direction {NORTH, EAST, SOUTH, WEST};
enum TileColor {WHITEANT, BLACKANT};

class Ant
{   private:
        char **gameBoard;  //a dynamically allocated 2D array of char that represents the board
        Direction antDirection;  //tracks direction ant is facing
        TileColor antTile;  //tracks color of tile
        int antRow;  //ant's current row location
        int antCol;  //ant's current column location
        int numMoves;  //counts the number of moves remaining to be made
        int boardRows;  //number of rows. Adds 2 to the user input number because of border.
        int boardCols;  //number of columns. Adds 2 to the user input number because of border.
        void boundsCheck(int antRowIn, int antColIn);  //checks if ant is inside bounds during move
        void tileColorCheck(int antRowIn, int antColIn); //checks tile color of moved spot, updating TileColor as necessary

    public:
        Ant(int rows, int cols, int startRow, int startCol, int numMoves);  //default constructor that creates array and places ant at user specified location
        ~Ant();  //destructor that frees board memory
        void antMove();
        void printBoard();
        
};
#endif //Ant