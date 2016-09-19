//
//  UP_Placer.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "UP_Placer.h"


bool place_up(int size, int shipNumber, int i, int j) {

    
    //control sum to check empty cells
    unsigned int checkSumForShip = 0;
    unsigned int checkSumForSurraundings = 0;
    
    //to check space around a ship
    int upperI, leftJ, rightJ;
    
    
    //check if we have empty cells into that direction
    for (int r = i-1; (r>=i-(size-1)) && (r >0) ;r--) {
        if (battleFieldMatrix[i][r] == 0) checkSumForShip++;
    }
    
    //if we have empty cells
    if (checkSumForShip == size-1) {
        
        //start checking surraunding area
        upperI = (i-size) < 0 ? 0 : i-size;
        leftJ = j == 0 ? 0: j-1;
        rightJ = j == battelFieldMatrixXY-1 ? battelFieldMatrixXY-1: j+1;
        
        
        for (int tempI = i-2; tempI>=upperI;tempI--) {
            checkSumForSurraundings +=battleFieldMatrix[tempI][leftJ] + battleFieldMatrix[tempI][rightJ];
        }
        checkSumForSurraundings+=battleFieldMatrix[upperI][j];
        
        
        //if checkSumForSurraundings stays 0 it means everything around is empty
        //place a ship
        if (checkSumForSurraundings == 0) {
            
            for (int tempI = i;tempI>i-size;tempI--) {
                battleFieldMatrix[tempI][j] = size*10+shipNumber;
            }
            
            return true;
        }
        else {
            return false;
        }
        
    }

    //not suppoused to be reached, unless a system error occurred
    return -1;
}