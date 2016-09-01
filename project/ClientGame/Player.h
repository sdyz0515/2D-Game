//
//  Player.h
//
//  Created by Yajun Shi
//
//  The user-controlled actor, has abilities of moving and shooting.
//

#include "stdafx.h"

#ifndef __ClientGame__Player__
#define __ClientGame__Player__

class Player : public PhysicsActor {
public:
    Player();
    
    virtual void Update(float dt);
    
    virtual void ReceiveMessage(Message *message);
    
    void Explode();
    void Reset();
    
private:

    float _bulletCooldown;
    int _bulletMode;
    float _bulletduration;
    
    AngelSampleHandle _bulletSound;
    AngelSampleHandle _explodeSound;

};


#endif /* defined(__ClientGame__Player__) */
