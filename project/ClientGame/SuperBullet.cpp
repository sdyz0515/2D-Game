/*
 SuperBullet.cpp
 
 Author: xun liu
 
 
 */

#include "SuperBullet.h"


SuperBullet::SuperBullet(Player* player)
{
    Vector2 playerVector = MathUtil::VectorFromAngle(player->GetRotation() + 90.0f);
    Vector2 pos = player->GetPosition();
    pos += playerVector * (player->GetSize().Y * 0.5f);
    SetPosition(pos);
    
    SetSprite("./Resources/Images/superBullet.png");
    SetSize(1.0f);
    SetDensity(1.0f);
    SetIsSensor(true);
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    InitPhysics();
    GetBody()->SetBullet(true);
    ApplyLinearImpulse(Vector2(0.0f, 10.0f), Vector2::Zero);
    
    Tag("superBullet");
    theWorld.Add(this);
}
