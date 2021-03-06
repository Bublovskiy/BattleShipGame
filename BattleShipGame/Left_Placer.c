//
//  Left_Placer.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Left_Placer.h"


bool place_left(int size, int shipNumber, int i, int j) {

    //control sum to check empty cells
    unsigned int checkSumForShip = 0;
    unsigned int checkSumForSurraundings = 0;
    
    //to check space around a ship
    int upperI, lowerI, leftJ;
    

    //check if we have empty cells into that diarection
    for (int r = j-1; (r>=j-(size-1)) && (r >0) ;r--) {
        
        if (battleFieldMatrix[i][r] == 0) {
            checkSumForShip++;
        }
        
     }

    //we have empty cells
    if (checkSumForShip == size-1) {
        
        //start checking surraunding area
        upperI = i == 0 ? 0 : i-1;
        lowerI = i == battelFieldMatrixXY-1 ? battelFieldMatrixXY-1 : i+1;
        leftJ = (j-size) < 0 ? 0 : j-size;
        
        for (int tempJ = j-2; tempJ>=leftJ;tempJ--) {
            checkSumForSurraundings +=battleFieldMatrix[upperI][tempJ] + battleFieldMatrix[lowerI][tempJ];
        }
        
        checkSumForSurraundings+=battleFieldMatrix[i][leftJ];
        
        
        //if checkSumForSurraundings stays 0 it means everything around is empty
        //place a ship
        if (checkSumForSurraundings == 0) {
            
            for (int tempJ = j;tempJ>j-size;tempJ--) {
                battleFieldMatrix[i][tempJ] = size*10+shipNumber;
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
