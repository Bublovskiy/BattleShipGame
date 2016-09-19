//
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-08-29.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Global_Data.h"

//Width and height of the Matrix
unsigned int battelFieldMatrixXY = 10;

//init main matrix with all element = 0;
unsigned int battleFieldMatrix[10][10] = {};

//matrix with codes of all ships
//the first digit is the size of a ship
//the second digit is the ordinal number of a ship
//22 - two cell size ship number 2

// Number and sizes of the ships:
// Size 1 - 4 pieces
// Size 2 - 3 pieces
// Size 3 - 2 pieces
// Size 4 - 1 pieces

unsigned int allShipsMatrix[20] = {11,
                                   12,
                                   13,
                                   14,
                                   21,21,
                                   22,22,
                                   23,23,
                                   31,31,31,
                                   32,32,32,
                                   41,41,41,41};