//  Start_Game
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-08-29.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "Matrix_Printer.h"
#include "Ships_Positioning.h"
#include "Game_Cycle.h"

// Number and sizes of the ships:
// Size 1 - 4 pieces
// Size 2 - 3 pieces
// Size 3 - 2 pieces
// Size 4 - 1 pieces

//the entry point of the programm
int main(void)
{
    
    //seed random number generator once for the programm life-cycle
    srand((unsigned int)time(NULL));
    
    //place the fleet
    placeShip(4,1);
    
    placeShip(3,1);
    placeShip(3,2);
    
    placeShip(2,1);
    placeShip(2,2);
    placeShip(2,3);
    
    placeShip(1,1);
    placeShip(1,2);
    placeShip(1,3);
    placeShip(1,4);
    
    //print out the matrix
    printMatrix(1);
    
    //start the game shooting
    startTheGame();
    
}//end main