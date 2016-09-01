//
//  Package1.h
//  ClientGame
//
//  Created by liuxun on 15/3/4.
//
//

#include "stdafx.h"

#ifndef __ClientGame__Package1__
#define __ClientGame__Package1__

class Package1: public PhysicsActor{
    
public:
    
    Package1(Vector2 position);
    
    virtual void Update(float dt);
    
};

#endif /* defined(__ClientGame__Package1__) */
