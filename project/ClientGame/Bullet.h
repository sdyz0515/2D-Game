/*
 bullet.h
 
 Author: xun liu
 
 */

#include "stdafx.h"
#include "Player.h"

#ifndef __ClientGame__Bullet__
#define __ClientGame__Bullet__

class Bullet : public PhysicsActor {
public:
    Bullet();
    
    Bullet(Player* player);
    
    virtual void Update(float dt);

};

#endif /* defined(__ClientGame__Bullet__) */
