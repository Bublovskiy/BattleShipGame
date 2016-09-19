//
//  Left_Placer.h
//  BattleShipGame
//
//  Created by Maxim Bublowskiy on 2016-09-05.
//  Copyright © 2016 Maxim Bublovskiy. All rights reserved.
//

#ifndef Left_Placer_h
#define Left_Placer_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Global_Data.h"


//returns:
//true  - placement succeded
//false - placement not succeded
bool place_left(int size, int shipNumber, int i, int j);

#endif /* Left_Placer_h */
