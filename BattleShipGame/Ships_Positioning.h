//
//  Ships_Positioning.h
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-08-29.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#ifndef Ship_Positioning_h

#define Ship_Positioning_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Global_Data.h"
#include "Random_Cell_Chooser.h"
#include "LEFT_Placer.h"
#include "RIGHT_Placer.h"
#include "UP_Placer.h"
#include "DOWN_Placer.h"

//place ships randomely in the matrix
void placeShip(int size, int shipNumber);

#endif /* Ship_Positioning_h */
