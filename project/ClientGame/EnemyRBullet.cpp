//
//  EnemyRBullet.cpp
//
//  Created by Yajun Shi
//

#include "EnemyRBullet.h"
#include "Player.h"


EnemyRBullet::EnemyRBullet(Enemy* enemy){
    
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
    ApplyLinearImpulse(Vector2(1.0f, -1.0f), Vector2::Zero);
    
    Tag("enemyBullet");
    
    theWorld.Add(this);
    
}