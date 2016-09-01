//
//  Enemy.h
//
//  Created by Yajun Shi
//
//  An enemy actor, moving straight down from the upper edge of the game window.
//  Exploded if hit by bullet, game over if hit by player.
//

#include "stdafx.h"

#ifndef __ClientGame__Enemy__
#define __ClientGame__Enemy__

class Enemy : public PhysicsActor {
public:
    Enemy();
    
    Enemy(Vector2 position);
    
    virtual void Update(float dt);
    
	virtual void ReceiveMessage(Message* message);
    
    void Explode();
    
private:
    
    AngelSampleHandle _enemyExplode; // 爆炸音效
    
};

#endif /* defined(__ClientGame__Enemy__) */
