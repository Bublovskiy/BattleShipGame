//
//  Game_Cycle.c
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-01.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#include "Game_Cycle.h"

//start the game loop
void startTheGame() {

    //key to finish the game
    bool shallExitGame = false;
    
    //user shot coordinates
    unsigned int userI, userJ, oneNumber;
    unsigned int n;
   
    printf("\n");
    printf("====== LET'S START SHOOTING! ======\n");
    printf("=(111 - Exit, 999 - See the ships)=\n");
    printf("===================================\n\n");
    
    while (shallExitGame == false) {

        //set input validation
        do {
            
        printf("Line and Column as one number: ");
        n = scanf("%d",&oneNumber);
            
            if (n !=1) {
                
                //sets the file position of the stream to the very begining
                //to prevent overflow and infinite looping if the user enters numbers with anything else
                fseek(stdin,0,SEEK_END);
                
                //print a prompt
                printf("Sorry! Did not capture your enter! Please trye again!\n");
            }
            
        } while (n != 1);
      
        //check if the user wants to finish the game
        if (oneNumber == 111) {
            shallExitGame = true;
            continue;
        }
        else if (oneNumber == 999) {
            printf("\n");
            
            //print the matrix with all ships visible
            printMatrix(SHIPS_VISIBLE);
            
            printf("\n\n");
            continue;
        }
        
        //extract the user's coordinates
        userI = (oneNumber - oneNumber % 10)/10;
        userJ = oneNumber % 10;
        
        //check if we hit, missed or completely win
        hitCheck(userI,userJ);
    
    }
}