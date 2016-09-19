//
//  Random_Cell_Chooser.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Random_Cell_Chooser.h"


//pick a random empty cell with empty surraunding area (empty deattached cell)
int randomCell() {
    unsigned int i;
    unsigned int j;
    int upperI, lowerI, leftJ, rightJ;
    unsigned int random;
    unsigned int checkAroundSum;
    
   
    while (1) {
        
        random = rand() % (battelFieldMatrixXY*battelFieldMatrixXY);
        i = (random - random % 10)/10;
        j = random % 10;
        checkAroundSum = 0;
        
        if (battleFieldMatrix[i][j] == 0) {
            
            upperI = i == 0 ? 0 : i-1;
            lowerI = i == battelFieldMatrixXY-1 ? battelFieldMatrixXY-1 : i+1;
            leftJ = j == 0 ? 0 : j-1;
            rightJ = j == battelFieldMatrixXY-1 ? battelFieldMatrixXY-1 : j+1;
            
            checkAroundSum = battleFieldMatrix[upperI][j] +
            battleFieldMatrix[lowerI][j] +
            battleFieldMatrix[i][leftJ] +
            battleFieldMatrix[i][rightJ] +
            battleFieldMatrix[upperI][leftJ] +
            battleFieldMatrix[upperI][rightJ] +
            battleFieldMatrix[lowerI][leftJ] +
            battleFieldMatrix[lowerI][rightJ];
            
            if (checkAroundSum == 0) {
                break;
            }
        }
    }
    
    //return a suitable cell number
    return i*10+j;
}
