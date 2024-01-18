#include "gameOfLife.h"

void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

void initCells(Cell* board[][10], int boardSize)
{

}

void readBoard(Cell* board[][10], int boardSize, string fileName) 
{

}

void printCells(Cell* board[][10], int boardSize)
{

}

void findNumNeighbors(Cell* board[][10], int boardSize) 
{

}

bool updateCellState(Cell* board[][10], int boardSize) 
{
    return false;
}