//
//  Package1.cpp
//  ClientGame
//
//  Created by liuxun on 15/3/4.
//
//

#include "Package1.h"


Package1::Package1(Vector2 position){
    
    SetSprite("./Resources/Images/package1.png");
    SetName("Package1");
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

void Package1::Update(float dt){
    
    PhysicsActor::Update(dt);
    
    if (GetPosition().Y < theCamera.GetWorldMinVertex().Y)
    {
        Destroy();
    }
}
