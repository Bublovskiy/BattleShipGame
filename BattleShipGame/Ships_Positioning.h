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
#include "Left_Placer.h"
#include "Right_Placer.h"
#include "Up_Placer.h"
#include "Down_Placer.h"

//place ships randomely in the matrix
void placeShip(int size, int shipNumber);

#endif /* Ship_Positioning_h */
