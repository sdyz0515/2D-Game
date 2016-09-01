//
//  Enemy3.h
//
//  Created by Xun Liu
//

#include "stdafx.h"
#include "Enemy.h"

#ifndef __ClientGame__Enemy3__
#define __ClientGame__Enemy3__

class Enemy3 : public Enemy {
public:
    Enemy3(Vector2 position);
    virtual void Update(float dt);
    virtual void ReceiveMessage(Message* message);
    
private:
    AngelSampleHandle _enemyExplodes;
    float _bullet_cd;
    int _HP;
    
};

#endif /* defined(__ClientGame__Enemy3__) */
