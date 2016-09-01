//
//  EnemyBullet.cpp
//  ClientGame
//
//  Created by liuxun on 15/3/3.
//
//

#include "EnemyBullet.h"
#include "Player.h"
#include "Enemy2.h"

EnemyBullet::EnemyBullet(){
}

EnemyBullet::EnemyBullet(Enemy* enemy)
{
    Vector2 enemyVector = MathUtil::VectorFromAngle(enemy->GetRotation() + 90.0f);
    Vector2 pos = enemy->GetPosition();
    pos -= enemyVector * (enemy->GetSize().Y * 0.5f);
    SetPosition(pos);
    
    SetSize(0.5f);
    SetDensity(1.0f);
    SetIsSensor(true);
    SetSprite("./Resources/Images/enemyBullet.png");
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    InitPhysics();
    GetBody()->SetBullet(true);
    ApplyLinearImpulse(Vector2(0.0f, -1.0f), Vector2::Zero);
    
    Tag("enemyBullet");
    theWorld.Add(this);
}


void EnemyBullet::Update(float dt)
{
    PhysicsActor::Update(dt);
    
    if (GetPosition().Y < theCamera.GetWorldMinVertex().Y)
    {
        Destroy();
    }
}
