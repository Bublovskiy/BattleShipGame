//
//  Ships_Positioning.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-08-29.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Ships_Positioning.h"

enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} orientation;

enum Plane {
    HORIZONTAL,
    VERTICAL,
    NONE
} plane;

//place ships randomely in the Matix
void placeShip(int size, int shipNumber) {
    
    //get a random empty cell
    unsigned int rndCell = randomCell();
    
    //extract coordinates (i,j)
    int i = (rndCell - rndCell % 10)/10;
    int j = rndCell % 10;
    
    //set the key of successful placement as FALSE
    bool endSuccessfully = false;
   
    //NONE option - will start the process over in order to avoid too similar posotioning of each ship
    switch (plane = rand() % 3) {
        
        case HORIZONTAL:
            
            orientation = (battelFieldMatrixXY-1)-j >= size-1 ? RIGHT : LEFT;
            
            switch (orientation) {
                    
                case RIGHT:
                    
                    endSuccessfully = place_right(size, shipNumber,i,j);
                    if (endSuccessfully == true) {
                        break;
                    }
                    
                case LEFT:
                    
                    endSuccessfully = place_left(size, shipNumber,i,j);
                    break;
                
                default:
                    //not suppoused to be ever shown unless an internal error
                    printf("\n WARNING! SYSTTEM ERROR HAS OCCURRED!\n");
                    break;
            }
            
            
            if (endSuccessfully == true)
            {
                break;
            }
            
        case VERTICAL:
            
            orientation = (battelFieldMatrixXY-1)-i >= size-1 ? DOWN : UP;
        
            switch (orientation) {
                case DOWN:
                
                    endSuccessfully = place_down(size, shipNumber,i,j);
                    if (endSuccessfully == true) {
                        break;
                    }
                    
                case UP:
                    
                    endSuccessfully = place_up(size, shipNumber,i,j);
                    break;
                    
                default:
                    //not suppoused to be ever shown unless an internal error
                    printf("\n WARNING! SYSTTEM ERROR HAS OCCURRED!\n");
                    break;
            }
            
            
            if (endSuccessfully == true) {
                break;
            }

        //start the whole process again
        case NONE:
            placeShip(size, shipNumber);
    }
}