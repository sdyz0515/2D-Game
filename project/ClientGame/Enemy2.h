//
//  Enemy2.h
//
//  Created by Xun Liu
//

#include "stdafx.h"
#include "Enemy.h"

#ifndef __ClientGame__Enemy2__
#define __ClientGame__Enemy2__

class Enemy2 : public Enemy {
public:
    Enemy2(Vector2 position);
    virtual void Update(float dt);
    
private:
    float _bullet_cd;
    AngelSampleHandle _enemyExplode;
    
};

#endif /* defined(__ClientGame__Enemy2__) */
