/*
 bullet.cpp
 
 Author: xun liu
 
 
 */

#include "Bullet.h"

Bullet::Bullet(){
}

Bullet::Bullet(Player* player)
{
    
    Vector2 playerVector = MathUtil::VectorFromAngle(player->GetRotation() + 90.0f);
    Vector2 pos = player->GetPosition();
    pos += playerVector * (player->GetSize().Y * 0.5f);
    SetPosition(pos);    
    
    SetSize(0.3f);
    SetDensity(1.0f);
    SetIsSensor(true);
    SetSprite("./Resources/Images/bullet.png");
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    InitPhysics();
    GetBody()->SetBullet(true);
    ApplyLinearImpulse(Vector2(0.0f, 1.0f), Vector2::Zero);
    
    Tag("bullet");
    theWorld.Add(this);
}


void Bullet::Update(float dt)
{
    PhysicsActor::Update(dt);
    
    if (GetPosition().Y > theCamera.GetWorldMaxVertex().Y)
    {
        Destroy();
    }
}

