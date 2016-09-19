//
//  Matrix_Printer.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-08-29.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//
#include "Matrix_Printer.h"


//function to print main battle ship matrix
void printMatrix(print_mode mode) {

    //the header of the matrix
    printf("     0  1  2  3  4  5  6  7  8  9 \n");
    printf("   -------------------------------\n");
    
    for (int i = 0; i<battelFieldMatrixXY;i++) {
        
        //the start of each line with art and number
        printf("%d | ",i);
        
        for (int j = 0; j<battelFieldMatrixXY;j++) {
            
            switch (battleFieldMatrix[i][j]) {
                case 0:
                    printf(" . ");
                    break;
                
                case 77:
                    printf(" × ");
                    break;
                
                default:
                    
                    if (mode == SHIPS_VISIBLE) {
                        printf(" © ");
                    }
                    else {
                        printf(" . ");
                    }
                    break;
            }
        }
    
        //empty line with art after each line
        printf("|\n");
    }
    
    //the footer of the matrix
     printf("   -------------------------------\n");
}