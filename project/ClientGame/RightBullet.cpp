//
//  RightBullet.cpp
//  ClientGame
//
//  Created by liuxun on 15/3/4.
//
//

#include "RightBullet.h"
#include "Player.h"


RightBullet::RightBullet(Player* player)
{
    
    Vector2 playerVector = MathUtil::VectorFromAngle(player->GetRotation() + 90.0f);
    Vector2 pos = player->GetPosition();
    pos += playerVector * (player->GetSize().Y * 0.5f);
    SetPosition(pos);
    
    SetSprite("./Resources/Images/bullet.png");
    SetSize(0.3f);
    SetDensity(1.0f);
    SetIsSensor(true);
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    InitPhysics();
    GetBody()->SetBullet(true);
    ApplyLinearImpulse(Vector2(1.0f, 1.0f), Vector2::Zero);
    
    Tag("bullet");
    theWorld.Add(this);
    
}