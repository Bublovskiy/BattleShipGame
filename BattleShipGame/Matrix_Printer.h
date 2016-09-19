//
//  Matrix_Printer.h
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-08-29.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#ifndef Matrix_Printer_h
#define Matrix_Printer_h

#include <stdio.h>
#include "Global_Data.h"

typedef enum {
    SHIPS_VISIBLE,
    SHIPS_INVISIBLE
} print_mode;

//function to print main battle ship matrix
//mode 0 - with the ships shown
//     1 - with the ships coded
void printMatrix(print_mode mode);

#endif /* Matrix_Printer_h */
