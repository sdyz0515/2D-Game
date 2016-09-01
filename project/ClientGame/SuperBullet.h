//
//  SuperBullet.cpp
//  ClientGame
//
//  Created by liuxun on 15/3/3.
//
//

#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

#ifndef __ClientGame__SuperBullet__
#define __ClientGame__SuperBullet__

class SuperBullet : public Bullet {
public:
    
    SuperBullet(Player* player);
};

#endif /* defined(__ClientGame__SuperBullet__) */
