//
//  Ship_Locator.h
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#ifndef Ship_Locator_h
#define Ship_Locator_h

#include <stdio.h>
#include <stdlib.h>
#include "Global_Data.h"
#include "Matrix_Printer.h"

typedef enum type_of_damage {
    MISS,
    PARTIAL_HIT,
    TOTAL_HIT,
    VICTORY,
    ANALYS_ERROR
} damage;

damage findShip(unsigned int i, unsigned int j, unsigned int *shipHit);

#endif /* Ship_Locator_h */
