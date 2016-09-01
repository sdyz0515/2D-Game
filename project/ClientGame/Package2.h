//
//  Package2.h
//  ClientGame
//
//  Created by liuxun on 15/3/4.
//
//

#include "stdafx.h"

#ifndef __ClientGame__Package2__
#define __ClientGame__Package2__

class Package2: public PhysicsActor{
    
public:
    
    Package2(Vector2 position);
    
    virtual void Update(float dt);
    
};

#endif /* defined(__ClientGame__Package2__) */
