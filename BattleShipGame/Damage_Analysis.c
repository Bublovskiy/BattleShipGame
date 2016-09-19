//
//  Demage_Analysis.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-01.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Damage_Analysis.h"

unsigned int shipHit;

void hitCheck(unsigned int i, unsigned int j) {
    
        //read a number and size of a hit ship
        switch (findShip(i,j, &shipHit)) {
            case MISS:
                printf("\n");
                printf("============= MISSS! ==============\n\n");
                break;
            case PARTIAL_HIT:
                printf("\n");
                printf("======== YOU GOT A PIECE! =========\n\n");
                break;
            case TOTAL_HIT:
                printf("\n");
                printf("======== TOTAL ANNIHILATION! ======\n");
                printf("===== DESTROYED SHIP'S SIZE: %d ====\n\n", (shipHit-shipHit%10)/10);
                break;
            case VICTORY:
                printf("\n");
                printf("======== ABSOLUTE VICTORY! ========\n\n");
                printMatrix(SHIPS_INVISIBLE);
                //exit the programm
                exit(0);
                break;
            case ANALYS_ERROR:
                printf("\n");
                printf("========== SYSTEM MESSAGE! ========\n");
                printf("Could not analyze the data. Please try again! \n\n");
                break;
        }
   
    printMatrix(SHIPS_INVISIBLE);
}