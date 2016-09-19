//
//  Down_Placer.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Down_Placer.h"

bool place_down(int size, int shipNumber, int i, int j) {

    //control sum to check empty cells
    unsigned int checkSumForShip = 0;
    unsigned int checkSumForSurraundings = 0;
    
    //to check space around a ship
    int lowerI, leftJ, rightJ;
    
    //check if we have empty cells into that diarection
        for (int r = i+1; r<=i+size-1;r++) {
        if (battleFieldMatrix[r][i] == 0) checkSumForShip++;
    }
    
    //if we have empty cells
    if (checkSumForShip == size-1) {
        
        //start checking surraunding area
        lowerI = (i+size) > battelFieldMatrixXY-1 ? battelFieldMatrixXY-1 : i+size;
        leftJ = j == 0 ? 0: j-1;
        rightJ = j == battelFieldMatrixXY-1 ? battelFieldMatrixXY-1: j+1;
        
        for (int tempI = i+2; tempI<=lowerI;tempI++) {
            checkSumForSurraundings +=battleFieldMatrix[tempI][leftJ] + battleFieldMatrix[tempI][rightJ];
        }
        checkSumForSurraundings+=battleFieldMatrix[lowerI][j];
        
        
        //if checkSumForSurraundings stays 0 it means everything around is empty
        //place a ship
        if (checkSumForSurraundings == 0) {
            
            for (int tempI = i;tempI<i+size;tempI++) {
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
