//
//  Ship_Locator.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Ship_Locator.h"


damage findShip(unsigned int i, unsigned int j, unsigned int *shipHit) {
    
    //representation of the sum of all hit cells
    static unsigned int controlSum = 77*20;
    
    //if a number is not "empty sapce (0)" or previously "hit cell (77)"
    if (battleFieldMatrix[i][j] != 0 && battleFieldMatrix[i][j] != 77) {
        
        //store size and number of a hit ship
        *shipHit = battleFieldMatrix[i][j];
        
        //mark that cell as hit by 77
        battleFieldMatrix[i][j] = 77;
        
        //search the control matrix to find a part of a ship
        for (unsigned int i=0;i<20;i++) {
            
            if (allShipsMatrix[i] == *shipHit) {
                
                //mark the part of a ship as hit
                allShipsMatrix[i] = 77;
                
                controlSum-=77;
                
                //check the control sum and return 2 if all ships have been destroyed. The sum = 0;
                if (controlSum == 0) {
                    return VICTORY;
                }
                
                if (i == 19) {
                    return TOTAL_HIT;
                }
                else {
                    return allShipsMatrix[i+1] == *shipHit  ?  PARTIAL_HIT : TOTAL_HIT;
                }
            }
        }
    }
    else {
        return MISS;
    }
    
    //is not suppoused to be ever reached, unless something went wrong
    return ANALYS_ERROR;
    
}
