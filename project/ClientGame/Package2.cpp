//
//  Package2.cpp
//  ClientGame
//
//  Created by liuxun on 15/3/4.
//
//

#include "Package2.h"


Package2::Package2(Vector2 position){
    
    SetSprite("./Resources/Images/package2.png");
    SetName("Package2");
    Tag("package");
    
    
    SetPosition(position);
    SetSize(0.8f);
    SetDensity(1.0f);
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    SetFixedRotation(true);
    SetIsSensor(true);
    InitPhysics();
    ApplyLinearImpulse(Vector2(0, -3.0f), Vector2::Zero);
    theWorld.Add(this);    
}

void Package2::Update(float dt){
    
    PhysicsActor::Update(dt);
    
    if (GetPosition().Y < theCamera.GetWorldMinVertex().Y)
    {
        Destroy();
    }
}
