//
//  EnemyBullet.h
//  ClientGame
//
//  Created by liuxun on 15/3/3.
//
//

#include "stdafx.h"
#include "Enemy2.h"

#ifndef __ClientGame__EnemyBullet__
#define __ClientGame__EnemyBullet__

class EnemyBullet : public PhysicsActor {
public:
    EnemyBullet();
    EnemyBullet(Enemy* enemy);
    
    virtual void Update(float dt);
    
};

#endif /* defined(__ClientGame__EnemyBullet__) */
